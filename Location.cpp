// But: �crire un programme pour calculer le montant qu�un individu devra d�bourser pour faire un voyage dans une automobile lou�e.
// Auteur: Christophe Baron
// Date: 2020-09-16

// Inclure la balise iostream ainsi que le module std
#include <iostream>
using namespace std;

// Ouverture du main

int main()
{
	// Incluse les caract�res sp�ciaux
	setlocale(LC_ALL, "");

	// D�clarer les variables utilis�es pour le programme
	int jour;
	int prix;
	float km;
	float moyennekm;
	float extramoyenne;
	float gas;
	float prix2;
	float prixfinal;

	// Au d�part le co�t de la voiture commence a 0 et va augmenter avec le nombre de km
	prix = 0;
	prix2 = 0;

	// Demander a l'utilisateur des informations
	cout << "Bonjour!" << endl << "Bienvenue au logiciel de calcul de d�penses pour une voiture lou�e!";
	
	cout << "Veuillez ins�rer le nombre de jours pendant lequel la voiture sera lou�e: ";
	cin >> jour;

	// Calcul du co�t de la voiture a chaque jours pour le nombre de jours qui se stocke dans la variable "prix"
	prix = jour * 45;

	// Demander le nombre de km parcouru par jour en moyenne pour ajouter le 0.05$ a chaque km
	cout << "Veullez ins�rer le nombre de kilom�tres parcourus au total durant la location du v�hicule: ";
	cin >> km;

	// Calculmer la moyenne des kilom�tres pour la dur�e du s�jour
	moyennekm = km / jour;

	// Si la moyenne de kilom�tres d�passe le 250km par jours on charge 0.05$ par kilom�tre de trop parcouru
	if (moyennekm > 250)
	{
		extramoyenne = moyennekm - 250;		// On soustrait les km gratuit (250) pour obtenir le surplus de km
		prix2 = prix + (0.05 * extramoyenne);		// Rajouter les km de surplus a la valeur d�pens�e
		cout << "Votre facture est de: " << prix2 << "$." << endl;	// Affiche la facture avec les kilom�tres d'extra ajout�
	}
	else
	{
		cout << "Pas de kilom�tre suppl�mentaire. Vous ne serez pas charg� d'un extra" << endl;		// Message pour annoncer que le kilom�trage par jour n'a pas �t� d�pass�
		cout << "Votre facture est de: " << prix << "$." << endl;	// Affiche la facture de la location de l'automobile
	}

	cout << "Calcule du prix du gas en cours..." << endl; // Message seulement pour informer l'utilisateur
	gas = 7.6 *(km / 100);	// Calcul les litres au 100km pour obtenir le prix du gas

	if (prix2 > prix)
	{
		prixfinal = prix2;	// D�terminer le prix final pour le kilom�trage extra
		prixfinal = prix2 + gas * 1.25;	// Recalcule le prix final ajouter au prix du gas
		cout << "Votre facture est maintenant de: " << prixfinal << "$.";
	}
	else
	{
		prixfinal = prix;	// D�terminer le prix final pour le kilom�trage extra
		prixfinal = prix + gas * 1.25;	// Recalcule le prix final ajouter au prix du gas
		cout << "Votre facture est maintenant de: " << prixfinal << "$.";	// Affiche le prix final de la location + extra kilom�tres + le prix du gas
	}
	/*
		Plan de test:

		Nb de jours:			Nb de km:			Prix ($):
		3						750					206,25
		20						5000				1375
		1						350					83,25
		127						31750				8731,25
		7						2842				592,79
	*/


	return 0;
}