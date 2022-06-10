#include <iostream>
#include <fstream>
#include "algos.h"

void ecriture(lan* l) 
{
    vector<equipements> e = l->equipement;
    ofstream fichier("test.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
    
    if(fichier)  // si l'ouverture a réussi
    {
        // instructions
        fichier << l->equipement.size() << "\t" << l->liens.size() << " \n";

        fichier << "Information sur la lan : \n";
        //ecriture des routeurs
        fichier << "routeurs : \n";
        for(int i = 0; i<l->equipement.size(); i++)
        {
            
            //verifier si c'est un switch ou pas
            if(!l->equipement[i].poste)
            {
                //printf("if 1");
                fichier << i << ";\t";
                for(const char* mac : l->equipement[i].mac)
                {
                    fichier << mac;
                    if(i < 5)
                    {
                        fichier << ":";
                    }
                    i++;
                } 
                fichier << ";\t";
                char s[2];
                fichier << sprintf(s, "%d", l->equipement[i].nbPort) << ";\t" << l->equipement[i].priorite << "\n";
            }
        }
        //s'occupé des stations
        fichier << "\ninformation sur les stations : \n";
        for(int i = 0; i<l->equipement.size(); i++)
        {
            //if(l->equipement[i].mac == 0)
            if(l->equipement[i].poste)
            {
                //printf("if 2");
                fichier << i << ";\t";
                for(const char* ip : l->equipement[i].ip)
                {
                    fichier << ip << ";\t";
                    for(const char* mac : l->equipement[i].mac)
                    {
                        fichier << mac;
                        if(i < 5)
                        {
                            fichier << ":";
                        }
                        i++;
                    } 
                    fichier << "\n";
                }
            }
            fichier << "\n";
        }
            fichier.close();  // on referme le fichier
    }
    else  // sinon
            cerr << "Erreur à l'ouverture !" << endl;
}
