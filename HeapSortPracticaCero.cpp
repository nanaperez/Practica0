#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
using namespace std;
int ini, fin;
vector <string> v; 

void OrdHeap(){

}

vector <string> leer_archivo()
{
  freopen("2.txt","r",stdin);
  string x;
  vector <string> v;
  while(cin >> x) v.push_back(x);
  return v;
}

int main(){
  ini = clock();
  v = leer_archivo();
  OrdHeap();
  fin = clock();
  for (int i = 0; i<v.size(); i++)
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
