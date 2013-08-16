#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *archivo;
char caracter;
int ini, fin, t; 

void lecturaarchivo(){
  archivo = fopen("1.txt","r");
  if (archivo == NULL){
    printf("\nError al abrir el archivo. \n\n");
  }else{
    printf("\nOrdenando: \n\n");
    while (feof(archivo) == 0){
      caracter = fgetc(archivo);
      printf("%c",caracter);
    }
  }
}

int main(){
  ini = clock();
  lecturaarchivo();
  fin = clock();
  t=(fin-ini)/100000;
  printf("\n\nEl tiempo de ejecucion  es de: %d segundos\n",t);
  return 0;
}
