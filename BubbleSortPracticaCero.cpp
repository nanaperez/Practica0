#include <iostream>//Iniciación de c++
#include <stdio.h>//
#include <stdlib.h>//Incluir todas las librerias de c++ //consultar
#include <time.h>//Libreria que me permie
#include <string> 
#include <vector>
using namespace std; 
int ini, fin;
vector <string> v;

void intercambiar(string &a, string &b)
{
  string tmp = b;
  b = a;
  a = tmp;
}

void OrdBurbuja(){
  for (int i = 0; i<v.size()-1 ; i++)
    for (int j = 0; j<v.size()-1 ; j++)
      if(v[j] > v[j+1])
	intercambiar(v[j],v[j+1]);
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
  OrdBurbuja();
  fin = clock();
  for (int i = 0; i<v.size(); ++i)
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
