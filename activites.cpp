#include "activites.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QString>
#include <QFile>
#include <QTextDocument>
#include<QTextStream>
#include<QIODevice>
#include<QDate>
#include <QSystemTrayIcon>

using namespace std;
/////////////////////////////////// constructeur par defaut ///////////////////////////////////////////////////////
/// le role mta constructeur yaamel instance men objet == > ya3ni yaamel creation mta objet
///
activites::activites()
{
id=0;
nom=" ";
desc=" ";
lieu=" ";
ide=0;
max=0;
}
////////////////////////////// constructeur parrametres ///////////////////////////////////////////////////////////
activites::activites(QString nom , QString desc, QString  lieu,int ide, int max)
{
    this->nom=nom;this->desc=desc;this->lieu=lieu;this->ide=ide;this->max=max;
}
/////////////////////// getters /////////////////////////////////////*
/// le role mta getter irecuperi donné
///
QString activites::getnom(){return nom;}
QString activites::getdesc(){return desc;}
QString activites::getlieu(){return lieu;}
int activites::getmax(){return max;}
int activites::getide(){return ide;}
////////////////////////// setters ///////////////////////////////////
/// le role mtea setter ybaddel donné
///
void activites::setnom (QString nom){this->nom=nom;}
void activites::setdesc (QString desc){this->desc=desc;}
void activites::setlieu (QString lieu){this->lieu=lieu;}
void activites::setmax (int max){this->max=max;}
void activites::setide(int ide){this->ide=ide;}
////////////////////////////////////////////////////////
/// bind value tinseri vaaleur fel requette sql
/// query.exec(); texecuti requette
/// el khadhra hia requette dima tabda b insert wala delete wala update wala select
///
bool activites::ajouter()
{
    QSqlQuery query;
    QString max_string=QString::number(max);
    QString ide_string=QString::number(ide);

         query.prepare("INSERT INTO activites (nom,descri,lieu,maxp,ide) "
                       "VALUES (:nom, :descri, :lieu, :maxp, :ide)");
         query.bindValue(":nom", nom);
         query.bindValue(":descri", desc);
         query.bindValue(":lieu", lieu);
         query.bindValue(":maxp",ide);
         query.bindValue(":ide",  max);
         return query.exec();
}



bool activites::supprimer(int id )
{
    QSqlQuery query;
         query.prepare("delete from activites where id=:id");
         query.bindValue(":id", id);
         return query.exec();
}

QSqlQueryModel* activites::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM activites ORDER BY id");
    model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("ID"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("DESC"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("MAX PARTICIPANT"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("IDE"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("LIEU"));
    return model;
}

QSqlQueryModel *activites::tri_max()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM activites ORDER BY maxp");
    model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("ID"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("DESC"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("MAX PARTICIPANT"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("IDE"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("LIEU"));
    return model;
}

QSqlQueryModel *activites::tri_nom()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM activites ORDER BY nom");
    model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("ID"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("DESC"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("MAX PARTICIPANT"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("IDE"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("LIEU"));
    return model;
}

QSqlQueryModel *activites::tri_lieu()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM activites ORDER BY lieu");
    model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("ID"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("DESC"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("MAX PARTICIPANT"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("IDE"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("LIEU"));
    return model;
}


bool activites::modifier(int id,QString nom, QString desc, QString lieu, int max,int ide)
{
    QSqlQuery query;
        query.prepare("UPDATE activites SET nom=:nom,descri=:desc,lieu=:lieu,maxp=:max,ide=:ide where id=(?)");
        query.addBindValue(nom);
        query.addBindValue(desc);
        query.addBindValue(lieu);
        query.addBindValue(max);
        query.addBindValue(ide);
        query.addBindValue(id);
   return  query.exec();
}

void activites::notification(QString cls)
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("NOTIFICATION",cls,QSystemTrayIcon::Information,15000);
}
