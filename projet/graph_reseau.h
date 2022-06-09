#pragma once

#include "types.h"
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








/* uint32_t nb_sommets(graphe_liste_aretes *g);
uint32_t nb_aretes(graphe_liste_aretes *g);

sommet ajouter_sommet(graphe_liste_aretes *g);
bool existe_arete(graphe_liste_aretes *g, arete a);
// La fonction ajouter_arete n'ajoute l'arête que si elle n'existe pas déjà dans le graphe
// et si elle connecte deux sommets distincts.
// Elle retourne un booléen indiquant si l'arête a été ajoutée ou non.
bool ajouter_arete(graphe_liste_aretes *g, arete a);

void pour_chaque_arete(graphe_liste_aretes *g, function<void(arete)> f);
void pour_chaque_sommet(graphe_liste_aretes *g, function<void(sommet)> f);
void pour_chaque_arete_incidente(graphe_liste_aretes *g, sommet s, function<void(arete)> f);
void pour_chaque_sommet_adjacent(graphe_liste_aretes *g, sommet s, function<void(sommet)> f);
 */