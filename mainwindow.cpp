#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include "terminal.h"
#include "filereader.h"
#include<QPalette>
#include <QTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel;
    ui->listView->setModel(model);
    Terminal::getInstance().setObject(ui->cmd);
    ui->cmdInput->installEventFilter(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

bool MainWindow::isInDir(QString value){
    for(int i=0;i<fr.allFilesList.size();++i)
        if(value==fr.allFilesList[i])
            return true;
    return false;
}

bool MainWindow::isInList(QString value){
    for(int i=0;i<model->rowCount();++i){
        Terminal::getInstance().writeLine(model->item(i)->accessibleText());
        if(model->item(i)->data(Qt::DisplayRole ).toString()==cmdList[1]+".txt")
            return true;
    }
    return false;
}
void MainWindow::addToList(QString value){
    QStandardItem *item;
    item = new QStandardItem();
    item->setData( value, Qt::DisplayRole );
    item->setEditable( false );
    model->appendRow( item );
    fr.currFilesList.append(value);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{  if (obj == ui->cmdInput && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *key = static_cast<QKeyEvent *>(event);
        if(key->key() == Qt::Key_Up)
        {
            if(currentCommand>0)
                ui->cmdInput->setText(commands.at(--currentCommand));
            else currentCommand=0;
        }
        else if(key->key() == Qt::Key_Down)
        {
            if(currentCommand+1<commands.size())
                    ui->cmdInput->setText(commands.at(++currentCommand));
        }
    }

    return QObject::eventFilter(obj, event);
}



void MainWindow::on_cmdInput_returnPressed()
{
    QString cmdIN = ui->cmdInput->text();
    cmdList = cmdIN.split(QRegExp("\\s+"));
    Terminal::getInstance().writeLine(cmdIN);
    if(cmdList[0]=="add"){
        if(cmdList[1]=="all")
            for(int i=0;i<fr.allFilesList.length();i++)
                addToList(fr.allFilesList[i]);
        else if(isInDir(cmdList[1]+".txt")){
            if(isInList(cmdList[1]+".txt"))
                Terminal::getInstance().writeLine("file currently exists in specified directory");
            else{
                addToList(cmdList[1]+".txt");
                if(ui->bstRB->isChecked()){
                    if(ui->avlCheck->isChecked())
                        fr.addDelFileinBst(cmdList[1],2);
                    else
                        fr.addDelFileinBst(cmdList[1],0);
                }
                else if(ui->tstRB->isChecked()){
                    if(ui->avlCheck->isChecked())
                        fr.addDelFileinTst(cmdList[1],2);
                    else
                        fr.addDelFileinTst(cmdList[1],0);
                }
                else if(ui->tRB->isChecked())
                    fr.addDelFileinTrie(cmdList[1],0);
                else if(ui->hashRb->isChecked())
                    fr.addDelFileinHash(cmdList[1],0);

            }

        }

        else
            Terminal::getInstance().writeLine("file does not exist in specified directory");
    }
    else if(cmdList[0]=="list"){
        if(cmdList[1]=="-w"){
            if(ui->bstRB->isChecked()){
                if(ui->avlCheck->isChecked())
                    fr.avlBstFile.inorderTraverse(fr.avlBstFile.root);
                else
                    fr.bstFile.inorderTraverse(fr.bstFile.root);
            }
            else if(ui->tstRB->isChecked()){
                if(ui->avlCheck->isChecked())
                    fr.avlTstFile.inorderTraverse(fr.avlTstFile.root);
                else
                    fr.tstFile.inorderTraverse(fr.tstFile.root);
            }
            else if(ui->tRB->isChecked())
                 fr.tFile.inorderTraverse(fr.tFile.root);
        }
        else if(cmdList[1]=="-f")
            for(int i=0;i<fr.allFilesList.size();i++)
                Terminal::getInstance().writeLine(fr.allFilesList[i]);

    }
    else if(cmdList[0]=="del"){
        for(int i=0;i<model->rowCount();++i){
            Terminal::getInstance().writeLine(model->item(i)->accessibleText());
            if(cmdList[1]=="all")
                model->removeRow(i);
            else if(model->item(i)->data(Qt::DisplayRole ).toString()==cmdList[1]+".txt"){
                model->removeRow(i);
                if(ui->bstRB->isChecked()){
                    if(ui->avlCheck->isChecked())
                        fr.addDelFileinBst(cmdList[1],3);
                    else
                        fr.addDelFileinBst(cmdList[1],1);
                }
                else if(ui->tstRB->isChecked()){
                    if(ui->avlCheck->isChecked())

                        fr.addDelFileinTst(cmdList[1],3);
                    else
                        fr.addDelFileinTst(cmdList[1],1);
                }/**/
                else if(ui->tRB->isChecked())
                    fr.addDelFileinTrie(cmdList[1],1);
                else if(ui->hashRb->isChecked())
                    fr.addDelFileinHash(cmdList[1],1);
            }
        }
    }
    else if(cmdList[0]=="update"){
        for(int i=0;i<model->rowCount();++i){
            Terminal::getInstance().writeLine(model->item(i)->accessibleText());
            if(model->item(i)->data(Qt::DisplayRole ).toString()==cmdList[1]+".txt"){
                if(ui->bstRB->isChecked()){
                    if(ui->avlCheck->isChecked()){
                        fr.addDelFileinBst(cmdList[1],3);
                        fr.addDelFileinBst(cmdList[1],2);
                    }
                    else{
                        fr.addDelFileinBst(cmdList[1],1);
                        fr.addDelFileinBst(cmdList[1],0);
                        }
                }
                else if(ui->tstRB->isChecked()){
                    if(ui->avlCheck->isChecked()){
                        fr.addDelFileinTst(cmdList[1],3);
                        fr.addDelFileinTst(cmdList[1],2);
                    }
                    else{
                        fr.addDelFileinTst(cmdList[1],1);
                        fr.addDelFileinTst(cmdList[1],0);
                    }
                }/**/
            }
        }
    }
    else if(cmdList[0]=="search"){
        if(ui->bstRB->isChecked()){
            if(fr.bstFile.root!=0){
                if(fr.bstFile.search(cmdList[1].toStdString()))
                    Terminal::getInstance().writeLine("word exists!");
                for (int i = 0; i < model->rowCount(); ++i) {
                    model->item(i)->setEnabled(false);
                    if (fr.bstFile.searchN(fr.bstFile.root,cmdList[1].toStdString())->occur.contains(model->item(i)->data(Qt::DisplayRole ).toString())) {
                        model->item(i)->setEnabled(true);
                    }
                }
            }
        }
        else if(ui->tstRB->isChecked())
            if(fr.tstFile.root!=0)
            {if(fr.bstFile.search(cmdList[1].toStdString()))
                    Terminal::getInstance().writeLine("file exists!");
            }
            else if(ui->tRB->isChecked())
                    if(fr.tFile.root!=0)
                        if(fr.bstFile.search(cmdList[1].toStdString()))
                            Terminal::getInstance().writeLine("file exists!");;
    }
        else
             Terminal::getInstance().writeError("file is Not on the list");
    commands.push_back(cmdIN);
    currentCommand=commands.size();
    ui->cmdInput->setText("");

}

void MainWindow::on_BrowseB_clicked(){
    fr.dirPath=QFileDialog::getExistingDirectory(this,"select the directory which you want to operate");
    if(!fr.dirPath.isEmpty()){
        QDir directory(fr.dirPath);
        fr.allFilesList=directory.entryList(QDir::Files,QDir::SortFlag::Name);
        ui->DirectoryA->setText(fr.dirPath);
//        for(int i=0;i<filesList.size();++i)
//            addToList(filesList[i]);
    }

}
void MainWindow::on_StopWordB_clicked(){
     QString stopWordPath;
     stopWordPath = QFileDialog::getOpenFileName(this, tr("Specify StopWords Address"), QDir::homePath(), tr("Text Files (*.txt)"));
     if(!stopWordPath.isEmpty()){
         ui->StopWordA->setText(stopWordPath);
        fr.getStopWords(stopWordPath);
        fr.swInTrees();
     }
}


void MainWindow::on_pushButton_clicked()
{
    QTime t;
    if(fr.filesText.empty())
        fr.fileAdder();
    t.start();
    if(!ui->avlCheck->isChecked()){
    if(ui->bstRB->isChecked())
        fr.fileInBst();
    else if(ui->tstRB->isChecked())
        fr.fileInTst();
    else if(ui->tRB->isChecked())
        fr.fileInTrie();
    else
        Terminal::getInstance().writeLine("select a tree");
    }
    else{
        if(ui->bstRB->isChecked())
            fr.fileInAvlBst();
        else if(ui->tstRB->isChecked())
            fr.fileInAvlTst();
    }
    if(ui->bstRB->isChecked() || ui->tstRB->isChecked() || ui->tRB->isChecked())
    Terminal::getInstance().writeLine("the tree was built in "+QString::number(t.elapsed())+" mSeconds");
}




void MainWindow::on_tRB_toggled(bool checked)
{
    ui->avlCheck->setCheckable(!ui->avlCheck->isCheckable());
}
