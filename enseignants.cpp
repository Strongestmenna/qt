#include "enseignants.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>

using namespace std;
/////////////////////////////////// constructeur par defaut ///////////////////////////////////////////////////////
/// le role mta constructeur yaamel instance men objet == > ya3ni yaamel creation mta objet
///
enseignants::enseignants()
{
id=0;
nom=" ";
prenom=" ";
email=" ";
street=" ";
genre=" ";
age=0;
}
////////////////////////////// constructeur parrametres ///////////////////////////////////////////////////////////
enseignants::enseignants(QString nom , QString prenom, QString  email, QString street, QString genre, int age)
{
    this->nom=nom;this->prenom=prenom;this->email=email;this->street=street;this->genre=genre;this->age=age;
}
/////////////////////// getters /////////////////////////////////////*
/// le role mta getter irecuperi donné
///
QString enseignants::getnom(){return nom;}
QString enseignants::getprenom(){return prenom;}
QString enseignants::getemail (){return email;}
QString enseignants::getstreet (){return street;}
QString enseignants::getgenre() {return genre;}
int enseignants::getage (){return age;}
int enseignants::getid(){return id;}
////////////////////////// setters ///////////////////////////////////
/// le role mtea setter ybaddel donné
///
void enseignants::setnom (QString nom){this->nom=nom;}
void enseignants::setprenom (QString prenom){this->prenom=prenom;}
void enseignants::setemail (QString email){this->email=email;}
void enseignants::setstreet (QString street){this->street=street;}
void enseignants::setgenre (QString genre){this->genre=genre;}
void enseignants::setage(int age){this->age=age;}
////////////////////////////////////////////////////////
/// bind value tinseri vaaleur fel requette sql
/// query.exec(); texecuti requette
/// el khadhra hia requette dima tabda b insert wala delete wala update wala select
///
bool enseignants::ajouter()
{
    QSqlQuery query;
    QString age_string=QString::number(age);

         query.prepare("INSERT INTO enseignants (nom,prenom,email,adresse,genre,age) "
                       "VALUES (:nom, :prenom, :email, :street, :genre, :age )");
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":email", email);
         query.bindValue(":street", street);
         query.bindValue(":genre", genre);
         query.bindValue(":age", age);
         return query.exec();
}



bool enseignants::supprimer(int id )
{
    QSqlQuery query;
         query.prepare("delete from enseignants where id=:id");
         query.bindValue(":id", id);
         return query.exec();
}

QSqlQueryModel* enseignants::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM enseignants ORDER BY id");
    model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("ID"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("ADRESSE"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("GENRE"));
    model ->setHeaderData(6,Qt::Horizontal,QObject::tr("AGE"));
    return model;
}

QSqlQueryModel *enseignants::tri_age()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM enseignants ORDER BY age");
    model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("ID"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("ADRESSE"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("GENRE"));
    model ->setHeaderData(6,Qt::Horizontal,QObject::tr("AGE"));
    return model;
}

QSqlQueryModel *enseignants::tri_nom()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM enseignants ORDER BY nom");
    model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("ID"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("ADRESSE"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("GENRE"));
    model ->setHeaderData(6,Qt::Horizontal,QObject::tr("AGE"));
    return model;
}

QSqlQueryModel *enseignants::tri_prenom()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM enseignants ORDER BY prenom");
    model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("ID"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("ADRESSE"));
    model ->setHeaderData(5,Qt::Horizontal,QObject::tr("GENRE"));
    model ->setHeaderData(6,Qt::Horizontal,QObject::tr("AGE"));
    return model;
}


bool enseignants::modifier(int id,QString nom, QString prenom, QString email, QString street, QString genre, int age)
{
    QSqlQuery query;
        query.prepare("UPDATE enseignants SET nom=:nom,prenom=:prenom,email=:email,adresse=:street,genre=:genre,age=:age where id=(?)");
        query.addBindValue(nom);
        query.addBindValue(prenom);
        query.addBindValue(email);
        query.addBindValue(street);
        query.addBindValue(genre);
        query.addBindValue(age);
        query.addBindValue(id);
   return  query.exec();
}
