/*
    nom 1 : 
    matricule 1 :
         
    nom 2 :
    matricule 2 :
*/

#include <math.h>
#include <stdio.h>

#define MAX_DROITE 20
#define PRECISION 0.00001



/* Pour afficher les coordonnées d'un point */ 
void affichePoint(float x, float y){
	printf("(%7.3f,%7.3f )\n",x,y);
}

/* Pour afficher l'équation de la droite */
void afficheDroite(float m, float b)
{
	printf("Y = %8.4fX + %8.4f\n", m, b);
}

/* retourne la valeur de Y d'une droite Y = mX + b ou 
   X est connu */
float yDeDroite( float m, float b, float x){
	return b + m * x;
}

/* retourne la valeur de X d'une droite Y = mX + b ou 
   Y est connu */
float xDeDroite( float m, float b, float y){
	return (y - b)/m;
}

float absolue(float a)
{ return a<0?-a:a;   /* si a est négatif on retourne -a sinon a */
}


int estParallele(float m1, float m2)
{
	float diff;


	diff = absolue(m1 - m2);  /* La différence en valeur absolue entre les pentes */

	if(diff>=PRECISION)            /* est ce que la différence est significative */
		return 0;                  /* si oui, pas parallele */
	else return 1;                 /* si non, on cosidere parallele */
}


/* Cette fonction calcule la différence en valeur absolue entre la pente m1 */
/* et -1/(pente m2). Si la différence (en valeur absolue) est significative */
/* (plus grande que PRECISION) elles ne sont pas perpendiculaire (retourne 0)  */
/* sinon, on les considere perpendiculaires et on retourne 1*/

int estPerpendiculaire(float m1, float m2)
{
	float m3 = -1/m2;
	estParallele( m1, m3);
}

	
/* Cette fonction calcule les valeurs x et y du point qui résout le système  
   d'équation suivant :
   Y = m1 X + b1
   Y = m2 X + b2

  Le point (X,Y) est ensuite transmis par pointeurs
*/

void intersection(float m1, float b1 ,float m2, float b2, float *x, float *y)
{
	float x1;
	float y1;
	x1 = (b2 - b1)/(m1 - m2);
	y1 = (m1 * x1) + b1;	
	*x = x1;
	*y = y1;
	affichePoint(*x, *y);
}


/*
Cette fonction calcule la droite qui est perpendiculaire à Y=mX+b ( pente = -1/m)
et passe par le point (x,y). La droite est transmise par pointeurs
*/

void perpendiculaire( float m, float b ,float x, float y, float *m1, float *b1)
{
	float m2;
	float b2;
	m2 = 1 / m;
	b2 = y - (m2 * x);
	*m1 = m2;
	*b1 = b2;
	yDeDroite( *m1, *b1, x);    
}

/* Calcul de la distance entre 2 points */
double distancePoints(float x1, float y1, float x2, float y2)
{
	float x2moinsx1= x2-x1;
	float y2moinsy1= y2-y1;
	return sqrt( x2moinsx1 * x2moinsx1 + y2moinsy1 * y2moinsy1 );
}

/* Calcul de la distance entre un point et une droite */
double distancePtDroite(float m, float b ,float x, float y)
{
	
	float xPlusPres, yPlusPres;
	float mPerpen, bPerpen;

	perpendiculaire( m,b, x,y, &mPerpen, &bPerpen);

	intersection(m,b,mPerpen,bPerpen,&xPlusPres, &yPlusPres);

	return distancePoints(x,y, xPlusPres, yPlusPres);
}



int main()
{
    float pente[MAX_DROITE]= {  1, 3.313253, -0.934783, 4, 1, -1, -2.07, 2.0/3};

    float ordOrig[MAX_DROITE]= {  1, -0.906627, 4.243479, -3.2, 0, 2, 9.51, -1.0/3};
	int i,nbDroite=8;
	int n;
	int *p;
	float min = 100;

	printf("Les droites du tableau\n");

	for(i=0; i<nbDroite; i++)
	{
		printf("%2d) ",i+1);
		afficheDroite(pente[i],ordOrig[i]);
	}
	
	// Reponse a la question 4 : Trouver et afficher l’équation de la droite qui est la plus rapprochée du point (5,2)
	for(i=0; i<nbDroite; i++)
	{
		
		float dist = distancePtDroite( pente[i], ordOrig[i], 5, 2);
		if (min > dist ){
			min = dist;
			n = i;
		}	
	}
	afficheDroite(pente[n],ordOrig[n]);
	
	// Reponse a la question 5 
	printf("\n Voici les droites paralleles a y = x + 1 \n ");
	for(i=1; i<nbDroite; i++)
	{
		int parallele  = estParallele(pente[i], pente[0]);
		if (parallele == 1 ){
			afficheDroite(pente[i],ordOrig[i]);		
		}	
	}

	// Reponse a la question 6 
	printf("\n Voici les droites perpendiculaires a y = x + 1 \n ");
	for(i=1; i<nbDroite; i++)
	{
		int perpendiculaire = estPerpendiculaire(pente[i], pente[0]);
		if (perpendiculaire == 1 ){
			afficheDroite(pente[i],ordOrig[i]);		
		}	
	}
	
	// Reponse a la question 7
	pente[2] *= -1/ pente[0];
	ordOrig[2] *= 3;
	afficheDroite(pente[2],ordOrig[2]);	
	
	// Reponse a la question 8
		printf("\n Voici les points d intersections a y = x + 1 \n ");
	for (i=1; i<nbDroite; i++)
	{
		int par = estParallele(pente[i], pente[0]);
		if (par == 0){
			intersection(pente[0], ordOrig[0] ,pente[i], ordOrig[i],  *x,  *y);
		}
	}
	
	
	
	
	
	
    system("pause");
    return 0;
}
