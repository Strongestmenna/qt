#ifndef ACTIVITES_H
#define ACTIVITES_H
#include <QString>
#include <QSqlQueryModel>


class activites
{
public:
    activites();
    activites(QString,QString,QString,int,int);

    QString getnom();
    QString getdesc();
    QString getlieu ();
    int getmax ();
    int getid();
    int getide();
    ////////////////////////////// Getter & Setter //////////////////////
    void setnom (QString);
    void setdesc (QString);
    void setlieu (QString);
    void setmax(int);
    void setide(int);
    /////////////////////////////// CRUD ///////////////////////////////
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel * tri();
    QSqlQueryModel * tri_max();
    QSqlQueryModel * tri_lieu();
    QSqlQueryModel * tri_nom();
    bool supprimer (int id);
    void notification(QString cls);
    bool modifier(int,QString,QString,QString,int,int);
    /////////////////////// Attributes //////////////////////////////
    private:
    QString nom , desc , lieu ;
    int ide ,id , max;
};

#endif // ACTIVITES_H
