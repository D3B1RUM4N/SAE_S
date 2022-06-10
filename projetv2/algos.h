#pragma once

#include <vector>
#include <cassert>
#include <functional>
#include "string.h"


/*
On stocke le nombre de sommets (nb_sommets).
On stocke un tableau (vector) d'arêtes (couple d'index de sommet).
Pour plus de commodité, on stockera toujours les arêtes en respectant s1 < s2.
*/

/*
On stocke une station (stations).
On stocke un tableau (int) d'adresse mac.
On stocke également un tableau (int) de l'adresse ip.
*/


/* 
Un equipementpeut etre un switch ou une stattio
La difference serra faite via l'adresse IP
une station en a une alors qu'un switch non.
*/

struct equipements
{
    bool poste;
    const char* mac[6]; //= {"55", "3a", "c2", "69", "21", "d2" };
    uint8_t nbPort; //=5;
    uint8_t priorite; //=1;
    vector<int> tabcom;
    const char* ip[12]; //= {"1", "3", "0", ".", "7", "9", ".", "0", ".", "1", "2", "6"};
};

struct lien
{
    equipements e1;
    equipements e2;
    uint8_t poid = 100;
};


//using liens = uint32_t;
struct lan
{
    vector<lien> liens;
    vector<equipements> equipement;
};


int affichage(equipements* e, lan* l);
void ecriture(lan* l);
equipements newPost();
equipements newRouteur();
void newLan(lan* l, equipements* e);

