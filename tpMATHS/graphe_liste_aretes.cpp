#include "graphe_liste_aretes.h"

uint32_t nb_sommets(graphe_liste_aretes* g)
{
    
    return g->nb_sommets;
}

uint32_t nb_aretes(graphe_liste_aretes* g)
{
    return g->aretes.size();
}

sommet ajouter_sommet(graphe_liste_aretes* g)
{
    g->nb_sommets ++;
    return sommet(g->nb_sommets);
}

bool ajouter_arete(graphe_liste_aretes* g, arete a)
{
    bool res = false;
    if(existe_arete(g, a))
    {
        g->aretes.push_back(a);
        res = true;
    }
    
    return res;
}
    

bool existe_arete(graphe_liste_aretes* g, arete a)
{
    bool res = true;
    for(arete x : g->aretes)
    {
        if(x.s1 == a.s1 && x.s1 == a.s2 || x.s2 == a.s1 && x.s2 == a.s2)
        {
            res = false;
        }
    }
    return res;
}

void pour_chaque_arete(graphe_liste_aretes* g, function<void(arete)> f)
{
    for(arete x : g->aretes)
    {
        f(x);
    }
}

void pour_chaque_sommet(graphe_liste_aretes* g, function<void(sommet)> f)
{
    for(arete x : g->aretes)
    {
        f(x);
    }
}

void pour_chaque_arete_incidente(graphe_liste_aretes* g, sommet s, function<void(arete)> f)
{
}

void pour_chaque_sommet_adjacent(graphe_liste_aretes* g, sommet s, function<void(sommet)> f)
{
}
