#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QFileDialog>
#include <QList>
#include <QDebug>
#include <QMovie>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void on_playButton_clicked(void);
    void on_selectButton_clicked(void);
    void on_frontButton_clicked(void);
    void on_nextButton_clicked(void);
private:
    QLabel *picLabel;
    QPushButton *playButton;
    QPushButton *selectButton;
    QPushButton *nextPicBtn;
    QPushButton *frontPicBtn;
    QLineEdit *pathEdit;
    QMovie *movie;
    QList<QString> list;
    int pic_num;
};

#endif // WIDGET_H
