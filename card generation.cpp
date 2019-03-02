// Nom et Prenom : Lamouchi Elyes
// Matricule : 20063403


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;



           // En considerant qu'il ya 52 cartes, 13 de chaques couleurs,
		  // J'ai pose que de  0 --> 12 on a les cartes Hearts (d'ou H) dans l'ordre 1,2,3,4..10,V,Q,K (ou 0 correspond a l'as et 12 correspond au roi K)
	     //                de 13 --> 25 on a les cartes Diamonds dans l'ordre 1,2,3,4..10,V,Q,K
	    //                 de 26 --> 38 on a les cartes Diamonds dans l'ordre 1,2,3,4..10,V,Q,K
	   //                  de 38 --> 51 on a les cartes Diamonds dans l'ordre 1,2,3,4..10,V,Q,K
	  //  Puisque chaque chiffre correspond a une seule carte, pour simuler un tirage aleatoire d'une carte il suffit de generer pseudo-aleatoirement
	 //  un entier compris entre 0 et 52



int main()
{
	 int n, m;
	 char c, l;
	 
	       
	 // Generer un entier entre 0 et 52 correspondant a une carte unique
	 srand(time(NULL));
	 n = rand()%52;
	 
	 
	 m=0;
	 l=' ';
	 
	 
	 	// Convertir l'entier genere en la valeur de la carte correspondante et assigner la couleur de la carte ( Hearts, Diamonds..) 
		 if (n<=12)
		 {
		 	m=n+1;
		 	c='h';            
		 }
		 else if (n>=13 && n<=25)
		 {
		 	m=n-12;
		 	c='d';
		 }
		 else if (n>=26 && n<=38)
		 {
		 	m=n-25;
		 	c='s';
		 }
		 else if (n>=39 && n<=51)
		 {
		 	m=n-38;
		 	c='c';
		 }
	 
	 
		// Assigner la lettre V Q K au cartes a valeurs 11, 12 et 13
		switch(m)
		{
			case 11:
				l='V';
				break;
			case 12:
				l='Q';
				break;
			case 13:
				l='K';
				break;		
		}
	 
		 
		if (m<=10)                 // Pour les cartes a chiffres 1,2 jusqua 10 la valeur de la carte est de type entier d'ou l'utilisation de %d
		{
			switch(c)
			{
				case 'h':
					printf("La carte tiree est : %d de coeurs ", m);
					break;
				case 'd':
					printf("La carte tiree est : %d de diamonds ", m);
					break;
				case 's':
					printf("La carte tiree est : %d de piques ", m);
					break;
				case 'c':
					printf("La carte tiree est : %d de trefles ", m);
					break;	                                   
			}
		 }
		
		else if (m>=11)         // Pour les cartes a lettres V, Q et K la valeur de la carte est de type character d'ou l'utilisation de %c
		{
			switch(c)
			{
				case 'h':
					printf("La carte tiree est : %c de coeurs ", l);
				    break;
				case 'd':
					printf("La carte tiree est : %c de diamonds ", l);
					break;
				case 's':
					printf("La carte tiree est : %c de piques ", l);
					break;
				case 'c':
					printf("La carte tiree est : %c de trefles ", l);
					break;	
			}	 	
		}
		
 return 0 ;
}
