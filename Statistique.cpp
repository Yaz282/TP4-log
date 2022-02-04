/*************************************************************************
                           Statistique  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Statistique> (fichier Statistique.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Statistique.h"
#include <map>
#include <vector>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Lecture::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool Statistique::sortbysecdesc(const pair<string,int> &a, const pair<string,int> &b)
{
    return a.second>b.second;
}

void Statistique::Ajouter ( Lecture & livre)
{
    string dest = livre.ligne.getDestUrl();
    string referer = livre.ligne.getReferer();

    /*Dico::iterator itr = carte.find(dest);
    if(itr!=carte.end())
    {
        map<string, int>::iterator ptr;
        bool present = false;
        for (ptr = itr->second.first.begin(); ptr != itr->second.first.end(); ptr++) {

           if(ptr->first==referer)
           {
                present = true;
                (ptr->second) = (ptr->second) +1;
                (itr->second.second) = (itr->second.second) +1;
                break;
           }
        }
        if(present==false)
        {
            int somme = (itr->second.second) +1;
            //carte[dest].first.insert(make_pair(referer,1));
            //carte[dest].second=somme;
        }
       
    } else {
        carte.insert( make_pair(dest,make_pair(make_pair(referer,1),1)));
    }*/

    Dico::iterator itr = carte.find(dest);
    if(itr!=carte.end()) 
    {
        map<string, int>::iterator ptr;
        bool present = false;

        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            if(ptr->first == referer) {
                ptr->second = ptr->second + 1;
                present = true;
                break;
            }
        }

        if (present == false) {
            carte[dest].insert(make_pair(referer, 1));
        }

        Cons::iterator itr = consultation.find(dest);
        itr->second = itr->second + 1;

    } else {

        carte.insert(make_pair(dest, map<string, int>()));
        carte[dest].insert(make_pair(referer, 1));
        consultation.insert(make_pair(dest,1));
    }
}

void Statistique::Afficher()
{
    map<string, map<string, int> >::iterator itr;   // For accessing outer map
    map<string, int>::iterator ptr;                // For accessing inner map

    for (itr = carte.begin(); itr != carte.end(); itr++) {
  
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            cout << "La cible est " << itr->first
                 << " et le referer est " << ptr->first
                 << " et le nombre de hit est " << ptr->second << endl;
        }
    }
}

/*bool Statistique::sortbysecdesc(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.second>b.second;
}*/

void Statistique::Top()
{
   /*sort(consultation.begin(), consultation.end(), sortbysecdesc);

   Cons::iterator itr = consultation.begin();
   int compteur = 0;
   while( itr!=consultation.end() && compteur<10)
   {
        cout << itr->first <<" (" << itr->second <<" hits)" << endl;
        ++itr;
   }*/

    vector<std::pair<string, int> > arr;
    /*for (const auto &item : consultation) {
        arr.emplace_back(item);
    }*/
    map<string, int>::iterator itr;
    for (itr = consultation.begin(); itr != consultation.end(); itr++)
    {
        arr.push_back(make_pair(itr->first,itr->second));
    }

    //sort(arr.begin(), arr.end(), [] ( const pair<string,int> &a, const pair<string,int> &b) { return a.second>b.second; });
    sort(arr.begin(), arr.end(), sortbysecdesc);

    int compteur=0;
    while(compteur<arr.size() && compteur<10)
    {
        cout << arr[compteur].first <<" (" << arr[compteur].second <<" hits)" << endl;
        compteur++;
    }
}

//------------------------------------------------- Surcharge d'opérateurs
/*Statistique & Statistique::operator = ( const Statistique & unStatistique )
// Algorithme :
//
{
} //----- Fin de operator =
*/


//-------------------------------------------- Constructeurs - destructeur
Statistique::Statistique ( const Statistique & unStatistique )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Lecture (constructeur de copie)


Statistique::Statistique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Statistique>" << endl;
#endif
} //----- Fin de Statistique


Statistique::~Statistique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Statistique>" << endl;
#endif
} //----- Fin de ~Statistique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

