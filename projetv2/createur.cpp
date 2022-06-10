#include <iostream>
#include <fstream>
#include "algos.h"

//creation de poste en dur
equipements newPost()
{
    equipements e;
    e.poste = true;
    //adresse mac
        e.mac[0] = "01";
        e.mac[1] = "02";
        e.mac[2] = "03";
        e.mac[3] = "04";
        e.mac[4] = "05";
        e.mac[5] = "06";
    //adresse ip
        e.ip[0] = "1";
        e.ip[1] = "2";
        e.ip[2] = "3";
        e.ip[3] = ".";
        e.ip[4] = "4";
        e.ip[5] = "5";
        e.ip[6] = ".";
        e.ip[7] = "6";
        e.ip[8] = ".";
        e.ip[9] = "7";
        e.ip[10] = "8";
        e.ip[11] = "9";
    return e;
}


//creation de routeur en dur
equipements newRouteur()
{
    equipements e;
    e.poste = false;
    //adresse mac
        e.mac[0] = "07";
        e.mac[1] = "08";
        e.mac[2] = "09";
        e.mac[3] = "a0";
        e.mac[4] = "a1";
        e.mac[5] = "a1";
    //adresse ip
        e.ip[0] = "2";
        e.ip[1] = "3";
        e.ip[2] = "4";
        e.ip[3] = ".";
        e.ip[4] = "5";
        e.ip[5] = "6";
        e.ip[6] = ".";
        e.ip[7] = "7";
        e.ip[8] = ".";
        e.ip[9] = "8";
        e.ip[10] = "9";
        e.ip[11] = "0";
    //port
    uint8_t a = 3;
    e.nbPort = a;
    //priorité
    uint8_t b = 3;
    e.priorite = b;

    return e;
}


//ajout d'equipement a une lan
void newLan(lan* l, equipements* e)
{
    l->equipement.push_back(*e);
}