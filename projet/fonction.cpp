#include <iostream>
#include <fstream>
#include "graph_reseau.h"


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
        for(int i = 0; i<l->equipement.size(); i++)
        {
            fichier << "routeurs : \n";
            //verifier si c'est un switch ou pas
            if(l->equipement[i].mac != 0)
            {
                fichier << i << ";\t";
                for(const char* mac : l->equipement[i].mac)
                {
                    fichier << "%s",mac;
                    if(i < 5)
                    {
                        fichier << ":";
                    }
                    i++;
                } 
                fichier << ";\t";
                fichier << l->equipement[i].nbPort << ";\t" << l->equipement[i].priorite << "\n";
            }
        }
        //s'occupé des stations
        fichier << "\n information sur les stations : \n";
        for(int i = 0; i<l->equipement.size(); i++)
        {
            if(l->equipement[i].mac == 0)
            {
                fichier << i << ";\t";
                for(const char* ip : l->equipement[i].ip)
                {
                    fichier << ip;
                }
            }
            fichier << "\n";
        }
            fichier.close();  // on referme le fichier
    }
    else  // sinon
            cerr << "Erreur à l'ouverture !" << endl;
}