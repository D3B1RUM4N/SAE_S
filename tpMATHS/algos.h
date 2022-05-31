#pragma once

#include <cstdio>
#include <vector>
#include <limits>

using namespace std;

template <typename GRAPHE>
void affiche(GRAPHE* g)
{
    printf("Youpi \\o/\n");
}

template <typename GRAPHE>
uint32_t degre(GRAPHE* g, sommet s)
{
    return 0;
}

template <typename GRAPHE>
bool est_regulier(GRAPHE* g)
{
    return true;
}

template <typename GRAPHE>
GRAPHE generer_complet(uint32_t ordre)
{
    GRAPHE g;
    return g;
}
