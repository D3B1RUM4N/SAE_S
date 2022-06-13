
#include "algos.h"





int affichage(equipements* e, lan* l)
{
    printf("adresse mac : \t");
    int i = 0;
    for(unsigned char mac : e->mac)
    {
        printf("%hhx",mac);
        if(i < 5)
        {
            printf(":");
        }
        i++;
    }
    printf("\n");
    printf("ip : \t");
    i=0;
    for(unsigned char ip : e->ip)
    {
        printf("%d", ip);
        if(i < 3)
        {
            printf(".");
        }
        i++;
    }
    printf("\n");

    printf("priorite : %d \n", e->priorite);

    return 0;
}