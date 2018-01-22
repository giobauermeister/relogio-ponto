#include "backend.h"

BackEnd::BackEnd(QObject *parent) : QObject(parent)
{
    qDebug() << "created object backend in QML";
    beepErr = "/home/pi/beepErr";
    beepOK = "/home/pi/beepOK";
    myProcess = new QProcess(this);
    //myProcess->start(beepOK);

    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(zeroTag()));

    openRfidPort();
    openDB("/home/pi/employee-manager-app/backend-app-server/filipeflop.db");

}

void BackEnd::openRfidPort()
{
    bool rfid_is_available = false;
    QString rfid_port_name;
    rfid = new QSerialPort(this);

    /*
     * Code for testing all available Serial ports
     *
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Port Name: " << serialPortInfo.portName();
        qDebug() << "Description: " << serialPortInfo.description();
        qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier();
        //qDebug() << "Vendor ID: " << QString().number(serialPortInfo.vendorIdentifier(), 16).toInt();
        qDebug() << "Vendor ID: " << QByteArray().number(serialPortInfo.vendorIdentifier(), 16);
        qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier();
        //qDebug() << "Product ID: " << QString().number(serialPortInfo.productIdentifier(), 16).toInt();
        qDebug() << "Product ID: " << QByteArray().number(serialPortInfo.productIdentifier(), 16);
        qDebug() << " ";
    }
    */


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        //  check if the serialport has both a product identifier and a vendor identifier
//        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
//            if(QString().number(serialPortInfo.vendorIdentifier(), 16).toInt() == ftdi_vendor_id
//                && QString().number(serialPortInfo.productIdentifier(), 16).toInt() == ftdi_product_id)
//            {
//                rfid_is_available = true;
//                rfid_port_name = serialPortInfo.portName();

//                qDebug() << "Port Name: " << serialPortInfo.portName();
//                qDebug() << "Description: " << serialPortInfo.description();
//                qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier();
//                qDebug() << "Vendor ID: " << QString().number(serialPortInfo.vendorIdentifier(), 16).toInt();
//                qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier();
//                qDebug() << "Product ID: " << QString().number(serialPortInfo.productIdentifier(), 16).toInt();
//            }
//        }

        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            if(QChar(serialPortInfo.vendorIdentifier()) == cp2102_vendor_id
                && QChar(serialPortInfo.productIdentifier()) == cp2102_product_id)
            {
                rfid_is_available = true;
                rfid_port_name = serialPortInfo.portName();

                qDebug() << "Port Name: " << serialPortInfo.portName();
                qDebug() << "Description: " << serialPortInfo.description();
                qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier();
                qDebug() << "Vendor ID: " << QByteArray().number(serialPortInfo.vendorIdentifier(), 16);
                qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier();
                qDebug() << "Product ID: " << QByteArray().number(serialPortInfo.productIdentifier(), 16);
            }
        }
    }
    if(rfid_is_available)
    {
        qDebug() << "Found RFID on port: " << rfid_port_name;
        rfid->setPortName(rfid_port_name);
        rfid->open(QSerialPort::ReadOnly);
        rfid->setBaudRate(QSerialPort::Baud9600);
        rfid->setDataBits(QSerialPort::Data8);
        rfid->setFlowControl(QSerialPort::NoFlowControl);
        rfid->setParity(QSerialPort::NoParity);
        rfid->setStopBits(QSerialPort::OneStop);
        rfid->setReadBufferSize(14);
        QObject::connect(rfid, SIGNAL(readyRead()), this, SLOT(readTag()));
    }
    else
    {
        qDebug() << "INFO: can't find USB UART chip, please make sure it is connected to USB port";
    }
}

void BackEnd::openDB(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
      qDebug() << "Error: connection with database fail";
    }
    else
    {
      qDebug() << "Database: connection ok";
    }
}

