/*************************************************************************
                           Statistique  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Statistique> (fichier Statistique.h) ----------------
#if ! defined ( Statistique_H )
#define Statistique_H

//--------------------------------------------------- Interfaces utilisées
#include "Ligne.h"
#include "Lecture.h"
#include <map>
#include <vector>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Statistique>
// Analyse les lignes du fichier log
// Permet de déterminer les fichiers les plus consultés
// Permet d'écrire un fichier dot pour réaliser un graphe de parcours
//------------------------------------------------------------------------

class Statistique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
   
    void Ajouter(Lecture & livre);
    // Mode d'emploi :
    // Ajoute les informations de la ligne lue par l'objet Lecture livre
    // dans les structures de données carte et consultation

    void Top();
    // Mode d'emploi :
    // Affiche les 10 fichiers les plus consultés par ordre décroissant de popularité

    static bool sortbysecdesc(const pair<string,int> &a, const pair<string,int> &b);
    // Mode d'emploi :
    // Tri un vector<std::pair<string, int> > par ordre décroissant du int 
    // En cas d'égalité, tri par ordre alphabétique

    void Graphe(string nomFichier);
    // Mode d'emploi :
    // Écrit dans le fichier nomFichier les informations nécessaires pour créer un graphe 


//-------------------------------------------- Constructeurs - destructeur
    Statistique ( const Statistique & unStatistique );

    Statistique ( );

    virtual ~Statistique ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    // Le premier string : destination de la requête
    // Dans map<string,int> : string est le referer (l'origine) de la requête
    // et le int est le nombre de hits vers la destination depuis ce referer
    typedef map <string, map<string,int> > Dico;
    Dico carte;

    // string : destination de la requête
    // int : nombre de hits vers la destination depuis tous les referer
    typedef map <string,int>  Cons;
    Cons consultation;

};

//-------------------------------- Autres définitions dépendantes de <Statistique>

#endif // Statistique_H

