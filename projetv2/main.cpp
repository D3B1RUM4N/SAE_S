#include <cstdio>
#include "algos.h"


using namespace std;
//using graphe = graphe_liste_aretes;
using equipement = equipements;
using lan = lan;

int main()
{
    lan l1;
    equipement e;


    equipement e1 = newPost();
    equipement e2 = newRouteur();
    newLan(&l1, &e1);
    newLan(&l1, &e2);
    


    //affichage dans le terminal
    affichage(&e1, &l1);
    //ecriture
    ecriture(&l1);

    

    return 0;
}