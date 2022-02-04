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
    /*void Ligne::setIPAdress(string s){
        IPAdress=s;
    }
    void Ligne::setUserLogname(string s){
        UserLogname=s;
    }
    void Ligne::setAuthenticatedUser(string s){
        AuthenticatedUser=s;
    }
    void Ligne::setDate(string s){
        Date=s;
    }
    void Ligne::setDestUrl(string s){
        DestUrl=s;
    }
    void Ligne::setReturnCode(string s){
        ReturnCode=s;
    }
    void Ligne::setDataTransfered(string s){
        DataTransfered=s;
    }
    void Ligne::setReferer(string s){
        Referer=s;
    }
    void Ligne::setClientNavigateur(string s){
        ClientNavigateur=s;
    }*/

    string Ligne::getDestUrl()
    {
        return DestUrl;
    }

    string Ligne::getReferer()
    {
        return Referer;
    }
    void Ligne::createHour(){
        createString(Date,hour,':',':');
    }

    void Ligne::createExtension(){
        createString(DestUrl, extension,'.',' ');
    }

    void Ligne::createString(const string & input, string & output , char del1, char del2 ){
        string temp;
        stringstream input_stringstream(input);

        getline(input_stringstream, temp, del1);
        getline(input_stringstream, output, del2);
    }



    //------------------------------------------------- Surcharge d'opérateurs
    /*Ligne & Ligne::operator = ( const Ligne & unLigne )
// Algorithme :
//
{
} //----- Fin de operator =
*/

    //-------------------------------------------- Constructeurs - destructeur
    Ligne::Ligne(const Ligne &unLigne)
    // Algorithme :
    //
    {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ligne>" << endl;
#endif
} //----- Fin de Ligne (constructeur de copie)


Ligne::Ligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif

} //----- Fin de Ligne


Ligne::~Ligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
} //----- Fin de ~Ligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

