// Nom et Prenom : Lamouchi Elyes
// Matricule : 20063403


#include <stdio.h>         // 	On a inclus stdio.h afin de pouvoir utiliser prinft() dans la suite
#include <time.h>
#include <stdlib.h>

int main()
{
 	int n1, n2, n3;  
 
 	srand(time(NULL));  
 	n1 = rand()%10;        // 	Pour une valeur pseudo-al�atoire entre 0 et n
 	n2 = rand()%10;       //   on doit doit affecter � notre variable rand()%(n+1)
 	n3 = rand()%10;
 	
	printf("Tirage de la quotidienne � 3 chiffres : %d %d %d ", n1, n2, n3);     // on a mis %d car on utilise des entiers
 	
	return 0 ;
}
