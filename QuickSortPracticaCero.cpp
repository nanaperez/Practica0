#include <iostream> //Provee los elementos fundamentales para la entrada y salida en C++, es decir su inicializacion
#include <stdio.h> //Libreria que contiene tipos, macros y funciones para la realización de las diferentes tareas
#include <stdlib.h> //Libreria que contiene tipos, macros y funciones para la conversión numérica, generación de números aleatorios, búsquedas y ordenación, gestión de memoria y similares
#include <time.h> //Libreria que contiene tipos, macros y funciones para la la manipulación de información sobre tiempos
#include <string> //Incluye contenedores tipo string para trabajar con cadenas de caracteres
#include <vector> //Incluye contenedores tipo vector, es decir, un arreglo dinamico
#include <sstream> //Flujos hacia/desde cadenas alfanuméricas
#include <cstring> //Define funciones para manipular strings y arreglos
using namespace std; //Espacios de nombres, es decir, nombres de funciones 
int ini, fin; //Variables para el inicio y fin del reloj.
vector <string> v; //Funcion vector creada para recibir los archivos a ordenar


int dividir(int start, int end) // Función para dividir el vector y hacer los intercambios respectivos
{
    int left;
    int right;
    string pivot;
    string tmp;
 
    pivot = v[start]; // El pivote empieza al comienzo
    left = start; // A la izquierda se le asigna el comienzo
    right = end; // A la derecha se le asigna el final
 
    while (left < right) // Mientras no se cruzen la izquierda con la derecha 
    {
        while (v[right] > pivot) // Ciclo
	{
            right--;
        }
 
        while ((left < right) && (v[left] <= pivot)) // Ciclo 
	{
            left++;
        }

        if (left < right) // Si aun no se cruza la izquierda con la derecha seguimos intercambiando
	{
            tmp = v[left];
            v[left] = v[right];
            v[right] = tmp;
        }
    }
 
    // Si ya se han cruzado, ponemos el pivote en el lugar que le corresponde
    tmp = v[right];
    v[right] = v[start];
    v[start] = tmp;
 
    // Retorna la nueva posición del pivot
    return right;
}
 

void OrdQuick(int start, int end) // Funcion recursivo que se encarga de ordenar las palabras
{
    int pivot;
 

    if (start < end) // Condicional
    {
      pivot = dividir(start, end);
    }

    if (start < end) // Condicional
    {
        pivot = dividir(start, end);

        // Ordeno la lista de los menores
        OrdQuick(start, pivot);
 
        // Ordeno la lista de los mayores
        OrdQuick(pivot + 1, end);
    }
}


vector <string> leer_archivo() // Funcion que se encarga de solo lectura de los archivos .txt
{
  freopen("1.txt","r",stdin); // Esta funcion abre un fichero para escritura/reescritura. El parametro es el fichero a abrir, la funcion que se va a cumplir y la accion
  string x;
  vector <string> v;
  while(cin >> x) v.push_back(x);
  return v;
}

int main() // Funcion principal que se encarga de ejecutar todos los metodos anteriores
{  
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
  cout << "\n\nEl tiempo de ejecución es de: " << mil << " Milisegundos." << endl; // Muestra el tiempo de ejecucion en milisegundos
  cout << "El tiempo de ejecución es de: " << seg << " segundos." << endl; // Muesra el tiempo de ejecucion en segundos
  cout << "El tiempo de ejecución es de: " << min << " minutos." << endl; // Muestra el tiempo de ejecucion en minutos
  cout << "El tiempo de ejecución es de: " << hor << " horas." << endl; // Muestra el tiempo de ejecucion en horas
  cout << "Cantidad de palabras: " << v.size() << endl; // Muestra la cantidad de palabras ordenadas
  return 0;
}
