/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Lecture> (fichier Lecture.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Lecture.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Lecture::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Lecture::Lire()
{
    string texte;
    if(file)
    {
        getline(file,texte,' ');
        ligne.setIPAdress(texte);
        getline(file,texte,' ');
        ligne.setUserLogname(texte);
        getline(file,texte,' ');
        ligne.setAuthenticatedUser(texte);
        getline(file,texte,'GET ');
        getline(file,texte,' ');
        ligne.setDestUrl(texte);
        getline(file,texte,' ');
        getline(file,texte,' ');
        ligne.setReturnCode(texte);
        getline(file,texte,' ');
        ligne.setDataTransfered(texte);
        //getline(file,texte,'.fr');
        getline(file,texte,' ');
        ligne.setReferer(texte);
        getline(file,texte,' ');
        ligne.setClientNavigateur(texte);

    }

}


//------------------------------------------------- Surcharge d'opérateurs
// Algorithme :
//
/*Lecture & Lecture::operator = ( const Statistique & unStatistique )
// Algorithme :
//
{
} //----- Fin de operator =
*/


//-------------------------------------------- Constructeurs - destructeur
Lecture::Lecture ( const Lecture & unLecture )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Lecture (constructeur de copie)


Lecture::Lecture ( string nomFichier )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Lecture>" << endl;
#endif
    file.open(nomFichier);
} //----- Fin de Lecture


Lecture::~Lecture ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Lecture>" << endl;
#endif
    file.close(nomFichier);
} //----- Fin de ~Lecture


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

