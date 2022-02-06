/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Lecture> (fichier Lecture.h) ----------------
#if ! defined ( LECTURE_H )
#define LECTURE_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include "Ligne.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Lecture>
//
//
//------------------------------------------------------------------------

class Lecture
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Lire();
    // Mode d'emploi :
    // Lit une ligne d'un fichier .log et crée un objet Ligne
    // Contrat :
    //

    string getIPAdress();
    ifstream & getFile();
    string getExtension();
    string getHeure();
    string getReturnCode();

    


    friend class Statistique;


//------------------------------------------------- Surcharge d'opérateurs
   // Lecture & operator = ( const Lecture & unLecture );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Lecture ( const Lecture & unLecture );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Lecture ( string nomFichier );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Lecture ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Ligne ligne;
ifstream file;
};

//-------------------------------- Autres définitions dépendantes de <Lecture>

#endif // LECTURE_H

