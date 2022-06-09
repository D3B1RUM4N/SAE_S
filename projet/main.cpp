#include <cstdio>
#include "graph_reseau.h"


using namespace std;
//using graphe = graphe_liste_aretes;
using equipement = equipements;
using lan = lan;

int main()
{
    lan l;
    equipement e;

    //affichage dans le terminal
    affichage(&e, &l);
    //ecriture
    ecriture(&l);

    return 0;
}