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

struct equipement
{
    char mac[48];
    uint8_t nbPort =0;
    uint8_t priorite =0;
    vector<int> tabcom;
    int ip[32];
};

struct sommet
{
    equipement e1;
    equipement e2;
};


struct lan
{
    uint8_t nb_sommet = 0;
    vector<equipement> equipement;
};




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