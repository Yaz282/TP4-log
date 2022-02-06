#include <iostream>
using namespace std;
#include "Ligne.h"
#include "Lecture.h"
#include "Statistique.h"
#include <string>
#include <cstring>
#include <sstream>


typedef struct Commande
{
	bool Arg_t = false; 
	bool Arg_e = false;
	bool Arg_g = false;
	string fichDot;
	string heure;
} Commande; // L'ordre d'écriture des commandes n'est pas pris en compte.

int main(int argc, char *argv[])
{

	// Mise a jour des flags avec les paramètre entrés

	Commande flags;
	for (int i = 0; i < argc; i++)
	{
		if (!strcmp(argv[i], "-g")) // Si paramètre -g
		{

			string ext = ".dot";
			string fichier(argv[i + 1]);
			if (fichier.find(ext) != string::npos) // Si le paramètre est correctement utilisé avec fichier .dot qui le suit
			{
				flags.Arg_g = true; // On active le flags lié au paramètre -g
				flags.fichDot = argv[i + 1];
			}
			else // Si pas de fichier .dot
			{
				cout << "Warning : une commande -g n'a pas été prise en compte, le nom de Fichier entrée n'est pas un .dot" << endl;
			}
		}

		if (!strcmp(argv[i], "-t")) // Si paramètre -t
		{
			string tmp(argv[i + 1]);
			if (tmp.find_first_not_of("0123456789") == string::npos) // Si -t est suivi par un nombre positif
			{
				if ((stoi(argv[i + 1]) < 24)) 
				{
					flags.Arg_t = true; // On active le flags lié au paramètre -t
					flags.heure = argv[i + 1]; // On retient l'heure indiquée suivant le paramètre
				}
				else
				{
					cout << "Warning : une commande -t n'a pas été prise en compte : l'heure indiquée n'est pas comprise entre 0 et 23" << endl;
				}
			}
			else
			{
				cout << "Warning : une commande -t n'a pas été prise en compte : l'heure indiquée n'est pas valide" << endl;
			}
		}

		if (!strcmp(argv[i], "-e")) // Si paramètre -e
		{
			flags.Arg_e = true; // On active le flag lié au paramètre -e
		}
	}

	// Fin de la mise à jour des flags 

	// Affichage des messages liés à l'état final des flags :

	if (flags.Arg_g)
	{
		cout << "Dot-file " << flags.fichDot << " generated" << endl;
	}
	if (flags.Arg_t)
	{
		cout << "Warning : only hits between " << stoi(flags.heure) << "h and " << stoi(flags.heure) + 1 << "h have been taken into account" << endl;
	}

	string nomFichier = argv[argc - 1];  // On retient le nom du fichier .log indiquée sur le terminal

	Lecture fichLog(nomFichier);

	Statistique stat = Statistique();

	while (!fichLog.getFile().eof() && fichLog.getFile()) // Lire tout le fichier et remplir la structure de donnée avec les bonnes lignes selon l'état des flags
	{
		fichLog.Lire(); // Lire ligne de mon fichier

		if (fichLog.getReturnCode() >= "400") // Si le return code est supérieur à 400, on ne conserve pas la ligne 
			continue; 

		if (flags.Arg_e)
		{ 
			if (fichLog.getExtension() == "present")
			{ // Si l'extension est à supprimer
				continue;
			}
		}

		if (flags.Arg_t)
		{
			if (stoi(fichLog.getHeure()) < stoi(flags.heure) || stoi(fichLog.getHeure()) >= stoi(flags.heure) + 1)
			{// Si l'heure n'est pas dans le bon interval
				continue;
			}
		}

		if (fichLog.getFile().eof())
			break; 

		stat.Ajouter(fichLog); // Ajouter la ligne à ma structure de donnée : elle a passé les différents tests
	}

	stat.Top();	// Afficher le top 10 de ma structure de donnée

	if (flags.Arg_g)
	{
		stat.Graphe(flags.fichDot);	// Créer le fichier.dot si Flags correspondant au paramètre -g activé
	}

	return 0;
}