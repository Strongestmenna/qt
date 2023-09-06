#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMessageBox>
#include<QSystemTrayIcon>
#include <QRegExp>
#include "connection.h"
#include <QFileDialog>
#include <QPainter>
#include <QDate>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
#include <QApplication>
#include <QIntValidator>
#include <QSqlQuery>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QtDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QtCore>
#include "qrcode.h"
#include "smtp.h"


using namespace qrcodegen;
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableView->setModel(e.afficher());
    ui->tableView_2->setModel(a.afficher());
    // control de saisie numreique
    ui->deleteid->setValidator(new QIntValidator(0, 999999,this));
    ui->agem->setValidator(new QIntValidator(0, 999999,this));
    ui->idm->setValidator(new QIntValidator(0, 999999,this));
    ui->age->setValidator(new QIntValidator(0, 999999,this));
    ui->maxa->setValidator(new QIntValidator(0, 999999,this));
    ui->idea->setValidator(new QIntValidator(0, 999999,this));
    ui->deleteida->setValidator(new QIntValidator(0, 999999,this));
    ui->maxam->setValidator(new QIntValidator(0, 999999,this));
    ui->idmm->setValidator(new QIntValidator(0, 999999,this));
    ui->ideam->setValidator(new QIntValidator(0, 999999,this));
    // control de saisie numreique
    QRegExp rx("[a-zA-Z]+");
        QValidator *validator =new
                QRegExpValidator(rx,this);
        ui->Adresse->setValidator(validator);
        ui->email->setValidator(validator);
        ui->prenom->setValidator(validator);
        ui->nom->setValidator(validator);
        ui->emailm->setValidator(validator);
        ui->adressem->setValidator(validator);
        ui->prenomm->setValidator(validator);
        ui->nomm->setValidator(validator);
        ui->descam->setValidator(validator);
        ui->lieuam->setValidator(validator);
        ui->nomam->setValidator(validator);
        ui->lieua->setValidator(validator);
        ui->desca->setValidator(validator);
        ui->noma->setValidator(validator);
        ui->idm->setVisible(false);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    int age=ui->age->text().toInt();
    QString adresse=ui->Adresse->text();
    QString email=ui->email->text();
    QString genre=ui->genre->currentText();
    enseignants e(nom,prenom,email,adresse,genre,age);
    bool test=e.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("ajoute \n"
                                                 "click to cancel"), QMessageBox::Cancel);
            ui->nom->clear();
            ui->prenom->clear();
            ui->age->clear();
            ui->email->clear();
            ui->Adresse->clear();
            ui->tableView->setModel(e.afficher());
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from enseignants  where id='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or adresse='"+val+"' or age='"+val+"'");

    if (qry.exec())
    { while (qry.next())
        {
            //update
            //id
            ui->idm->setText(qry.value(0).toString());
            ui->nomm->setText(qry.value(1).toString());
            ui->prenomm->setText(qry.value(2).toString());
            ui->emailm->setText(qry.value(3).toString());
            ui->adressem->setText(qry.value(4).toString());

            ui->agem->setText(qry.value(6).toString());
            //delete
            //id
            ui->deleteid->setText(qry.value(0).toString()); //pour supprimer


        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    int id =ui->deleteid->text().toUInt();
        bool test=e.supprimer(id);
        if (test)
        {
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimé \n" "click to cancel"),QMessageBox::Cancel);
            ui->tableView->setModel(e.afficher());

        }
    else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
    QString nomm=ui->nomm->text();
    QString prenomm=ui->prenomm->text();
    int agem=ui->agem->text().toInt();
    QString adressem=ui->adressem->text();
    QString emailm=ui->emailm->text();
    QString genrem=ui->genrem->currentText();
    int idm=ui->idm->text().toInt();
    bool test=e.modifier(idm,nomm,prenomm,emailm,adressem,genrem,agem);
    if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("ok"),
                                         QObject::tr("modifier \n"
                                                     "click to cancel"), QMessageBox::Cancel);
                 ui->tableView->setModel(e.afficher());
            }
            else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
