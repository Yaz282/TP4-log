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
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Statistique.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Lecture::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Statistique::Ajouter ( Ligne & ligne)
{
    //tdico.insert()
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

