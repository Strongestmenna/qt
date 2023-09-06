#ifndef ENSEIGNANTS_H
#define ENSEIGNANTS_H
#include <QString>
#include <QSqlQueryModel>


class enseignants
{
public:
    enseignants();
    enseignants(QString,QString,QString,QString,QString,int);

    QString getnom();
    QString getprenom();
    QString getemail ();
    QString getstreet();
    QString getgenre();
    int getage ();
    int getid();
    ////////////////////////////// Getter & Setter //////////////////////
    void setnom (QString);
    void setprenom (QString);
    void setemail (QString);
    void setstreet(QString);
    void setgenre(QString);
    void setage(int);
    /////////////////////////////// CRUD ///////////////////////////////
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel * tri();
    QSqlQueryModel * tri_age();
    QSqlQueryModel * tri_nom();
    QSqlQueryModel * tri_prenom();
    bool supprimer (int id);
    bool modifier(int,QString,QString,QString,QString,QString,int);
    /////////////////////// Attributes //////////////////////////////
    private:
    QString nom , prenom , email , street, genre;
    int age ,id ;

};

#endif // ENSEIGNANTS_H
