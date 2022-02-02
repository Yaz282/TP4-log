/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ligne> (fichier Ligne.h) ----------------
#if ! defined ( LIGNE_H )
#define LIGNE_H
#include <string>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ligne>
//
//
//------------------------------------------------------------------------

class Ligne
{
//----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void setIPAdress(string s);
    void setUserLogname(string s);
    void setAuthenticatedUser(string s);
    void setDate(string s);
    void setDestUrl(string s);
    void setReturnCode(string s);
    void setDataTransfered(string s);
    void setReferer(string s);
    void setClientNavigateur(string s);

    //------------------------------------------------- Surcharge d'opérateurs
   // Ligne & operator = ( const Ligne & unLigne );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Ligne ( const Ligne & unLigne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ligne ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Ligne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string IPAdress;
string UserLogname;
string AuthenticatedUser;
string Date;
string DestUrl;
string ReturnCode;
string DataTransfered;
string Referer;
string ClientNavigateur;

};

//-------------------------------- Autres définitions dépendantes de <Ligne>

#endif // LIGNE_H

