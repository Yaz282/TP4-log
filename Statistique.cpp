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
#include <algorithm>

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
    if(a.second==b.second)
    {
        return a.first<b.first;
    } else {
        return a.second>b.second;
    }
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

void Statistique::Top()
{
   
    vector<std::pair<string, int> > arr;
    
    map<string, int>::iterator itr;
    for (itr = consultation.begin(); itr != consultation.end(); itr++)
    {
        arr.push_back(make_pair(itr->first,itr->second));
    }

    sort(arr.begin(), arr.end(), sortbysecdesc);

    int compteur=0;
    while(compteur<arr.size() && compteur<10)
    {
        cout << arr[compteur].first <<" (" << arr[compteur].second <<" hits)" << endl;
        compteur++;
    }
}

void Statistique::Graphe(string nomFichier)
{

    Dico::iterator itr;   // For accessing outer map
    Cons::iterator ptr;   // For accessing inner map
    Cons graphe;
    int compteur=0;

    //on remplit le graphe avec les cibles et les referer
    for (itr = carte.begin(); itr != carte.end(); itr++) {
        graphe.insert(make_pair(itr->first,compteur));
        compteur++;
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            graphe.insert(make_pair(ptr->first,compteur));
            compteur++;
        }
    }

    ofstream file (nomFichier); //ouverture du fichier nomFichier
    streambuf *oldCoutBuffer = cout.rdbuf ( file.rdbuf ( ) ); //redirection du streambuffer
    if(!file) //teste si le fichier n'a pas pu s'ouvrir
    {
        cout <<"Erreur ouverture fichier"<<endl;
    } else {
        cout <<"digraph {" << endl;

        Cons::iterator ctr;

        //affichage des noeuds
        for (ctr = graphe.begin(); ctr != graphe.end(); ctr++) {
            cout << "node" << ctr->second << " [label=\"" << ctr->first << " \"];" << endl;
        }
        
        //affichage des arcs
        for (itr = carte.begin(); itr != carte.end(); itr++) {
            for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
                
                ctr=graphe.find(ptr->first);
                cout << "node"<<ctr->second;
                ctr=graphe.find(itr->first);
                cout <<" -> node" <<ctr->second <<" [label= " <<ptr->second <<" ];" <<endl;
            }
        }
        cout << "}" << endl;

    }

    cout.rdbuf ( oldCoutBuffer ); // Restauration du stream buffer par défaut pour cout 
    file.close(); //Fermeture de nomFichier
}

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