// modifier activie
void MainWindow::on_pushButton_16_clicked()
{
    QString nom=ui->nomam->text();
    QString desc=ui->descam->text();
    QString lieu=ui->lieuam->text();
    int max=ui->maxam->text().toInt();
    int ide=ui->ideam->text().toInt();
    int id=ui->idmm->text().toInt();
    bool test=a.modifier(id,nom,desc,lieu,max,ide);
    if(test)
            {
                 ui->tableView_2->setModel(a.afficher());
                 a.notification("Activite modifier avec succee");
            }
            else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);
}
// ajouter activitee
void MainWindow::on_pushButton_14_clicked()
{
        QString noma=ui->noma->text();
        QString desca=ui->desca->text();
        QString lieua=ui->lieua->text();
        int max=ui->idea->text().toInt();
        int ide=ui->maxa->text().toInt();
        activites a(noma,desca,lieua,ide,max);
        bool test=a.ajouter();
            if(test)
            {
                a.notification("Activite ajouter avec succee");
                ui->noma->clear();
                ui->desca->clear();
                ui->lieua->clear();
                ui->maxa->clear();
                ui->tableView_2->setModel(a.afficher());
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);
}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from activites  where id='"+val+"' or NOM='"+val+"' or descri='"+val+"' or lieu='"+val+"' or maxp='"+val+"'");

    if (qry.exec())
    { while (qry.next())
        {
            //update
            //id
            ui->idmm->setText(qry.value(0).toString());
            ui->nomam->setText(qry.value(1).toString());
            ui->descam->setText(qry.value(2).toString());
            ui->maxam->setText(qry.value(3).toString());
            ui->ideam->setText(qry.value(4).toString());
            ui->lieuam->setText(qry.value(5).toString());
            //delete
            //id
            ui->deleteida->setText(qry.value(0).toString()); //pour supprimer


        }
    }
}

void MainWindow::on_pushButton_15_clicked()
{
    int id =ui->deleteida->text().toUInt();
        bool test=a.supprimer(id);
        if (test)
        {
            a.notification("Activite supprimer avec succee");
            ui->tableView_2->setModel(a.afficher());

        }
    else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->tableView_2->setModel(a.tri_lieu());
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->tableView_2->setModel(a.tri_nom());
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->tableView_2->setModel(a.tri_max());
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->tableView->setModel(e.tri_prenom());
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->tableView->setModel(e.tri_nom());
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->tableView->setModel(e.tri_age());
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM ENSEIGNANTS WHERE ID  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or PRENOM  LIKE'"+arg1+"%' or EMAIL LIKE'"+arg1+"%' or AGE  LIKE'"+arg1+"%' or GENRE  LIKE'"+arg1+"%' or ADRESSE  LIKE'"+arg1+"%' ");
     query->exec();
     if (query->next()) {
     model->setQuery(*query);
     ui->tableView->setModel(model);
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !!\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->lineEdit->clear();}
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM ACTIVITES WHERE ID  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or DESCRI  LIKE'"+arg1+"%' or MAXP LIKE'"+arg1+"%' or LIEU  LIKE'"+arg1+"%'");
     query->exec();
     if (query->next()) {
     model->setQuery(*query);
     ui->tableView->setModel(model);
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !!\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->lineEdit_2->clear();}
}

void MainWindow::on_pushButton_17_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                                    model->setQuery("select * from ENSEIGNANTS where GENRE = 'homme' ");
                                    float e=model->rowCount();
                                    model->setQuery("select * from ENSEIGNANTS where GENRE = 'femme' ");
                                    float ee=model->rowCount();
                                    float total=e+ee;
                                    QString a=QString("Homme"+QString::number((e*100)/total,'f',2)+"%" );
                                    QString b=QString("Femme"+QString::number((ee*100)/total,'f',2)+"%" );
                                    QPieSeries *series = new QPieSeries();
                                    series->append(a,e);
                                    series->append(b,ee);
                            if (e!=0)
                            {QPieSlice *slice = series->slices().at(0);
                             slice->setLabelVisible();
                             slice->setPen(QPen());}
                            if ( ee!=0)
                            {
                                     // Add label, explode and define brush for 2nd slice
                                     QPieSlice *slice1 = series->slices().at(1);
                                     //slice1->setExploded();
                                     slice1->setLabelVisible();
                            }
                                    // Create the chart widget
                                    QChart *chart = new QChart();
                                    // Add data to chart with title and hide legend
                                    chart->addSeries(series);
                                    chart->setTitle("Pourcentage des homme et femme : nombre total : "+ QString::number(total));
                                    chart->legend()->hide();
                                    // Used to display the chart
                                    QChartView *chartView = new QChartView(chart);
                                    chartView->setRenderHint(QPainter::Antialiasing);
                                    chartView->resize(1000,500);
                                    chartView->show();
}

void MainWindow::on_pushButton_18_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                                    model->setQuery("select * from ACTIVITES where MAXP > 100 ");
                                    float e=model->rowCount();
                                    model->setQuery("select * from ACTIVITES where MAXP < 100 ");
                                    float ee=model->rowCount();
                                    float total=e+ee;
                                    QString a=QString("Grande activite"+QString::number((e*100)/total,'f',2)+"%" );
                                    QString b=QString("Grande activite"+QString::number((ee*100)/total,'f',2)+"%" );
                                    QPieSeries *series = new QPieSeries();
                                    series->append(a,e);
                                    series->append(b,ee);
                            if (e!=0)
                            {QPieSlice *slice = series->slices().at(0);
                             slice->setLabelVisible();
                             slice->setPen(QPen());}
                            if ( ee!=0)
                            {
                                     // Add label, explode and define brush for 2nd slice
                                     QPieSlice *slice1 = series->slices().at(1);
                                     //slice1->setExploded();
                                     slice1->setLabelVisible();
                            }
                                    // Create the chart widget
                                    QChart *chart = new QChart();
                                    // Add data to chart with title and hide legend
                                    chart->addSeries(series);
                                    chart->setTitle("Ratio grand vs petit : nombre total d'activite : "+ QString::number(total));
                                    chart->legend()->hide();
                                    // Used to display the chart
                                    QChartView *chartView = new QChartView(chart);
                                    chartView->setRenderHint(QPainter::Antialiasing);
                                    chartView->resize(1000,500);
                                    chartView->show();
}

