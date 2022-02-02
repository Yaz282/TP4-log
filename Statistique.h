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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Statistique>
//
//
//------------------------------------------------------------------------

class Statistique :
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Ajouter(Ligne & ligne);


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
    typedef map <string, pair< map<string,int>, int> > Dico;
    Dico tdico;

};

//-------------------------------- Autres définitions dépendantes de <Statistique>

#endif // Statistique_H

