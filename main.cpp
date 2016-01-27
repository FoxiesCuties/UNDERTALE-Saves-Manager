#include "UnSavManager.hpp"
#include <QtWidgets>

QPixmap splashScreen(QPixmap pix, QString text)
{
    QFont font("Determination Mono", 20);

    QFontMetrics metricFont(font);

    int textWidth = metricFont.width(text);

    QPixmap mMerged(pix.size());
        mMerged.fill(Qt::transparent);//Alpha

    QPainter mPainter(&mMerged);
        mPainter.setFont(font);
        mPainter.setPen(QPen(QColor("lightgrey")));
        mPainter.drawPixmap(0, 0, pix);
        mPainter.drawText(QPoint( (pix.width() / 2) - (textWidth / 2), 160), text);

    return mMerged;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Required for add "Determination Mono" font.
    QFontDatabase::addApplicationFont(":/fonts/DTM");

    QSplashScreen screen;

    UnSavManager unSav;

    screen.setPixmap(splashScreen(QPixmap(":imgs/splash"), "Alpha"));
    screen.show();

    QObject().thread()->sleep(2);//Fake thread for wait 2 secondes

    screen.hide();

    unSav.show();

    return app.exec();
}
