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
                printf("if 1");
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
        fichier << "\ninformation sur les stations : \n";
        for(int i = 0; i<l->equipement.size(); i++)
        {
            //if(l->equipement[i].mac == 0)
            if(true)
            {
                printf("if 2");
                fichier << i << ";\t";
                for(const char* ip : l->equipement[i].ip)
                {
                    fichier << ip << ";\t";
                    for(const char* mac : l->equipement[i].mac)
                    {
                        fichier << "%s",mac;
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


equipements newPost()
{
    equipements e;
    e.poste = true;
    //adresse mac
        e.mac[0] = "01";
        e.mac[1] = "02";
        e.mac[2] = "03";
        e.mac[3] = "04";
        e.mac[4] = "05";
        e.mac[5] = "06";
    //adresse ip
        e.ip[0] = "1";
        e.ip[1] = "2";
        e.ip[2] = "3";
        e.ip[3] = ".";
        e.ip[4] = "4";
        e.ip[5] = "5";
        e.ip[6] = ".";
        e.ip[7] = "6";
        e.ip[8] = ".";
        e.ip[9] = "7";
        e.ip[10] = "8";
        e.ip[11] = "9";
    return e;
}