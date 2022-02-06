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
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Lecture.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Lecture::Lire()
{
    string texte;
    if(file)
    {
        getline(file,texte,' ');
        ligne.IPAdress=texte;
        getline(file,texte,' ');
        ligne.UserLogname=texte;
        getline(file,texte,' ');
        ligne.AuthenticatedUser=texte;
        getline(file,texte,'[');
        getline(file,texte,']');
        ligne.Date=texte;
        getline(file,texte,'"');
        getline(file,texte,'/');
        getline(file,texte,' ');
        ligne.DestUrl=texte;
        getline(file,texte,'"');
        getline(file,texte,' ');
        getline(file,texte,' ');
        ligne.ReturnCode=texte;
        getline(file,texte,' ');
        ligne.DataTransfered=texte;
        getline(file,texte,'"');
        getline(file,texte,'"');
        ligne.Referer=texte;
        getline(file,texte,'"');
        getline(file,texte,'"');
        ligne.ClientNavigateur=texte;
        ligne.createExtension(); //on détermine si la destination est une image, un fichier css ou javascript, ou autre chose
        ligne.createHour(); //on détermine l'heure de la requête

        //vérifier si base de l'url de DestUrl est locale
        string local = "http://intranet-if.insa-lyon.fr";
        if (ligne.Referer.find(local) != string::npos) {
            //Si elle est locale, on supprime la base de l'url de DestUrl
            stringstream input_stringstream(ligne.Referer);
            getline(input_stringstream, ligne.Referer, '/');
            getline(input_stringstream, ligne.Referer, '/');
            getline(input_stringstream, ligne.Referer, '/');
            getline(input_stringstream, ligne.Referer, ' ');
        }
    }
    else{
        cout<<"ERREUR : La ligne n'a pas pu être lue "<<endl;
    }
} //----- Fin de Lire

string Lecture::getIPAdress()
{
    return ligne.IPAdress;
} //----- Fin de getIPAdress

string Lecture::getExtension()
{
    return ligne.extension;
} //----- Fin de etExtension

string Lecture::getHeure()
{
    return ligne.hour;
} //----- Fin de getHeure

string Lecture::getReturnCode()
{
    return ligne.ReturnCode;
} //----- Fin de getReturnCode

ifstream & Lecture::getFile()
{
    return file;
} //----- Fin de getFile


//-------------------------------------------- Constructeurs - destructeur
Lecture::Lecture ( const Lecture & unLecture )
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
string ext = ".log";
if(nomFichier.find(ext) != string::npos)
{
    file.open(nomFichier);
    if (!file) {
        cout << "ERREUR : Le fichier n'a pas été ouvert" << endl;
    }
} else {
    cout<<"Le fichier en entrée n'est pas un .log !"<<endl;
}
} //----- Fin de Lecture


Lecture::~Lecture ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Lecture>" << endl;
#endif
    file.close();
} //----- Fin de ~Lecture


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

