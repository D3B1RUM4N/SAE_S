#include "graph_reseau.h"


int affichage(equipements* e, lan* l)
{
    printf("adresse mac : \t");
    for(const char* mac : e->mac)
    {
        printf(mac);
    }
    printf("\n");
    printf("ip : \t");
    for(const char* ip : e->ip)
    {
        printf(ip);
    }
    printf("\n");

    printf("priorite : %d \n", e->priorite);

    return 0;
}