#include "terminal.h"
#include <iostream>

Terminal::Terminal()
{

}

Terminal& Terminal::getInstance()
{
    static Terminal instance;
    return instance;
}


void Terminal::writeLine(QString line){
    terminalOutput->appendPlainText(">>  "+line);
}
void Terminal::writeWord(std::string sline){
    QString line = QString::fromStdString(sline);
    terminalOutput->appendPlainText(line);
}

void Terminal::setObject(QPlainTextEdit *terminalOutput){
    this->terminalOutput = terminalOutput;
}

void Terminal::writeError(QString line){
    writeLine(line);
}

