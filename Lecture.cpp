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
        ligne.IPAdress=texte;
        getline(file,texte,' ');
        ligne.UserLogname=texte;
        getline(file,texte,' ');
        ligne.AuthenticatedUser=texte;
        getline(file,texte,'[');
        getline(file,texte,']');
        ligne.Date=texte;
        getline(file,texte,'"');
        getline(file,texte,' ');
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
        ligne.createExtension();
        ligne.createHour();
    }
    else{
        cout<<"ERREUR : La ligne n'a pas pu être lue "<<endl;
    }

}



string Lecture::getIPAdress()
{
    return ligne.IPAdress;
}
string Lecture::getExtension()
{
    return ligne.extension;
}

string Lecture::getHeure()
{
    return ligne.hour;
}

ifstream & Lecture::getFile()
{
    return file;
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
string extFich;
ligne.createString(nomFichier,extFich,'.',' ');
if(extFich=="log"){
    file.open(nomFichier);
        if (!file)
    {
        cout << "ERREUR : Le fichier n'a pas été ouvert" << endl;
    }
}
else{
    cout<<"Le fichier en entrée n'est pas un .log !"<<endl;
}
} //----- Fin de Lecture


Lecture::~Lecture ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Lecture>" << endl;
#endif
    file.close();
} //----- Fin de ~Lecture


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

