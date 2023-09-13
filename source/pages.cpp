#include "headerCpp.h"
#include "pages.h"


QMainWindow* thisP2;
int testIt = 0;
bool playing = true;
int character = 0;


Page::Page() //defeaul constructor
{
    string prompt = "Pick one:";
    options.push_back("Exit");
    funcNum = 0;
    dynamic = false;
};

Page::Page(QString newPrompt, QVector<QString> newOptions, QVector<QString> newOptions2, QVector<QString> newOptions3, int newFuncNum, bool newDynamic, int newColumnNum, QVector<QString> newHeaders, bool newInput) //overloaded constructor
{
    prompt = newPrompt;
    options = newOptions;
    options2 = newOptions2;
    options3 = newOptions3;
    funcNum = newFuncNum;
    dynamic = newDynamic;
    columnNum = newColumnNum;
    headers = newHeaders;
    input = newInput;

};


void Page::display(MyModel& myModel) //iterate through options vector to print in format
{


    if(dynamic)
    {
        int vecLen1 = players.size();
        options = emptyVec;
        for(int i = 0; i < vecLen1; i++) //copies player names into character select options vector
        {
            options.push_back("");
            options[i] = players[i].getName();
            options2.push_back("");
            options2[i] = QString::number(players[i].getLevel());
            options3.push_back("");
            options3[i] = QString::number(players[i].getScore());
            while(options.size() < options2.size())
            {
                options2.pop_back();
            }
            while(options.size() < options3.size())
            {
                options3.pop_back();
            }
        }
    }

    int vecLen = options.size();

    cout << prompt.toStdString() << endl;

    if(options2.empty())
    {
        for(int i = 0; i < vecLen; i++)
        {
            options2.push_back("");
        }
    }

    if(options3.empty())
    {
        for(int i = 0; i < vecLen; i++)
        {
            options3.push_back("");
        }
    }


 modelMap.clear();
 modelMap.push_back(options);
 modelMap.push_back(options2);
 modelMap.push_back(options3);

/*  OLD DISP FUNC
    for(int i = 0; i < vecLen; i++)
    {
        cout << i << " - " << options[i] << " " << options2[i] << " " << options3[i] << endl;
    }
*/



myModel.rows = vecLen;
myModel.columns = columnNum;

cout << page << endl;
cout << funcNum << endl;





 //tableView->setModel(&myModel);

 //cout << tableView << endl;



};

int Page::doFunc(QModelIndex index) //does page funct and returns next page
{


    if(funcNum == 0) //exit function
    {
        playing = false;
        return 1;
    } else if(funcNum == 1) //select page from menu
    {
        return index.row() + 1;
    } else if(funcNum == 2) //select character
    {
        int newCharacter;
        newCharacter = index.row();
        if(newCharacter != character)
        {
            character = newCharacter;
            cout << "Now playing as: " << players[character].getName().toStdString() << endl;
        } else
        {
            cout << "Still playing as: " << players[character].getName().toStdString() << endl;
        }

        return 0; // return to menu
    } else if(funcNum == 3) //create character
    {
        createPlayer(players);
        character = players.size() - 1;
        return 0; //return to menu
    } else if(funcNum == 4) // edit name
    {
        cout << "test" << endl;
        QString newName;
        newName = QInputDialog::getText(thisP, "", prompt);
        players[character].setName(newName);

        cout << "Now playing as: " << players[character].getName().toStdString() << endl;
        return 0; //return menu
    } else if(funcNum == 5) //add to character score
    {
        int scoreAdded;
        scoreAdded = QInputDialog::getInt(thisP, "", prompt);
        players[character].setScore(players[character].getScore() + scoreAdded);
        return 0; //return to menu
    }

    else {return 0;}

};


QString Page::getPrompt()
{
    return prompt;
}

/*
Page::~Page()
{
    delete tableView;
};
*/
