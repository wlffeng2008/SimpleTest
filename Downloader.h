#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = nullptr);
    ~Downloader();

    // 开始下载
    void startDownload(const QString &url, const QString &savePath);
    // 暂停
    void pause();
    // 继续
    void resume();
    // 取消
    void cancel();

signals:
    // 下载进度 0~100
    void progressChanged(int percent);
    // 下载完成
    void finished(bool success, const QString &msg);
    // 出错
    void errorOccurred(const QString &errMsg);

private slots:
    void onReadyRead();
    void onReplyFinished();
    void downloadProgress(qint64 recv, qint64 total);

private:
    QNetworkAccessManager *m_manager;
    QNetworkReply *m_reply;
    QFile m_file;
    QString m_url;
    qint64 m_downloadedSize; // 已下载字节
    bool m_isPaused;
    bool m_isCanceled;
};

#endif // DOWNLOADER_H
