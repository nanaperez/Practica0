#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <sstream>
#include <alloca.h>
#include <cstring>
using namespace std;
int ini, fin;
vector <string> v;

// Función para dividir el array y hacer los intercambios    
int divide(int start, int end) {
    int left;
    int right;
    string pivot;
    string temp;
 
    pivot = v[start];
    left = start;
    right = end;
 
    // Mientras no se cruzen los índices
    while (left < right) {
        while (v[right] > pivot) {
            right--;
        }
 
        while ((left < right) && (v[left] <= pivot)) {
            left++;
        }
 
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = v[left];
            v[left] = v[right];
            v[right] = temp;
        }
    }
 
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = v[right];
    v[right] = v[start];
    v[start] = temp;
 
    // La nueva posición del pivot
    return right;
}
 
// Función recursiva para hacer el ordenamiento
void OrdQuick(int start, int end)
{
    int pivot;
 
    if (0 < end) {
      pivot = divide(start, end);
 
        // Ordeno la lista de los menores
        OrdQuick(start, end);
 
        // Ordeno la lista de los mayores
        OrdQuick(pivot + 1, end);
    }
}

vector <string> leer_archivo()
{
  freopen("1.txt","r",stdin);
  string x;
  vector <string> v;
  while(cin >> x) v.push_back(x);
  return v;
}

int main(){
  
  ini = clock();
  v = leer_archivo();
  OrdQuick(0, v.size()-1);
  fin = clock();
  for (int i = 0; i < v.size()-1; ++i)
    cout << v[i] << endl;
  int mil = fin-ini;
  double seg = mil / (double) CLOCKS_PER_SEC;
  double min = seg / 60;
  double hor = min / 60;
  cout << "\n\nEl tiempo de ejecución es de: " << mil << " Milisegundos." << endl;
  cout << "El tiempo de ejecución es de: " << seg << " segundos." << endl;
  cout << "El tiempo de ejecución es de: " << min << " minutos." << endl;
  cout << "El tiempo de ejecución es de: " << hor << " horas." << endl;
  cout << "Cantidad de palabras: " << v.size() << endl;
  return 0;
}
