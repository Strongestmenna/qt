#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "enseignants.h"
#include "activites.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_14_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_15_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_envoyer_2_clicked();

    void sendMail();
    void mailSent(QString) ;
private:
    Ui::MainWindow *ui;
    enseignants e;
    activites a ;
};
#endif // MAINWINDOW_H
