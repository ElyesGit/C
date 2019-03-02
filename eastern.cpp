// Nom et Prenom : Lamouchi Elyes
// Matricule : 20063403


#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	
	int annee, nbre_bissextiles, coeff_correc, dimanche, jour_pleine_lune, nombre_or, siecle;
	
	// Saisie de l'annee  
	printf("Entez l'annee desiree :\n");
	scanf("%d",&annee);
	
	// Initialisation des  variables utilisees dans l'algorithme
	nombre_or = (annee%19)+1; 	// convertir l'annee saisie en annee de cycle metonique (c'est dire que par exemple 2016 et 2035 donnent le meme nombre d'or)
	siecle = (annee/100)+1;         		 // calcul du siecle
	nbre_bissextiles = ((3*siecle)/4)-12;      //  le nombre de journee de plus (annee bissextile contient 366 jours) 
	coeff_correc=(((8*siecle)+5)/25)-5;		// synchronisation de paques avec l'orbite de la lune
	dimanche=((5*annee)/4)-nbre_bissextiles-10;
	
	 
	jour_pleine_lune =( (11*nombre_or) + 20+ coeff_correc -nbre_bissextiles ) %30 ; // calcul de la pleine lune
	 
		if (jour_pleine_lune<0)
		{
		 	jour_pleine_lune=jour_pleine_lune+30;
		}
		 
		else if (((jour_pleine_lune==25 && nombre_or>11) || (jour_pleine_lune==24)))
		{
		 	jour_pleine_lune=jour_pleine_lune+1;
		}
	 
	jour_pleine_lune=44-jour_pleine_lune;
	
		if (jour_pleine_lune<21)
		{
		 	jour_pleine_lune=jour_pleine_lune+30;
		}
	 
	jour_pleine_lune=jour_pleine_lune+7-((dimanche + jour_pleine_lune)%7);
	
		if (jour_pleine_lune>31)           // si j>31 on est entrer dans le mois d'avril
		{
		 	jour_pleine_lune=jour_pleine_lune-31;
		 	printf("\n La date est le %d avril ", jour_pleine_lune);
		}
		 
		else if (jour_pleine_lune<32)
		{
		 	printf("\n La date est le %d mars ", jour_pleine_lune);
		}
 
return 0;
}
