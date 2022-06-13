#include "algos.h"

#include <string.h>
#include <iostream>
#include <fstream>
 
using namespace std;
 
void lecture(lan* l)
{
    ifstream fichier("text.txt", ios::in);  // on ouvre le fichier en lecture

    if(fichier)  // si l'ouverture a réussi
    {       
        int i = 0;
        string ligne;

        const char * separators = ";";
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            //cout << ligne << endl;  // on l'affiche
            printf("%s \n", ligne.c_str());

            if(i > 0)
            {
                char * strToken = strtok ( (char*)ligne.c_str(), separators );

                printf("longueure : %ld\t",strlen(strToken));
                printf("val %s \n", strToken);
                for(int j; j < strlen(strToken); j++)
                {
                    printf("strToken : %s \n", strToken);
                    if(strToken[j]=='1')
                    {
                        ajouterPost(l, ligne);
                    }    
                }

            }
            i++;
        }
        // instructions
            fichier.close();  // on ferme le fichier
    }
    else  // sinon
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}


void ajouterPost(lan* l, string ligne)
{
    const char * separators = ";";
    const char * separator = ":";
    const char * separatr = ".";
    char * strToken = strtok ( (char*)ligne.c_str(), separators );
    int i = 0;
    while ( strToken != NULL ) 
    {
        if(i == 1)
        {
            printf("ip : %s \n", strToken);
        }
        if(i == 2)
        {
            printf("mac : %s", strToken);
        }
        i++;
        strToken = strtok ( NULL, separators );
    }
}
