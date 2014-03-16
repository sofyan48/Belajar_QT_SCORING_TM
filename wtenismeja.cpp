#include "wtenismeja.h"
#include "ui_wtenismeja.h"

WTenisMeja::WTenisMeja(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WTenisMeja)
{
    ui->setupUi(this);

    this->setWindowTitle("SKORING TENIS MEJA DIES NATALIS 2014");

    this->ui->webView->load(QUrl("http://stmikadhiguna.ac.id"));

    this->ui->lcdNumber->setFixedSize(420,200);
    this->ui->lcdNumber_2->setFixedSize(420,200);

    this->ui->lcdNumber->display("0000");
    this->ui->lcdNumber_2->display("0000");
    this->ui->lcdNumber_3->display("00:00");

    this->ui->pushButton_5->hide();
    this->ui->pushButton_3->hide();

    this->point=0;
    this->point2=0;

    player2 = new QMediaPlayer;
    player = new QMediaPlayer;
}

WTenisMeja::~WTenisMeja()
{
    delete ui;
}

void WTenisMeja::on_pushButton_clicked()
{
   int p1=0;
    if (p1==0){
        point+=1;
    }
    if (this->point==9){

        this->player->setMedia(QUrl::fromLocalFile("/home/meong/TenisMeja/sounds/l2.ogg"));
        this->player->setVolume(100);
        this->player->play();
    }
    else if (this->point==10){

        this->player->setMedia(QUrl::fromLocalFile("/home/meong/TenisMeja/sounds/l1.ogg"));
        this->player->setVolume(100);
        this->player->play();
        this->deuce(this->point,this->point2);
    }
    else if (this->point==11){

        this->player->setMedia(QUrl::fromLocalFile("/home/meong/TenisMeja/sounds/gmp.ogg"));
        this->player->setVolume(100);
        this->player->play();
        if ((this->point)==(this->point2)){
           this->deuce(this->point,this->point2);
        }
        this->ui->pushButton_3->show();
    }
    else if (point==12){
        this->ui->lcdNumber_2->display("lost");
        this->ui->pushButton_2->hide();
        this->ui->pushButton_3->show();
    }
    else if (point>=13){
        QMessageBox::StandardButton reply;
          reply = QMessageBox::question(this, "Warning", "Maaf Anda hanya Bisa\nMemasukan Point sampai 11\nKecuali Dalam Posisi Deuce Maka Poin Akan\nLebih Dari 11\nTekan Yes Untuk Kembali Dan tekan Tombol Next Mach",
                                        QMessageBox::Yes|QMessageBox::No);
          if (reply == QMessageBox::Yes) {
                this->point=0;
                this->player->setMedia(QUrl::fromLocalFile("/home/meong/TenisMeja/sounds/nm.ogg"));
                this->player->play();
              this->ui->lcdNumber_2->display("0000");
          } else {
              this->point=0;
              this->ui->lcdNumber_2->display("error");
              this->ui->pushButton->hide();
              this->ui->pushButton_2->hide();
              this->ui->pushButton_4->hide();
              this->ui->pushButton_5->show();
              this->ui->pushButton_3->hide();
          }

    }
    this->ui->lcdNumber->display(point);

}

void WTenisMeja::on_pushButton_2_clicked()
{
    int p2=0;
     if (p2==0){
         point2+=1;
     }
     if (this->point2==9){
         this->player = new QMediaPlayer;
         this->player->setMedia(QUrl::fromLocalFile("/home/meong/TenisMeja/sounds/l2.ogg"));
         this->player->setVolume(100);
         this->player->play();
     }
     if (this->point2==10){
        //QMessageBox::information(0, "Information", "GAME POINT");

         this->player->setMedia(QUrl::fromLocalFile("/home/meong/TenisMeja/sounds/l1.ogg"));
         this->player->setVolume(100);
         this->player->play();

         this->deuce(this->point,this->point2);
     }
     else if (this->point2==11){
         //QMessageBox::information(0, "Information", "Winner");
         this->player->setMedia(QUrl::fromLocalFile("/home/meong/TenisMeja/sounds/gmp.ogg"));
         this->player->setVolume(100);
         this->player->play();
         if ((this->point) == (this->point2)){
            this->deuce(this->point,this->point2);
         }
         this->ui->pushButton_3->show();

     }
     else if (point2==12){
         this->ui->lcdNumber->display("Lost");
         this->ui->pushButton->hide();
         this->ui->pushButton_3->show();
     }

     else if (point2>12){
         QMessageBox::StandardButton reply;
           reply = QMessageBox::question(this, "Warning", "Maaf Anda hanya Bisa\nMemasukan Point sampai 11\nKecuali Dalam Posisi Deuce Maka Poin Akan\nLebih Dari 11\nTekan Yes Untuk Kembali Dan tekan Tombol Next Mach",
                                         QMessageBox::Yes|QMessageBox::No);
           if (reply == QMessageBox::Yes) {
                this->point2=0;
                this->player->setMedia(QUrl::fromLocalFile("/home/meong/TenisMeja/sounds/nm.ogg"));
               this->player->play();
               this->ui->lcdNumber->display("0000");
           } else {
               this->point=0;
               this->ui->lcdNumber_2->display("error");
               this->ui->pushButton->hide();
               this->ui->pushButton_2->hide();
               this->ui->pushButton_4->hide();
               this->ui->pushButton_5->show();
               this->ui->pushButton_3->hide();
           }

     }
     this->ui->lcdNumber_2->display(point2);
}

