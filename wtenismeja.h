#ifndef WTENISMEJA_H
#define WTENISMEJA_H

#include <QWidget>
#include <QMessageBox>
#include <QMultimedia>
#include <QAudioOutput>
#include <QAudioDeviceInfo>
#include <QMediaPlayer>

#include <QTimer>

namespace Ui {
class WTenisMeja;
}

class WTenisMeja : public QWidget
{
    Q_OBJECT

public:
    explicit WTenisMeja(QWidget *parent = 0);
    ~WTenisMeja();

    void deuce(int n, int p);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_5_clicked();

private:
    Ui::WTenisMeja *ui;

    int point;
    int point2;

    QMediaPlayer *player;
    QMediaPlayer *player2;
};

#endif // WTENISMEJA_H
