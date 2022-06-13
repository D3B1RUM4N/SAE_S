#include <iostream>
#include <fstream>
#include "algos.h"
#include <vector>
using namespace std;

//creation de poste en dur
equipements newPost()
{
    equipements e;
    e.poste = true;
    //adresse mac
    
    addMac mac = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
    for(size_t i=0 ; i < 6; i++)
    {
        e.mac[i] = mac[i];
    }
    ipv4 ip = {10, 0, 2, 15};
    for(int i = 0; i<4 ; i++)
    {
        e.ip[i] = ip[i];
    }
    return e;
}


//creation de routeur en dur
equipements newRouteur()
{
    equipements e;
    e.poste = false;
        //adresse mac
    
    addMac mac = {0x11, 0x12, 0x13, 0x14, 0x15, 0x06};
    for(size_t i=0 ; i < 6; i++)
    {
        e.mac[i] = mac[i];
    }
    ipv4 ip = {11, 1, 3, 16};
    for(int i = 0; i<4 ; i++)
    {
        e.ip[i] = ip[i];
    }
    //port
    uint8_t a = 3;
    e.nbPort = a;
    //priorité
    uint8_t b = 3;
    e.priorite = b;
    e.index = 0;

    return e;
}


//ajout d'equipement a une lan
void newLan(lan* l, equipements* e)
{
    e->index = l->equipement.size() +1;
    //printf("index equipement %d \n", e->index);
    l->equipement.push_back(*e);
}


bool ajouterLien(lan* l, lien s)
{
    s.indexe1 = s.e1.index;
    s.indexe2 = s.e2.index;
    bool res = false;
    uint8_t poid = 100;
    if(!existeLien(l, s))
    {
        l->liens.push_back({s.e1, s.e2, s.e1.index, s.e2.index, poid});
        res = true;
    }
    
    return res;
}
    

bool existeLien(lan* l, lien a)
{
    bool res = false;
    //printf("size %ld \n", l->liens.size());
    for(lien x : l->liens)
    {
        //printf("AVANT LE IF index e1 %d index e2 %d index x1 %d index x2 %d \n", a.indexe1, a.indexe2, x.indexe1, x.indexe2);
        if(x.indexe1 == a.indexe1 && x.indexe2 == a.indexe2 || x.indexe2 == a.indexe1 && x.indexe1 == a.indexe2)
        {
            //printf("index e1 %d index e2 %d index x1 %d index x2 %d \n", a.indexe1, x.indexe2, x.indexe1, x.indexe2);
            res = true;
        }
    }
    return res;
} 