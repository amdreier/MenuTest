#ifndef PAGES_H
#define PAGES_H

#include "player.h"
#include "headerCpp.h"
#include "mymodel.h"
#include "QLabel"
#include "QMainWindow"

void createPlayer(QVector<Player>&);
int selection(int);
void options(int);

extern QMainWindow* thisP;
extern bool playing;
extern QVector<Player> players;
extern int character;
extern QVector<QString> emptyVec;
extern QVector<QVector<QString>> modelMap;
extern int page;

class Page
{
    QString prompt;
    QVector<QString> options;
    QVector<QString> options2;
    QVector<QString> options3;
    int funcNum;
    bool dynamic;
    QTableView* tableView = new QTableView;
    int columnNum;



    public:
        Page();  //default constructor
        Page(QString prompt, QVector<QString> newOptions, QVector<QString> newOptions2, QVector<QString> newOptions3, int newFuncNum, bool dynamic, int newColumnNum, QVector<QString> newHeaders, bool newInput); //overloaded constructor
        //~Page();


        //METHODS

        void display(MyModel&); //to display vector contents
        int doFunc(QModelIndex index); //gets user input and does page functionality
        QVector<QString> headers;
        QString getPrompt();
        bool input;

};

extern QVector<Page> pages;

#endif // PAGES_H
