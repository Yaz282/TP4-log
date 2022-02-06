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

bool Statistique::sortbysecdesc(const pair<string,int> &a, const pair<string,int> &b)
{
    if(a.second==b.second)
    {
        return a.first<b.first;
    } else {
        return a.second>b.second;
    }
} //----- Fin de sortbysecdesc

void Statistique::Ajouter ( Lecture & livre)
{
    string dest = livre.ligne.getDestUrl(); // destination de la requête
    string referer = livre.ligne.getReferer(); // origine de la requête

    Dico::iterator itr = carte.find(dest);
    if(itr!=carte.end()) // teste si la destination est déjà présente dans la structure de données
    {
        Cons::iterator ptr;
        bool present = false; // indique si l'origine de la requête est présente dans la structure de données

        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            if(ptr->first == referer) { // teste si l'origine est présente dans la structure de données
                ptr->second = ptr->second + 1; // on incrémente le nombre de hit vers la destination depuis cette origine
                present = true;
                break;
            }
        }

        if (present == false) { // si l'origine n'est pas présente dans la structure de données
            carte[dest].insert(make_pair(referer, 1)); //on l'insère
        }

        Cons::iterator itr = consultation.find(dest);
        itr->second = itr->second + 1; // incrémente le nombre de hit vers la destination depuis toutes les origines

    } else { // si la destination n'est pas présente dans la structure de données

        // insère les informations de cette requête dans les structures de données
        carte.insert(make_pair(dest, map<string, int>()));
        carte[dest].insert(make_pair(referer, 1));
        consultation.insert(make_pair(dest,1));
    }
} //----- Fin de Ajouter

void Statistique::Top()
{
    // création d'un vecteur
    vector<std::pair<string, int> > arr; 
    
    // remplissage du vecteur avec les éléments de consultation
    Cons::iterator itr;
    for (itr = consultation.begin(); itr != consultation.end(); itr++)
    {
        arr.push_back(make_pair(itr->first,itr->second));
    }

    // tri du vecteur par ordre décroissant des hits
    sort(arr.begin(), arr.end(), sortbysecdesc);

    // affichage des 10 fichiers les plus consultés par ordre décroissant de popularité
    int compteur=0;
    while(compteur<arr.size() && compteur<10)
    {
        cout << arr[compteur].first <<" (" << arr[compteur].second <<" hits)" << endl;
        compteur++;
    }
} //----- Fin de Top

void Statistique::Graphe(string nomFichier)
{
    Dico::iterator itr;   // For accessing outer map
    Cons::iterator ptr;   // For accessing inner map
    // Création d'une structure de données pour gérer les noeuds 
    Cons graphe;
    int numero=0;

    // on remplit le graphe avec les destinations et les referer(origines) des requêtes
    // on leur assigne à chacune un nombre entier unique
    for (itr = carte.begin(); itr != carte.end(); itr++) {
        graphe.insert(make_pair(itr->first,numero));
        numero++;
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            graphe.insert(make_pair(ptr->first,numero));
            numero++;
        }
    }

    ofstream file (nomFichier); //ouverture du fichier nomFichier
    streambuf *oldCoutBuffer = cout.rdbuf ( file.rdbuf ( ) ); //redirection du streambuffer
    if(!file) // teste si le fichier n'a pas pu s'ouvrir
    {
        cout <<"Erreur ouverture fichier"<<endl;
    } else { // écriture du fichier .dot
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
} //----- Fin de Graphe

//-------------------------------------------- Constructeurs - destructeur
Statistique::Statistique ( const Statistique & unStatistique )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Statistique (constructeur de copie)


Statistique::Statistique ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Statistique>" << endl;
#endif
} //----- Fin de Statistique


Statistique::~Statistique ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Statistique>" << endl;
#endif
} //----- Fin de ~Statistique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