void WTenisMeja::on_toolButton_clicked()
{
    int p2=0;
     if (p2==0){
         point2-=1;
     }
     if (this->point2==-1){
         QMessageBox::warning(0,"WARNING","Maaf terjadi Kesalahan Point \nPoint Hanya Bisa Sampai 0");
         this->point2=0;
     }
     this->ui->lcdNumber_2->display(point2);
}

void WTenisMeja::on_toolButton_2_clicked()
{
    int p1=0;
     if (p1==0){
         point-=1;
     }
     if (this->point==-1){
         QMessageBox::warning(0,"WARNING","Maaf terjadi Kesalahan Point \nPoint Hanya Bisa Sampai 0");
         this->point=0;
     }
     this->ui->lcdNumber->display(point);
}

void WTenisMeja::on_pushButton_4_clicked()
{
    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("/home/meong/TenisMeja/sounds/sv.ogg"));
    player->setVolume(100);
    player->play();
}

void WTenisMeja::on_pushButton_3_clicked()
{
    this->point=0;
    this->point2=0;

    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("/home/meong/TenisMeja/sounds/nm.ogg"));
    player->setVolume(100);
    player->play();

    this->ui->lcdNumber->display("0000");
    this->ui->lcdNumber_2->display("0000");
    this->ui->pushButton_2->show();
    this->ui->pushButton->show();
}

void WTenisMeja::on_comboBox_activated(const QString &arg1)
{
    if (arg1=="ALFAKHI"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">ALFAKHI</span></p></body></html>", 0));
    }
    else if (arg1=="AGUS"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">AGUS</span></p></body></html>", 0));
    }
    else if (arg1=="ARFAN"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">ARFAN</span></p></body></html>", 0));;
    }
    else if(arg1=="AYYUB"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">AYYUB</span></p></body></html>", 0));
    }
    else if(arg1=="DARMAN"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">DARMAN</span></p></body></html>", 0));
    }
    else if(arg1=="EDWIN"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">EDWIN</span></p></body></html>", 0));
    }
    else if(arg1=="EWIN"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">EWIN</span></p></body></html>", 0));
    }
    else if(arg1=="HAJRUNA"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">HAJRUNA</span></p></body></html>", 0));
    }
    else if(arg1=="ISHAK"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">ISHAK</span></p></body></html>", 0));
    }
    else if(arg1=="JHUN"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">JHUN</span></p></body></html>", 0));
    }
    else if(arg1=="KIKI"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">KIKI</span></p></body></html>", 0));
    }
    else if(arg1=="MAMAN"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">MAMAN</span></p></body></html>", 0));
    }
    else if(arg1=="MIRWAN"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">MIRWAN</span></p></body></html>", 0));
    }

    else if(arg1=="MOH.KHARIS"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">MOH.KHARIS</span></p></body></html>", 0));
    }
    else if(arg1=="RIFKY"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">RIFKY</span></p></body></html>", 0));
    }
    else if(arg1=="REVEN"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">REVEN</span></p></body></html>", 0));
    }
    else if(arg1=="SUFRIADI"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">SUFRIADI</span></p></body></html>", 0));
    }
    else if(arg1=="SYAHRULLAH"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">SYAHRULLAH</span></p></body></html>", 0));
    }
    else if(arg1=="SURAHMAT"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">SURAHMAT</span></p></body></html>", 0));
    }
    else if(arg1=="TAKIM"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">TAKIM</span></p></body></html>", 0));
    }
    else if(arg1=="VICTOR"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">ITOY</span></p></body></html>", 0));
    }
    else if(arg1=="WAWAN"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">WAWAN OI GODE</span></p></body></html>", 0));
    }
    else if(arg1=="Select People"){
        this->ui->label_2->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">Nama</span></p></body></html>", 0));
    }
    else {
        QMessageBox::information(0, "WARNING", "Tidak Ada Orang Yang Di Pilih");
    }
}

