#include <iostream>
#include <stdio.h>
#include <stdlib.h>

FILE *archivo;
char caracter;

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
  lecturaarchivo();
  return 0;
}
