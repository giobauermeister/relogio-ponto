#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QTimer>
#include <QProcess>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDateTime>

class BackEnd : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString employeePhoto READ employeePhoto WRITE setEmployeePhoto NOTIFY employeePhotoChanged)
    Q_PROPERTY(QString employeeName READ employeeName WRITE setEmployeeName NOTIFY employeeNameChanged)
    Q_PROPERTY(QString employeeID READ employeeID WRITE setEmployeeID NOTIFY employeeIDChanged)
    Q_PROPERTY(int timeIndex READ timeIndex WRITE setTimeIndex NOTIFY timeIndexChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);

    //-- funções do RFID
    void openRfidPort();
    QProcess *myProcess;
    QTimer *timer;

    //-- funções do Banco de Dados
    void openDB(const QString& path);
    void searchTagID(const QString& tagID);
    void searchTimesheet(const QString& tagID, const QString& name);
    void saveTimesheet(const int& index, const QString& time, const QString& tagID, const QString& data);
    void addRecordToDB(const QString& tagID, const QString& name, const QString& data, const QString& time);

    //--- Declaração dasfunções de Q_PROPERTY do objeto em QML
    QString employeePhoto();
    void setEmployeePhoto(const QString &photo);

    QString employeeName();
    void setEmployeeName(const QString &name);

    QString employeeID();
    void setEmployeeID(const QString &id);

    int timeIndex();
    void setTimeIndex(const int &timeIndex);

//    bool zeroTag();
//    void setEmployeeID(const QString &id);

    //-- variaveis para QML
    QString m_idtext;
    QString m_employeePhoto;
    QString m_employeeName;
    QString m_employeeID;
    int m_timeIndex;

private:
    QSerialPort *rfid;
    QByteArray serialData;
    QByteArray serialBuffer;
    static const quint16 ftdi_vendor_id = 403;
    static const quint16 ftdi_product_id = 6001;
    static const quint16 cp2102_vendor_id = 4292;
    static const quint16 cp2102_product_id = 60000;
    QString oldID;
    QString ID;
    QString beepOK;
    QString beepErr;


    //-- variáveis privadas banco de dados
    QSqlDatabase m_db;


signals:

    //-- sinais do QML
    void idtextChanged(const QString &id);
    void employeePhotoChanged(const QString &photo);
    void employeeNameChanged(const QString &name);
    void employeeIDChanged(const QString &id);
    void timeIndexChanged(const int &timeIndex);


public slots:
    bool decodeTag();
    void readTag();
    void zeroTag();

};

#endif // BACKEND_H
