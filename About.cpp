#include "About.hpp"

About::About()
{
    createObjects();
    createConnexions();
    createInterface();
    createObjectName();
    createSettings();
}

//Organizers
void About::createObjects()
{
    mAboutVBox      = new QVBoxLayout;
    mAboutCButton   = new QPushButton;
    mAboutTHbox     = new QHBoxLayout;
    mAboutTButton   = new TPushButton(this);
    mAboutVbox      = new QVBoxLayout;
    mAboutPixmap    = new QLabel;
    mTAboutVBox     = new QVBoxLayout;
    mAboutTitle     = new QLabel;
    mAboutDev       = new QLabel;
    mAboutAst       = new QLabel;
    mAboutGButton   = new QPushButton;
}
void About::createConnexions()
{
    connect(mAboutCButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(mAboutGButton, SIGNAL(clicked()), this, SLOT(openGitHubProject()));
}
void About::createInterface()
{
    mAboutTitle->setText("About");

    mAboutTHbox->addWidget(mAboutCButton, 1, Qt::AlignRight | Qt::AlignTop);
    mAboutTHbox->setContentsMargins(0, 22, 9, 0);

    mAboutPixmap->setPixmap(QPixmap(":imgs/settings/setBan"));
    mAboutPixmap->setAlignment(Qt::AlignCenter);
    mAboutPixmap->setLayout(mAboutTHbox);
    mAboutPixmap->setContentsMargins(0, -15, -7, -25);

    mTAboutVBox->addWidget(mAboutPixmap, 1);
    mTAboutVBox->addWidget(mAboutTitle, 0, Qt::AlignHCenter);

    mAboutTButton->setLayout(mTAboutVBox);
    mAboutTButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
    mAboutTButton->setFixedHeight(90);

    mAboutDev->setText("- Developer -");

    mAboutAst->setText("- Assistant -");

    mAboutVBox->addWidget(mAboutDev, 0, Qt::AlignHCenter);
    mAboutVBox->addWidget(new QLabel("FoxiesCuties"), 0, Qt::AlignHCenter);
    mAboutVBox->addWidget(mAboutAst, 0, Qt::AlignHCenter);
    mAboutVBox->addWidget(new QLabel("Dreamslike"), 0, Qt::AlignHCenter);
    mAboutVBox->addWidget(new QLabel("\n\n"), 0, Qt::AlignHCenter);
    mAboutVBox->addWidget(mAboutGButton, 0, Qt::AlignHCenter | Qt::AlignBottom);
    mAboutVBox->setContentsMargins(11, 7, 11, 11);
    mAboutVBox->setAlignment(Qt::AlignTop);

    mAboutVbox->addWidget(mAboutTButton, 1, Qt::AlignTop);
    mAboutVbox->addLayout(mAboutVBox, 0);
}
void About::createObjectName()
{
    mAboutTitle->setObjectName("Label_About_Title");
    mAboutTButton->setObjectName("Button_About_Title");
    mAboutCButton->setObjectName("Button_About_Close");
    mAboutDev->setObjectName("Label_About_Header");
    mAboutAst->setObjectName("Label_About_Header");
    mAboutGButton->setObjectName("Button_About_Github");
}
void About::createSettings()
{
    this->setWindowTitle("UNDERTALE Save Manager - " + mAboutTitle->text());
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    this->setContentsMargins(-8, -8, -8, -8);
    this->setLayout(mAboutVbox);
    this->setFixedSize(400, 350);
}

//Slots
void About::openGitHubProject()
{
    QDesktopServices::openUrl(QUrl("https://github.com/FoxiesCuties/UNDERTALE-Saves-Manager", QUrl::StrictMode));
}

//Events
void About::keyPressEvent(QKeyEvent *event)
{
    event->ignore();
}
void About::closeEvent(QCloseEvent *event)
{
    //Accept only internal closing events
    event->setAccepted(!event->spontaneous());
}
