/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <string>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Ligne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ligne::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Ligne::getDestUrl()
{
    return DestUrl;
}

string Ligne::getReferer()
{
    return Referer;
}
void Ligne::createHour()
{
    string temp;
    stringstream input_stringstream(Date);

    getline(input_stringstream, temp, ':');
    getline(input_stringstream, hour, ':'); // On stocke dans l'attribut hour l'heure du hit à partir de la Date
}

void Ligne::createExtension()
{
    string ext1 = ".jpg";
    string ext2 = ".png";
    string ext3 = ".gif";
    string ext4 = ".css";
    string ext5 = ".js";
    if (DestUrl.find(ext1) != string::npos || DestUrl.find(ext2) != string::npos || DestUrl.find(ext3) != string::npos || DestUrl.find(ext4) != string::npos || DestUrl.find(ext5) != string::npos)
    {
        extension = "present"; 
    }
    else
    {
        extension = "absent";
    }
}

//-------------------------------------------- Constructeurs - destructeur
Ligne::Ligne(const Ligne &unLigne)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ligne>" << endl;
#endif
} //----- Fin de Ligne (constructeur de copie)

Ligne::Ligne()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif

} //----- Fin de Ligne

Ligne::~Ligne()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
} //----- Fin de ~Ligne

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
