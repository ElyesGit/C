// Nom et Prenom : Lamouchi Elyes
// Matricule : 20063403


#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	
	int a, b, c, a1, i;
 
	 	for(int i = 100; i < 1000; i++)       // Parcours tout les entiers compris entre 100 et 999 
		{                                    // afin de verifier si ils sont des nombres d'Armstrong ou pas
			a=i%10;
			a1=i/10;            
			b=a1%10;
			c=i/100;
			
				if(i == (a*a*a)+(b*b*b)+(c*c*c))          
				{
				printf(" %d est un Nombre d Armstrong \n", i);
				}
			
		}	 
 
 
 return 0;
}

