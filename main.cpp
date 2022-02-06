#include <iostream>
using namespace std;
#include "Ligne.h"
#include "Lecture.h"
#include "Statistique.h"
#include <string> 
#include<cstring>
#include <sstream>


  /*void createString(const string & input, string & output , char del1, char del2 ){
        string temp;
        stringstream input_stringstream(input);

        getline(input_stringstream, temp, del1);
        getline(input_stringstream, output, del2);
    }*/

typedef struct Commande
{
	bool Arg_t=false; 
    bool Arg_e=false;
    bool Arg_g=false;
	string fichDot;
	string heure;
} Commande; // Peu importe l'ordre des commandes

int main(int argc, char* argv[])
{

	// Mise a jour des flags
	Commande flags;
	for(int i=0;i<argc;i++){
		if (!strcmp(argv[i], "-g"))
		{
			//string extFich;
			//createString(argv[i + 1], extFich, '.', ' ');
			string ext = ".dot";
			string fichier(argv[i+1]);
			//if (extFich == "dot")
			if (fichier.find(ext) != string::npos)
			{
				flags.Arg_g = true;
				flags.fichDot = argv[i + 1];
			}
			else
			{
				cout << "Warning : une commande -g n'a pas été prise en compte, le nom de Fichier entrée n'est pas un .dot" << endl;
			}
		}

		if (!strcmp(argv[i], "-t"))
		{
			string tmp(argv[i+1]);
			if (tmp.find_first_not_of("0123456789") == string::npos) // Si la commande est suivi par un nombre positif
			{
				if((stoi(argv[i+1])<24 )){
					flags.Arg_t = true;
					flags.heure = argv[i + 1];
				}
				else{
					cout << "Warning : une commande -t n'a pas été prise en compte : l'heure indiquée n'est pas comprise entre 0 et 23"<<endl;
				}
			}
			else
			{
				cout << "Warning : une commande -t n'a pas été prise en compte : l'heure indiquée n'est pas valide"<<endl;
			}
		}

		if(!strcmp(argv[i],"-e")){
			flags.Arg_e=true;
		}
	}
	if (flags.Arg_g)
	{
		cout << "Dot-file "<< flags.fichDot <<" generated"<<endl;
	}
	if (flags.Arg_t)
	{
		cout<< "Warning : only hits between " << stoi(flags.heure)  << "h and " << stoi(flags.heure)+1<<"h have been taken into account"<<endl;
	}

	string nomFichier = argv[argc-1];
	Lecture fichLog(nomFichier);

	Statistique stat = Statistique();

	while (!fichLog.getFile().eof() && fichLog.getFile()) // Remplir ma structure de donnée avec les bonnes lignes
	{
		fichLog.Lire();
		if(fichLog.getReturnCode() >= "400") continue;

		if (flags.Arg_e){ // Si -e 
			if(fichLog.getExtension()=="present"){ //Si l'extension est à supprimer
				continue;
			}
		}
		if(flags.Arg_t){
			if(stoi(fichLog.getHeure())<stoi(flags.heure)||stoi(fichLog.getHeure())>=stoi(flags.heure)+1){
				continue;
			}
		}
		if (fichLog.getFile().eof() ) break;
		stat.Ajouter(fichLog);

		// Ajouter ma ligne à ma structure de donnée : elle a passé les différents tests
	}

	// Afficher le top 10 de ma structure de donnée
	stat.Top();

	// Créer le graphe : 

	if (flags.Arg_g)
	{
		stat.Graphe(flags.fichDot);
	}

	return 0;

}