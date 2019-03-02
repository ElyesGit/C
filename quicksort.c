#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quickSort(float arr[], char p[][], char n[][], int nbr[], int left, int right) {
      int i = left, j = right;
      float tmp;
      char tmpN;
      char tmpP;
      int tmpNbr;
      int pivot = arr[(left + right) / 2];

      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;

                  tmpP = p[i];
                  p[i] = p[j];
                  p[j] = tmpP;

                  tmpN = n[i];
                  n[i] = n[j];
                  n[j] = tmpN;

                  tmpNbr = nbr[i];
                  nbr[i] = nbr[j];
                  nbr[j] = tmpNbr;

                  i++;
                  j--;
            }
      };

      if (left < j)
            quickSort(arr, p, n, nbr, left, j);
      if (i < right)
            quickSort(arr, p, n, nbr, i, right);
}

int main(){
  FILE *fp;
  int numeros_tab[200];
  char prenoms_tab[200][200];
  char noms_tab[200][200];
  float notes_tab[200];

  fp = fopen("notes.txt", "r");

  if(fp == NULL){
    printf("Can't open file\n");
  }

  int i = 0;
  while(feof(fp) == 0){
    int numero = 0;
    char prenom[50];
    char nom[50];
    float note = 0;

    char numero_str[50];
    fscanf(fp, "%s", numero_str);
    numero = atoi(numero_str);
    numeros_tab[i] = numero;

    fscanf(fp, "%s", prenom);
    strcpy(prenoms_tab[i], prenom);
    fscanf(fp, "%s", nom);
    strcpy(noms_tab[i], prenom);

    char note_str[200];
    fscanf(fp, "%s", note_str);
    note = atof(note_str);
    notes_tab[i] = note;

    i++;
  }

  quickSort(notes_tab, prenoms_tab, noms_tab, numeros_tab, 0, i - 1);

  for(int j = 0; j < i; j++){
      printf ("%d\t", numeros_tab[j]);
      printf("%s\t", prenoms_tab[j]);
      printf("%s\t", noms_tab[j]);
      printf("%f\n", notes_tab[j]);
  }

  fclose(fp);
  return 0;
}
