#ifndef PLAYER_H
#define PLAYER_H

#include "headerCpp.h"

const QVector<double> ORIGIN(3, 0);

class Player
{
    int score, level;
    QString name;
    QVector<double> cords;


 public:

    Player(); //defaul constructor
    Player(int, int, QVector<double>, QString); //overloaded constructor


    /*      GETTERS     */
    int getScore() {return score;}; //get score
    QVector<double> getCords() {return cords;}; //get cords vect
    int getLevel() {return level;}; //gets level
    double getCord(int i) {return cords[i];}; //get cord x y z
    QString formatCords() // gets string of cords like {x, y, z}
    {
        QString str1;
        QString formattedCords = "{";
        for(int i = 0; i < cords.size()-1; i++)
        {
            QString str2 = QString::number(cords[i]) + ", ";

           formattedCords = formattedCords + str2;
        }
        QString str2 = QString::number(cords[cords.size()-1]) + "}";
        formattedCords = formattedCords + str2 + "\n";

        return formattedCords;
    }

    QString getName() {return name;}; // get name

    /*     SETTERS      */
    void setScore(int newScore) {score = newScore;}; //set score
    void setCords(QVector<double> newCords) {cords = newCords;}; //set cord vector
    void setCord(int i, double newCord) {cords[i] = newCord;};   //set cords x y z
    void setName(QString newName) {name = newName;}; //set name
    void setLevel(int newLevel) {level = newLevel;}; //set level

    /*      METHODS      */
    void askName(); //Ask and set name

};
#endif // PLAYER_H
