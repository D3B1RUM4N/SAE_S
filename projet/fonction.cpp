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
        fichier << "routeurs : \n";
        for(int i = 0; i<l->equipement.size(); i++)
        {
            
            //verifier si c'est un switch ou pas
            if(!l->equipement[i].poste)
            {
                printf("if 1");
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
                printf("if 2");
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

equipements newRouteur()
{
    equipements e;
    e.poste = false;
    //adresse mac
        e.mac[0] = "07";
        e.mac[1] = "08";
        e.mac[2] = "09";
        e.mac[3] = "a0";
        e.mac[4] = "a1";
        e.mac[5] = "a1";
    //adresse ip
        e.ip[0] = "2";
        e.ip[1] = "3";
        e.ip[2] = "4";
        e.ip[3] = ".";
        e.ip[4] = "5";
        e.ip[5] = "6";
        e.ip[6] = ".";
        e.ip[7] = "7";
        e.ip[8] = ".";
        e.ip[9] = "8";
        e.ip[10] = "9";
        e.ip[11] = "0";
    //port
    uint8_t a = 3;
    e.nbPort = a;
    //priorité
    uint8_t b = 3;
    e.priorite = b;

    return e;
}

void newLan(lan* l, equipements* e)
{
    l->equipement.push_back(*e);
}
