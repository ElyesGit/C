#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float EPSILON = pow(10, -10);
float X0 = 0.25;
float MAX_ITER = 100;
float i = 100;
float Xn_1 = 0;
float Xn = -9999;

float f_x(int x){
	float y = pow(x, 4) + 0.8 * pow(x, 3) - 0.3 * pow(x, 2) - 1.9 * x + 0.4;
	return y;
}
	
float deriv_fx(int x){
	float y=  4*pow(x,3)+ 2.4*pow(x,2)-0.6*x -1.9 ;
	return y;
}	

float resultat(int n){
	if ( n <= 0 || deriv_fx(Xn_1) == 0 || abs(Xn - Xn_1) < EPSILON ){
		return X0;
	} else{
		i--;
		float p = resultat(i);
		Xn_1 = p;
		Xn =  p - (f_x(p) / deriv_fx(p));
		return Xn;
	}	
}

int main(){
	float valeur = resultat(i);
	printf("%f\n", valeur);
	printf("%f", f_x(valeur));
	return 0;
}


	
	





		
