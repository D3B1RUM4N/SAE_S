
#include "algos.h"

int affichage(equipements* e, lan* l)
{
    printf("adresse mac : \t");
    int i = 0;
    for(const char* mac : e->mac)
    {
        printf("%s",mac);
        if(i < 5)
        {
            printf(":");
        }
        i++;
    }
    printf("\n");
    printf("ip : \t");
    for(const char* ip : e->ip)
    {
        printf("%s", ip);
    }
    printf("\n");

    printf("priorite : %d \n", e->priorite);

    return 0;
}