void MainWindow::on_pushButton_25_clicked()
{
                  int tabeq=ui->tableView_2->currentIndex().row();
                  QVariant idd=ui->tableView_2->model()->data(ui->tableView_2->model()->index(tabeq,0));
                  QString id=idd.toString();
                 // QString code=idd.toSTring();
                  QSqlQuery qry;
                  qry.prepare("select * from activites where id=:code");
                  qry.bindValue(":code",id);
                  qry.exec();

                   QString nom,desc,lieu;//attributs
                   int max;

                 while(qry.next()){

                     id=qry.value(0).toString();
                      nom=qry.value(1).toString();
                       desc=qry.value(2).toString();
                      lieu=qry.value(5).toInt();
                      max=qry.value(3).toInt();
                  }
                  id=QString(id);
                         id="CODE:\t" +id+ "NOM\t:" +nom+ "descri:\t" +desc+ "lieu:\t" +lieu+ "max:\t" +max ;
                  QrCode qr = QrCode::encodeText(id.toUtf8().constData(), QrCode::Ecc::HIGH);

                  // Read the black & white pixels
                  QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
                  for (int y = 0; y < qr.getSize(); y++) {
                      for (int x = 0; x < qr.getSize(); x++) {
                          int color = qr.getModule(x, y);  // 0 for white, 1 for black

                          // You need to modify this part
                          if(color==0)
                              im.setPixel(x, y,qRgb(254, 254, 254));
                          else
                              im.setPixel(x, y,qRgb(0, 0, 0));
                      }
                  }
                  im=im.scaled(200,200);
                  ui->qrcode->setPixmap(QPixmap::fromImage(im));
}

void MainWindow::on_pushButton_26_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
        qDebug()<<dir;
        QPdfWriter pdf(dir+"/PdfList.pdf");
                               QPainter painter(&pdf);
                              int i = 4000;

                                   painter.drawPixmap(QRect(100,100,2500,2500),QPixmap("C:/logo1.jpg"));
                                   painter.setPen(Qt::red);
                                   painter.setFont(QFont("Time New Roman", 25));
                                   painter.drawText(3000,1400,"Listes des enseignants");
                                   painter.setPen(Qt::black);
                                   painter.setFont(QFont("Time New Roman", 15));
                                   painter.drawRect(100,100,9400,2500); // dimension taa rectangle li fih liste
                                   painter.drawRect(100,3000,9400,500);
                                   painter.setFont(QFont("Time New Roman", 9));
                                   painter.drawText(300,3300,"ID");
                                   painter.drawText(2000,3300,"Nom");
                                   painter.drawText(4000,3300,"Prenom");
                                   painter.drawText(5600,3300,"EMAIL");
                                   painter.drawText(7000,3300,"AGE");
                                   painter.drawText(8000,3300,"GENRE");
                                   painter.drawRect(100,3000,9400,10700);
                                   QTextDocument previewDoc;
                                   QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");
                                   QTextCursor cursor(&previewDoc);
                                   QSqlQuery query;
                                   query.prepare("select * from ENSEIGNANTS");
                                   query.exec();
                                   while (query.next())
                                   {
                                       painter.drawText(300,i,query.value(0).toString());
                                       painter.drawText(2000,i,query.value(1).toString());
                                       painter.drawText(4000,i,query.value(2).toString());
                                       painter.drawText(5600,i,query.value(4).toString());
                                       painter.drawText(7000,i,query.value(6).toString());
                                       painter.drawText(8000,i,query.value(5).toString());
                                      i = i +500;
                                   }
                                   int reponse = QMessageBox::question(this, "Générer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                       QMessageBox::Yes|QMessageBox::No);
                                       if (reponse == QMessageBox::Yes)
                                       {
                                           QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                           painter.end();
                                       }
                                       else
                                       {
                                            painter.end();
    }

}

//mailling
void MainWindow::on_envoyer_2_clicked()
{
    connect(ui->envoyer_2, SIGNAL(clicked()),this, SLOT(sendMail()));
}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("naimantar65@gmail.com", "tdeslvzcffmcbzsc","smtp.gmail.com",465,30000);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("promotion", ui->lineEdit_14->text() , ui->lineEdit_13->text(),ui->textEdit_2->toPlainText());
}



void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
