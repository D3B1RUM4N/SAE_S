#pragma once

#include "types.h"
#include <vector>
#include <cassert>
#include <functional>

/*
On stocke le nombre de sommets (nb_sommets).
On stocke un tableau (vector) d'arêtes (couple d'index de sommet).
Pour plus de commodité, on stockera toujours les arêtes en respectant s1 < s2.
*/

struct graphe_liste_aretes
{
    uint32_t nb_sommets = 0;
    vector<arete> aretes;
};

uint32_t nb_sommets(graphe_liste_aretes *g);
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
