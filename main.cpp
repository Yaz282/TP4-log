#include <iostream>
using namespace std;
#include "Ligne.h"
#include "Lecture.h"
#include "Statistique.h"
#include <string> 
#include<cstring>

typedef struct Commande {
    bool Arg_t=false; 
    bool Arg_e=false;
    bool Arg_g=false;
	string fichDot;
	string heure;
} Commande; // Peu importe l'ordre des commandes

int main(int argc, char* argv[])
{
	/*for(int i=0;i<argc;i++){ 
		cout<<argv[i]<<endl;
	}*/

	// Mise a jour des flags
	Commande flags;
	for(int i=0;i<argc;i++){ // Gestion des erreurs à faire
		if(!strcmp(argv[i],"-g")){
			flags.Arg_g=true;
			flags.fichDot=argv[i+1];
		}
		if(!strcmp(argv[i],"-t")){
			flags.Arg_t=true;
			flags.heure=argv[i+1];
		}	

		if(!strcmp(argv[i],"-e")){
			flags.Arg_e=true;
		}	
	}

	string nomFichier = argv[argc-1];
	/*cin >> nomFichier;*/
	Lecture fichLog(nomFichier);

	Statistique stat = Statistique();
	cout << flags.Arg_e<<endl;
	cout << flags.Arg_t<<endl;
	cout << flags.Arg_g<<endl;

	while (!fichLog.getFile().eof() && fichLog.getFile()) // Remplir ma structure de donnée avec les bonnes lignes
	{
		fichLog.Lire();
		//cout<<fichLog.getExtension()<<endl;

		if (flags.Arg_e){ // Si -e 
			if(fichLog.getExtension()=="jpg" || fichLog.getExtension()=="png"||fichLog.getExtension()=="gif"||fichLog.getExtension()=="js"||fichLog.getExtension()=="css"){//Si l'extension est à supprimer
				continue;
			}
		}
		if(flags.Arg_t){
			if(stoi(fichLog.getHeure())<stoi(flags.heure)||stoi(fichLog.getHeure())>=stoi(flags.heure)+1){
				continue;
			}
		}

		stat.Ajouter(fichLog);

		// Ajouter ma ligne à ma structure de donnée : elle a passé les différents tests
	}

	stat.Afficher();

	// Afficher le top 10 de ma structure de donnée
	stat.Top();

	// Créer le graphe : 

	if (flags.Arg_g)
	{
		stat.Graphe(flags.fichDot);
	}

	return 0;

}

/*#include <iostream>
using namespace std;
#include "Lecture.h"

typedef struct Commande {
    bool Arg_t=0; 
    bool Arg_e=0;
    bool Arg_g=0;
} Commande; // Peu importe l'ordre des commandes 

int main(int argc, char *argv[])
{
    // Définir les commandes 
    string nomFichier;
    cin>>nomFichier;
    Lecture fichLog (nomFichier);
    while(!fichLog.getFile().eof()){
        fichLog.Lire();
        if(){

        }

    }
    return 0;
}*/

	/*Lecture livre = Lecture(nomFichier.c_str());
	livre.Lire();
	string Ip = livre.getIPAdress();
	cout << Ip << endl;
	Statistique stat = Statistique();
	stat.Ajouter(livre);
	livre.Lire();
	stat.Ajouter(livre);
	livre.Lire();
	stat.Ajouter(livre);
	livre.Lire();
	stat.Ajouter(livre);
	livre.Lire();
	stat.Ajouter(livre);
	stat.Afficher();
	stat.Top();*/