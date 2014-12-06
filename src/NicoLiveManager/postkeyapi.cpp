#include "nicolivemanager.h"
#include "../mainwindow.h"

void NicoLiveManager::getPostKeyAPI(const QString& thread, int block_no)
{
  QNetworkAccessManager* mManager = new QNetworkAccessManager(this);
  // make request
  QNetworkRequest rq;
  QVariant postData = makePostData(mwin->settings.getUserSession());
  rq.setHeader(QNetworkRequest::CookieHeader, postData);
  rq.setUrl(QUrl(QString("http://live.nicovideo.jp/api/getpostkey?") +
             "thread=" + thread +
             "&block_no=" + QString::number(block_no) ));

  connect(mManager, SIGNAL(finished(QNetworkReply*)), this,
          SLOT(postKeyFinished(QNetworkReply*)));
  mManager->get(rq);
}

void NicoLiveManager::postKeyFinished(QNetworkReply* reply){
  QByteArray repdata = reply->readAll();
  // int t = repdata.indexOf(".", 9);
  auto postKey = repdata.mid(8);
  nowWaku.setPostKey(QString(postKey));
}
