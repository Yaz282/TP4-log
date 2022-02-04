#include <iostream>
using namespace std;
#include "Ligne.h"
#include "Lecture.h"
#include "Statistique.h"

int main()
{
	string nomFichier = "texte.log";
	Lecture livre = Lecture(nomFichier.c_str());
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
	livre.Lire();
	stat.Ajouter(livre);
	//stat.Afficher();
	stat.Top();
	stat.Graphe("graphe.dot");

	return 0;
}