void BackEnd::searchTagID(const QString &tagID)
{
    QString photoPath;
    //qDebug() << "Start Search TagID";
    QSqlQuery query;
    query.prepare("SELECT EmployeeName FROM Employees WHERE TagID = (:TagID)");
    query.bindValue(":TagID", tagID);
    if (query.exec())
    {
        if (query.next())
        {
            qDebug() << "tag number exists";
            int idName = query.record().indexOf("EmployeeName");
            QString name = query.value(idName).toString();
            qDebug() << "===" << name;
            photoPath = "file:///home/pi/employee-manager-app/vuejs-app-server/dist/static/userphotos/" + tagID + ".png";
            //qDebug() << photoPath;
            //qDebug() << "now is the time to setIdText";
            //setIdtext(ID);
            myProcess->start(beepOK);
            setEmployeePhoto(" ");
            setEmployeePhoto(photoPath);
            setEmployeeName(name);
            setEmployeeID(tagID);
            searchTimesheet(tagID, name);
        }
        else {
            qDebug() << "tag NOT FOUND in database";
            setTimeIndex(4);
            myProcess->start(beepErr);
            setEmployeePhoto("resources/unknown-user.png");
            setEmployeeName("User Not Found");
            setEmployeeID(tagID);
        }
    }
}

void BackEnd::searchTimesheet(const QString &tagID, const QString &name)
{

    //SELECT ClockIn FROM 'Timesheet' Where TagID = '2100C6D3281C' AND date = '23-12-2017';
    //QDateTime date = QDateTime::currentDateTime();
    //qDebug() << date.currentDateTime().toString();

    qDebug() << "saving time to database";
    QDateTime date = QDateTime::currentDateTime();
    qDebug() << date.currentDateTime().toString("dd-MM-yyyy");
    QString dateFormat = date.currentDateTime().toString("dd-MM-yyyy");
    //-- manipulação da data para testes
    //QString dateFormat = "51-12-2017";

    QDateTime time = QDateTime::currentDateTime();
    qDebug() << time.currentDateTime().toString("hh:mm");
    QString timeFormat = time.currentDateTime().toString("hh:mm");
    qDebug() << " ";

    QSqlQuery query;
    query.prepare("SELECT ClockIn, LunchIn, LunchOut, ClockOut FROM Timesheets WHERE TagID = (:TagID) AND Data = (:Data)");
    query.bindValue(":TagID", tagID);
    query.bindValue(":Data", dateFormat);
    if (query.exec())
    {
        qDebug() << "inside QUERY EXEC";
        if(query.next())
        {
            qDebug() << "found data in database";
            query.exec();
            while (query.next())
            {
                for(int i=0;i<4;i++) {
                    if(query.value(i).toString() != "")
                    {
                        qDebug() << query.value(i).toString();
                        if(i == 3) setTimeIndex(3);
                    }
                    else {
                        // ClockIn = 0
                        // LunchIn = 1
                        // LunchOut = 2
                        // ClockOut = 3
                        qDebug() << "NULL";
                        qDebug() << i;
                        saveTimesheet(i,timeFormat,tagID,dateFormat);
                        break;
                    }
                }
            }
        }
        else {
            qDebug() << "no data found";
            addRecordToDB(tagID,name,dateFormat,timeFormat);
        }
//        while (query.next())
//        {
//            for(int i=0;i<4;i++) {
//                if(query.value(i).toString() != "")
//                {
//                    qDebug() << query.value(i).toString();
//                }
//                else {
//                    qDebug() << "NULL";
//                }

//            }
//            QString teste1 = query.value(0).toString();
//            qDebug() << teste1;
//            QString teste2 = query.value(1).toString();
//            qDebug() << teste2;
//            QString teste3 = query.value(2).toString();
//            qDebug() << teste3;
//            QString teste4 = query.value(3).toString();
//            qDebug() << teste4;
        //}
//        if(!query.next()) {
//            qDebug() << "no data found";
//        } else {
//            qDebug() << "found data in database";
//            while (query.next())
//            {
//                QString teste1 = query.value(0).toString();
//                qDebug() << teste1;
//                QString teste2 = query.value(1).toString();
//                qDebug() << teste2;
//                QString teste3 = query.value(2).toString();
//                qDebug() << teste3;
//                QString teste4 = query.value(3).toString();
//                qDebug() << teste4;
//            }
//        }
    } else {
        qDebug() << "ERROR  " << query.lastError();
    }
}

