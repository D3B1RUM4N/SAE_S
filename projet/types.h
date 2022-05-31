#pragma once

#include <cstdint>

using namespace std;

/*
Pour toutes les structures de graphe, on se met d'accord sur les types suivants.
Un sommet est un entier.
Une arête est une structure composée de deux sommets.
*/

using sommet = uint32_t;
struct arete
{
    sommet s1;
    sommet s2;
};
