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
//
//
//------------------------------------------------------------------------

class Statistique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Ajouter(Lecture & livre);

    void Afficher();

    void Top();

    static bool sortbysecdesc(const pair<string,int> &a, const pair<string,int> &b);

    void Graphe(string nomFichier);


//------------------------------------------------- Surcharge d'opérateurs
    //Statistique & operator = ( const Statistique & unStatistique );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Statistique ( const Statistique & unStatistique );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Statistique ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Statistique ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    //typedef map <string, pair< map<string,int>, int> > Dico;
    typedef map <string, map<string,int> > Dico;
    Dico carte;
    typedef map <string,int>  Cons;
    Cons consultation;

};

//-------------------------------- Autres définitions dépendantes de <Statistique>

#endif // Statistique_H

