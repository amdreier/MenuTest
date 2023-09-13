#include "headerCpp.h"
#include "player.h"
#include "pages.h"

int undefinedPlayerCount = 0;


Player::Player() //defaul constructer
{
    score = 0;
    level = 1;
    cords = ORIGIN;
    name = "Player" + QString::number(undefinedPlayerCount+1);
    undefinedPlayerCount++;
};

Player::Player(int a, int b, QVector<double> c, QString d) //Constructer definition
{
    score = a;
    level = b;
    cords = c;
    name = d;

};

void Player::askName()
{
    QString newName = QInputDialog::getText(thisP, "", "What is your name?");
    cout << "What is your name?" << endl;

    name = newName;
    cout << "Now playing as: " << name.toStdString() << endl;
}