void BackEnd::saveTimesheet(const int& index, const QString& time, const QString& tagID, const QString& data)
{
    //-- query para adicionar novo horario
    //UPDATE Timesheet SET LunchIn = '12:01' WHERE TagID = '2100C6D3281C' AND Data = '23-12-2017';
    QSqlQuery query;

    switch (index) {
//    case 0:
//        query.prepare("UPDATE Timesheets SET ClockIn = (:time) WHERE TagID = (:TagID) AND Data = (:Data)");
//        break;
    case 1:
        query.prepare("UPDATE Timesheets SET LunchIn = (:time) WHERE TagID = (:TagID) AND Data = (:Data)");
        qDebug() << "saving time to LunchIn";
        break;
    case 2:
        query.prepare("UPDATE Timesheets SET LunchOut = (:time) WHERE TagID = (:TagID) AND Data = (:Data)");
        qDebug() << "saving time to LunchOut";
        break;
    case 3:
        query.prepare("UPDATE Timesheets SET ClockOut = (:time) WHERE TagID = (:TagID) AND Data = (:Data)");
        qDebug() << "saving time to ClockOut";
        break;
    }
    query.bindValue(":time", time);
    query.bindValue(":TagID", tagID);
    query.bindValue(":Data", data);
    if(query.exec())
    {
        setTimeIndex(index);
        qDebug() << "success updating time";
    }
    else
    {
        qDebug() << "error updating time  " << query.lastError();
    }

}

void BackEnd::addRecordToDB(const QString &tagID, const QString &name, const QString &data, const QString &time)
{
    //-- add new row to database, this will just happen in the mornig when ClockIn
    //INSERT into Timesheet ('TagID', 'EmployeeName', 'Data', 'ClockIn') Values ('210062672400', 'Adilson Thomsen', '23-12-2017', '8:03');
    QSqlQuery query;
    query.prepare("INSERT into Timesheets ('TagID', 'EmployeeName', 'Data', 'ClockIn') Values ((:tagID), (:name), (:data), (:time))");
    query.bindValue(":tagID", tagID);
    query.bindValue(":name", name);
    query.bindValue(":data", data);
    query.bindValue(":time", time);
    if(query.exec())
    {
         qDebug() << "SUCCESS adding new ClockIn";
         setTimeIndex(0);
    }
    else
    {
        qDebug() << "ERROR adding new ClockIn  " << query.lastError();
    }
}

QString BackEnd::employeePhoto()
{
    return m_employeePhoto;
}

void BackEnd::setEmployeePhoto(const QString &photo)
{
    qDebug() << photo;
//    if (photo == m_employeePhoto)
//        return;
    m_employeePhoto = photo;
    //qDebug() << "emitting signal photo";
    emit employeePhotoChanged(m_employeePhoto);
}

QString BackEnd::employeeName()
{
    return m_employeeName;
}

void BackEnd::setEmployeeName(const QString &name)
{
    qDebug() << name;
//    if (name == m_employeeName)
//        return;
    m_employeeName = name;
    //qDebug() << "emitting signal name";
    emit employeeNameChanged(m_employeeName);
}

QString BackEnd::employeeID()
{
    return m_employeeID;
}

void BackEnd::setEmployeeID(const QString &id)
{
    qDebug() << id;
//    if (id == m_employeeID)
//        return;
    m_employeeID = id;
    //qDebug() << "emitting signal id";
    emit employeeIDChanged(m_employeeID);
}

int BackEnd::timeIndex()
{
    return m_timeIndex;
}

void BackEnd::setTimeIndex(const int &timeindex)
{
    qDebug() << timeindex;
//    if (id == m_employeeID)
//        return;
    m_timeIndex = timeindex;
    //qDebug() << "emitting signal id";
    emit timeIndexChanged(m_timeIndex);
}

bool BackEnd::decodeTag()
{
    //QString oldID;
    serialData += rfid->readAll();
    if(!serialData.contains("\x03"))
        return false;
    ID = QString(serialData).remove("\x02").remove("\x03");
    serialData.clear();
    //rfid->write(QByteArray(" ")); // teste para evitar travamento da porta
    //rfid->flush();
    //rfid->clear(); // outro teste para evitar travamento da porta
    if(oldID == ID)
    {
        //qDebug() << "same ID";
        //qDebug() << ID;
        oldID = ID;
        return false;
    }
    else
    {
        //qDebug() << "different ID";
        //qDebug() << ID;
        oldID = ID;
        return true;
    }
}

void BackEnd::readTag()
{
    if(decodeTag())
    {
        //qDebug() << "inside read tag returned true";
        qDebug() << ID;
        qDebug() << " ";
        //myProcess->start(beepOK);
        searchTagID(ID);
        timer->start(3000);
    }
}

void BackEnd::zeroTag()
{
    //qDebug() << "zero oldID";
    oldID = "";
    setEmployeeID(oldID);
}
