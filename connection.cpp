#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("testbd");
db.setUserName("naim");//inserer nom de l'utilisateur
db.setPassword("password");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
