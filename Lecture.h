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
// La classe Lecture lit une ligne du fichier log à analyser et initialise son attribut ligne
// avec les informations lues
//------------------------------------------------------------------------

class Lecture
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Lire();
    // Mode d'emploi :
    // Lit une ligne d'un fichier .log et initialise son attribut ligne

    string getIPAdress();
    // Mode d'emploi :
    // Renvoie l'attribut IPAdress de l'objet Ligne en attribut

    ifstream & getFile();
    // Mode d'emploi :
    // Renvoie l'ifstream file

    string getExtension();
    // Mode d'emploi :
    // Renvoie l'attribut extension de l'objet Ligne en attribut

    string getHeure();
    // Mode d'emploi :
    // Renvoie l'attribut hour de l'objet Ligne en attribut

    string getReturnCode();
    // Mode d'emploi :
    // Renvoie l'attribut ReturnCode de l'objet Ligne en attribut

    friend class Statistique;
    // La classe <Statistique> est amie de <Lecture>
    // Elle a donc accès à ses attributs protégés et privés

//-------------------------------------------- Constructeurs - destructeur
    Lecture ( const Lecture & unLecture );
    // Constructeur de copie

    Lecture ( string nomFichier );
    // Mode d'emploi :
    // Vérifie que le fichier en paramètre est bien un fichier log
    // Si c'est le cas elle ouvre ce fichier
    // Sinon elle affiche un message d'erreur

    virtual ~Lecture ( );
    // Mode d'emploi :
    // Ferme le fichier ouvert dans le constructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Ligne ligne; //Ligne lue par la classe
ifstream file; //Ifstream contenant le fichier log à analyser
};

//-------------------------------- Autres définitions dépendantes de <Lecture>

#endif // LECTURE_H

