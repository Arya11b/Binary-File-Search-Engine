#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <vector>
#include<filereader.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_BrowseB_clicked();

    void on_StopWordB_clicked();

    bool eventFilter(QObject *obj, QEvent *event);
    void on_cmdInput_returnPressed();

    void on_pushButton_clicked();
    void currentFiles();

    void on_bstRB_clicked();

    void on_tstRB_clicked();
    
    void on_bstRB_toggled(bool checked);

    void on_tRB_toggled(bool checked);

private:
    FileReader fr;
    QStringList cmdList;
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    void addToList(QString value);
    bool isInDir(QString value);
    bool isInList(QString value);
//    QStringList filesList;
//    QString dirPath;
    std::vector<QString> commands;
    int currentCommand=0;
};

#endif // MAINWINDOW_H
