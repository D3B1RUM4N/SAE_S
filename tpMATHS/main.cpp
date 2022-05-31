#include "graphe_liste_aretes.h"

#include "algos.h"

#include <cstdio>

using namespace std;

using graphe = graphe_liste_aretes;

void p_arete(arete a)
{
    printf("%d %d\n", a.s1, a.s2);
}
void p_sommet(sommet s)
{
    printf("%d\n", s);
}

int main()
{
    graphe g;
    sommet s0 = ajouter_sommet(&g);
    sommet s1 = ajouter_sommet(&g);
    ajouter_arete(&g, {s0, s1});
    sommet s2 = ajouter_sommet(&g);
    sommet s3 = ajouter_sommet(&g);
    ajouter_arete(&g, {s2, s3});
    ajouter_arete(&g, {s1, s2});

    printf("fct\n");
    pour_chaque_arete(&g, p_arete);

    printf("fct\n");
    pour_chaque_sommet(&g, p_sommet);

    printf("AFFICHE GRAPHE\n");
    printf("==============\n");
    affiche(&g);

    printf("%d\n", nb_sommets(&g));
    printf("%d\n", nb_aretes(&g));

    return 0;
}