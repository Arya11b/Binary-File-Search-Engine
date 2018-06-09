#ifndef TERMINAL_H
#define TERMINAL_H
#include<QString>
#include <QPlainTextEdit>
#include<QKeyEvent>
class Terminal
{
public:
    Terminal();
    QPlainTextEdit *terminalOutput;
    QString terminalInput;
    static Terminal &getInstance();
    void writeLine(QString line);
    void writeWord(std::string sline);
    void writeError(QString line);
    void setObject(QPlainTextEdit *terminalOutput);
    void getInput();
};

#endif // TERMINAL_H
