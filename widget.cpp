#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("图片阅读器");
    this->picLabel = new QLabel("                                        暂无可显示图片...");
    this->picLabel->setMinimumSize(640, 480);
    this->playButton = new QPushButton("显示");
    this->pathEdit = new QLineEdit;
    this->selectButton = new QPushButton("...");
    this->frontPicBtn = new QPushButton("上一张");
    this->nextPicBtn = new QPushButton("下一张");
    this->movie = new QMovie;


    QHBoxLayout *hbox = new QHBoxLayout;
    QVBoxLayout *vbox = new QVBoxLayout;
    QScrollArea *sa = new QScrollArea;

    sa->setMinimumSize(640,480);

    hbox->addWidget(pathEdit);
    hbox->addWidget(selectButton);
    hbox->addWidget(frontPicBtn);
    hbox->addWidget(nextPicBtn);
    hbox->addWidget(playButton);
    sa->setWidget(picLabel);
    vbox->addWidget(sa);
    vbox->addLayout(hbox);
    this->setLayout(vbox);
    this->pic_num = 0;

    connect(this->playButton, SIGNAL(clicked(bool)), this, SLOT(on_playButton_clicked()));
    connect(this->selectButton, SIGNAL(clicked(bool)), this, SLOT(on_selectButton_clicked()));
    connect(this->frontPicBtn, SIGNAL(clicked(bool)), this, SLOT(on_frontButton_clicked()));
    connect(this->nextPicBtn, SIGNAL(clicked(bool)), this, SLOT(on_nextButton_clicked()));
}

Widget::~Widget()
{

}

void Widget::on_playButton_clicked()
{
    if(this->pic_num < 0){
        this->pic_num = this->list.size()-1;
    }
    QString picPath;
    if(this->pathEdit->text().trimmed() != NULL){
        picPath = this->pathEdit->text().trimmed();
    }
    else{
        picPath = this->list.at(this->pic_num);
    }

    if(picPath.contains(".gif"))
    {
        this->movie->stop();
        this->movie->setFileName(picPath);
        this->picLabel->setMovie(this->movie);
        this->movie->start();
        qDebug() << "is gif";
    }
    else
    {
        this->picLabel->setPixmap(QPixmap(picPath));
        this->picLabel->setScaledContents(1);
    }
}

void Widget::on_selectButton_clicked()
{
    this->pic_num = 0;
    this->list = QFileDialog::getOpenFileNames(this, "选择多个文件", "D:/picture");
    this->on_playButton_clicked();
}

void Widget::on_frontButton_clicked()
{
    this->pic_num = (--this->pic_num)%this->list.size();
    this->on_playButton_clicked();
}

void Widget::on_nextButton_clicked()
{
    this->pic_num = (++this->pic_num)%this->list.size();
    this->on_playButton_clicked();
}
