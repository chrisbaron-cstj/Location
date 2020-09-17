// But: Écrire un programme pour calculer le montant qu’un individu devra débourser pour faire un voyage dans une automobile louée.
// Auteur: Christophe Baron
// Date: 2020-09-16

// Inclure la balise iostream ainsi que le module std
#include <iostream>
using namespace std;

// Ouverture du main

int main()
{
	// Incluse les caractères spéciaux
	setlocale(LC_ALL, "");

	// Déclarer les variables utilisées pour le programme
	int jour;
	int prix;
	float km;
	float moyennekm;
	float extramoyenne;
	float gas;
	float prix2;
	float prixfinal;

	// Au départ le coût de la voiture commence a 0 et va augmenter avec le nombre de km
	prix = 0;
	prix2 = 0;

	// Demander a l'utilisateur des informations
	cout << "Bonjour!" << endl << "Bienvenue au logiciel de calcul de dépenses pour une voiture louée!";
	
	cout << "Veuillez insérer le nombre de jours pendant lequel la voiture sera louée: ";
	cin >> jour;

	// Calcul du coût de la voiture a chaque jours pour le nombre de jours qui se stocke dans la variable "prix"
	prix = jour * 45;

	// Demander le nombre de km parcouru par jour en moyenne pour ajouter le 0.05$ a chaque km
	cout << "Veullez insérer le nombre de kilomètres parcourus au total durant la location du véhicule: ";
	cin >> km;

	// Calculmer la moyenne des kilomètres pour la durée du séjour
	moyennekm = km / jour;

	// Si la moyenne de kilomètres dépasse le 250km par jours on charge 0.05$ par kilomètre de trop parcouru
	if (moyennekm > 250)
	{
		extramoyenne = moyennekm - 250;		// On soustrait les km gratuit (250) pour obtenir le surplus de km
		prix2 = prix + (0.05 * extramoyenne);		// Rajouter les km de surplus a la valeur dépensée
		cout << "Votre facture est de: " << prix2 << "$." << endl;	// Affiche la facture avec les kilomètres d'extra ajouté
	}
	else
	{
		cout << "Pas de kilomètre supplémentaire. Vous ne serez pas chargé d'un extra" << endl;		// Message pour annoncer que le kilométrage par jour n'a pas été dépassé
		cout << "Votre facture est de: " << prix << "$." << endl;	// Affiche la facture de la location de l'automobile
	}

	cout << "Calcule du prix du gas en cours..." << endl; // Message seulement pour informer l'utilisateur
	gas = 7.6 *(km / 100);	// Calcul les litres au 100km pour obtenir le prix du gas

	if (prix2 > prix)
	{
		prixfinal = prix2;	// Déterminer le prix final pour le kilométrage extra
		prixfinal = prix2 + gas * 1.25;	// Recalcule le prix final ajouter au prix du gas
		cout << "Votre facture est maintenant de: " << prixfinal << "$.";
	}
	else
	{
		prixfinal = prix;	// Déterminer le prix final pour le kilométrage extra
		prixfinal = prix + gas * 1.25;	// Recalcule le prix final ajouter au prix du gas
		cout << "Votre facture est maintenant de: " << prixfinal << "$.";	// Affiche le prix final de la location + extra kilomètres + le prix du gas
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