void WTenisMeja::on_comboBox_2_activated(const QString &arg1)
{
    if (arg1=="ALFAKHI"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">ALFAKHI</span></p></body></html>", 0));
    }
    else if (arg1=="AGUS"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">AGUS</span></p></body></html>", 0));
    }
    else if (arg1=="ARFAN"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">ARFAN</span></p></body></html>", 0));;
    }
    else if(arg1=="AYYUB"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">AYYUB</span></p></body></html>", 0));
    }
    else if(arg1=="DARMAN"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">DARMAN</span></p></body></html>", 0));
    }
    else if(arg1=="EDWIN"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">EDWIN</span></p></body></html>", 0));
    }
    else if(arg1=="EWIN"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">EWIN</span></p></body></html>", 0));
    }
    else if(arg1=="HAJRUNA"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">HAJRUNA</span></p></body></html>", 0));
    }
    else if(arg1=="ISHAK"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">ISHAK</span></p></body></html>", 0));
    }
    else if(arg1=="JHUN"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">JHUN</span></p></body></html>", 0));
    }
    else if(arg1=="KIKI"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">KIKI</span></p></body></html>", 0));
    }
    else if(arg1=="MAMAN"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">MAMAN</span></p></body></html>", 0));
    }
    else if(arg1=="MIRWAN"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">MIRWAN</span></p></body></html>", 0));
    }

    else if(arg1=="MOH.KHARIS"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">MOH.KHARIS</span></p></body></html>", 0));
    }
    else if(arg1=="RIFKY"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">RIFKY</span></p></body></html>", 0));
    }
    else if(arg1=="REVEN"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">REVEN</span></p></body></html>", 0));
    }
    else if(arg1=="SUFRIADI"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">SUFRIADI</span></p></body></html>", 0));
    }
    else if(arg1=="SYAHRULLAH"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">SYAHRULLAH</span></p></body></html>", 0));
    }
    else if(arg1=="SURAHMAT"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">SURAHMAT</span></p></body></html>", 0));
    }
    else if(arg1=="TAKIM"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">TAKIM</span></p></body></html>", 0));
    }
    else if(arg1=="VICTOR"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">ITOY</span></p></body></html>", 0));
    }
    else if(arg1=="WAWAN"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">WAWAN OI GODE</span></p></body></html>", 0));
    }

    else if(arg1=="Select People"){
        this->ui->label_3->setText(QApplication::translate("WTenisMeja", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#0000ff;\">Nama</span></p></body></html>", 0));
    }
    else {
        QMessageBox::information(0, "WARNING", "Tidak Ada Orang Yang Di Pilih");
    }
}

void WTenisMeja::deuce(int n, int p){
    if ((n==10) && (p==10)){
        this->player2->setMedia(QUrl::fromLocalFile("/home/meong/TenisMeja/sounds/win.mp3")); //deuce 1
        this->player2->setVolume(100);
        this->player2->play();
        this->player->stop();
    }
    else if (((n<=10) && (p>=11)) || ((n>=11) && (p<=10))){
        this->player->stop();
    }
    else if ((n==11) &&(p==11)){
        this->player->stop();
        this->player2->setMedia(QUrl::fromLocalFile("/home/meong/TenisMeja/sounds/win.mp3")); //deuce 2
        this->player2->play();
    }
}


void WTenisMeja::on_pushButton_5_clicked()
{
    this->ui->pushButton_5->hide();
    this->ui->pushButton_3->show();
    this->ui->pushButton->show();
    this->ui->pushButton_2->show();
    this->ui->pushButton_4->show();

    QMessageBox::information(0, "Information", "Tekan Tombol Next Mach\nUntuk Pertandingan Baru");
}
