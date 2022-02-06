/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ligne> (fichier Ligne.h) ----------------
#if !defined(LIGNE_H)
#define LIGNE_H
#include <string>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ligne>
// La classe objet Ligne permet de décrire une ligne d'un fichier log avec toutes les informations conservées
// dans ses attributs, pour des raisons de réutilisabilité.
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

    string getDestUrl();
    // Mode d'emploi :
    // Cette méthode permet de renvoyer l'attribut DestUrl 
    // Contrat :
    //
    string getReferer();
    // Mode d'emploi :
    // Cette méthode permet de renvoyer l'attribut Referer 
    // Contrat :
    //
    void createHour();
    // Mode d'emploi :
    // Cette méthode permet de compléter l'attribut Hour à partir de l'attribut Date 
    // Contrat :
    //
    void createExtension();
    // Mode d'emploi :
    // Cette méthode permet de compléter l'attribut extension en vérifiant si la ligne correspond à un fichier
    // image, javascript, css. L'attribut extension vaut alors "présent" s'il s'agit d'un fichier image, javascript 
    // ou css et "absent" sinon.
    // Contrat :
    //

    friend class Lecture; // La classe Lecture est une classe amie de la classe Ligne

    //-------------------------------------------- Constructeurs - destructeur
    Ligne(const Ligne &unLigne);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ligne();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Ligne();
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
    string extension;
    string hour;
};

//-------------------------------- Autres définitions dépendantes de <Ligne>

#endif // LIGNE_H
