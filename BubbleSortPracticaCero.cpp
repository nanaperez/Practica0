#include <iostream>//Provee los elementos fundamentales para la entrada y salida en C++, es decir su inicializacion
#include <stdio.h>//Libreria que contiene tipos, macros y funciones para la realización de las diferentes tareas
#include <stdlib.h>//Libreria que contiene tipos, macros y funciones para la conversión numérica, generación de números aleatorios, búsquedas y ordenación, gestión de memoria y tareas similares //Creo que no la necesitamos
#include <time.h>//Libreria que contiene tipos, macros y funciones para la la manipulación de información sobre tiempos
#include <string>//Incluye contenedores tipo string para trabajar con cadenas de caracteres
#include <vector>//Incluye contenedores tipo vector, es decir, un arreglo dinamico
using namespace std; //Espacios de nombres, es decir, nombres de funciones 
int ini, fin;
vector <string> v;

void intercambiar(string &a, string &b) //Metodo que es llamado en OrdBurbuja para intercambiar las palabras y poder ordenarlas
{
  string tmp = b; // al string 'b' le asigna una variable temporal
  b = a; // al string 'a' le asigna 'b'
  a = tmp; // a la variable temporal se le asigna 'a'
}

void OrdBurbuja() //Metodo que se encarga de ordenar las palabras
{ 
  for (int i = 0; i<v.size()-1 ; i++)
    for (int j = 0; j<v.size()-1 ; j++)
      if(v[j] > v[j+1])
	intercambiar(v[j],v[j+1]);
}

vector <string> leer_archivo() //Metodo que se encarga de solo lectura del archivo .txt
{
  freopen("1.txt","r",stdin); //Esta funcion abre un fichero para escritura/reescritura. El parametro es el fichero a abrir, la funcion que se va a cumplir y la accion
  string x;
  vector <string> v;
  while(cin >> x) v.push_back(x);
  return v;
}

int main() //Metodo principal que se encarga de ejecutar todos los metodos
{ 
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
