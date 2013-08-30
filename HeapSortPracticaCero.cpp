#include <iostream> //Provee los elementos fundamentales para la entrada y salida en C++, es decir su inicializacion
#include <stdio.h> //Libreria que contiene tipos, macros y funciones para la realización de las diferentes tareas
#include <stdlib.h> //Libreria que contiene tipos, macros y funciones para la conversión numérica, generación de números aleatorios, búsquedas y ordenación, gestión de memoria y similares
#include <time.h> //Libreria que contiene tipos, macros y funciones para la la manipulación de información sobre tiempos
#include <string> //Incluye contenedores tipo string para trabajar con cadenas de caracteres
#include <vector> //Incluye contenedores tipo vector, es decir, un arreglo dinamico
#include <sstream> //Flujos hacia/desde cadenas alfanuméricas
// #include <alloca.h> //Algo con memoria
#include <cstring> //Define funciones para manipular strings y arreglos
#include <cmath>
using namespace std; //Espacios de nombres, es decir, nombres de funciones 
int ini, fin; //Variables para el inicio y fin del reloj
vector <string> v; //Funcion vector creada con varaibles strings para recibir los archivos a ordenar

void maxHeapify(vector<string>& v, int i, int heapSize) {
  int l = 2 * i;
  int r = 2 * i + 1;
  int largest;
  if(l <= heapSize && v[l] > v[i]) 
    largest = l;
  else
    largest = i;

  if(r <= heapSize && v[r] > v[largest])
    largest = r;

  if(largest != i) {
    swap(v[i], v[largest]);
    maxHeapify(v, largest, heapSize);   
  }
}

void buildMaxHeap(vector<string>& v, int heapSize) {
  for(int i = floor(v.size()-1 / 2); i >= 1; i--)
    maxHeapify(v, i, heapSize);
}

void heapSort(vector<string>& v) {
  int heapSize = v.size() - 1; 
  buildMaxHeap(v, heapSize);
  for(int i = v.size()-1; i>=2; i--) {
    swap(v[1], v[i]);
    heapSize--;
    maxHeapify(v, 1, heapSize);
  }
}

vector <string> leer_archivo() //Metodo que se encarga de solo lectura de los archivos .txt
{
  freopen("4.txt","r",stdin); //Esta funcion abre un fichero para escritura/reescritura. El parametro es el fichero a abrir, la funcion que se va a cumplir y la accion
  string x;
  vector <string> v;
  while(cin >> x) v.push_back(x);
  return v;
}

int main() {
  ini = clock();
  v = leer_archivo();
  heapSort(v);
  fin = clock();
  for (int i = 0; i < v.size()-1; ++i)
    cout << v[i] << endl;
  int mil = fin-ini;
  double seg = mil / (double) CLOCKS_PER_SEC;
  double min = seg / 60;
  double hor = min / 60;
  cout << "\n\nEl tiempo de ejecución es de: " << mil << " Milisegundos." << endl; //Muestra el tiempo de ejecucion en milisegundos
  cout << "El tiempo de ejecución es de: " << seg << " segundos." << endl; //Muesra el tiempo de ejecucion en segundos
  cout << "El tiempo de ejecución es de: " << min << " minutos." << endl; //Muestra el tiempo de ejecucion en minutos
  cout << "El tiempo de ejecución es de: " << hor << " horas." << endl; //Muestra el tiempo de ejecucion en horas
  cout << "Cantidad de palabras: " << v.size() << endl; //Muestra la cantidad de palabras ordenadas
  return 0;
}