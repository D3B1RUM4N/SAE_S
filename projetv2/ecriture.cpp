#include <iostream>
#include <fstream>
#include "algos.h"

void ecriture(lan* l) 
{
    vector<equipements> e = l->equipement;
    ofstream fichier("text.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
    
    if(fichier)  // si l'ouverture a réussi
    {
        fichier << l->equipement.size() << " " << l->liens.size() << "\n";
        for(equipements e : l->equipement)
        {
            if(e.poste)
            {
                int i = 0;
                fichier << "1;";
                char *resMAC = (char *)calloc(20, sizeof(char));
                for(unsigned char mac : e.mac)
                {
                    sprintf(resMAC, "%d", mac);
                    fichier << resMAC;
                    if(i < 5)
                    {
                        fichier << ":";
                    }
                    i++;
                }
                free(resMAC);

                fichier << ";";
                char *resIP = (char *)calloc(20, sizeof(char));
                i=0;
                for(int y = 0; y < 4; y++)
                {
                    sprintf(resIP, "%d", e.ip[y]);
                    fichier << resIP;
                    if(i < 3)
                    {
                        fichier <<".";
                    }
                    i++;
                }
                free(resIP);
                fichier << ";" << e.index << "\n";
            }
            else
            {
                int i = 0;
                fichier << "2;";
                char *resMac = (char *)calloc(20, sizeof(char));
                for(unsigned char mac : e.mac)
                {
                    
                    sprintf(resMac, "%d", mac);
                    fichier << resMac;
                    if(i < 5)
                    {
                        fichier << ":";
                    }
                    i++;
                }
                free(resMac);
                char *res = (char *)calloc(20, sizeof(char));
                sprintf(res, ";%d;%d;%d \n", e.nbPort, e.priorite, e.index);
                fichier << res;
                free(res);
                //fichier << ";" << e.nbPort << ";" << e.priorite << "\n";
            }

            for(lien s : l->liens)
            {
                char *resLien = (char *)calloc(20, sizeof(char));
                sprintf(resLien, "%d;%d;%d", s.indexe1,s.indexe2,s.poid);
                fichier << resLien << "\n";
                free(resLien);
            }
        }

            fichier.close();  // on referme le fichier
    }
    else  // sinon
            cerr << "Erreur à l'ouverture !" << endl;
}
