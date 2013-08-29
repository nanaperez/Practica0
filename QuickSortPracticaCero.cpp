#include <iostream> //Provee los elementos fundamentales para la entrada y salida en C++, es decir su inicializacion
#include <stdio.h> //Libreria que contiene tipos, macros y funciones para la realización de las diferentes tareas
#include <stdlib.h> //Libreria que contiene tipos, macros y funciones para la conversión numérica, generación de números aleatorios, búsquedas y ordenación, gestión de memoria y similares
#include <time.h> //Libreria que contiene tipos, macros y funciones para la la manipulación de información sobre tiempos
#include <string> //Incluye contenedores tipo string para trabajar con cadenas de caracteres
#include <vector> //Incluye contenedores tipo vector, es decir, un arreglo dinamico
#include <sstream> //Flujos hacia/desde cadenas alfanuméricas
#include <cstring> //Define funciones para manipular strings y arreglos
using namespace std; //Espacios de nombres, es decir, nombres de funciones 
int ini, fin; //Variables para el inicio y fin del reloj
vector <string> v; //Funcion vector creada con varaibles strings para recibir los archivos a ordenar

// Función para dividir el array y hacer los intercambios    
int divide(int start, int end) 
{
    int left;
    int right;
    string pivot;
    string temp;
 
    pivot = v[start];
    left = start;
    right = end;
 
    // Mientras no se cruzen los índices
    while (left < right) 
    {
        while (v[right] > pivot) 
	{
            right--;
        }
 
        while ((left < right) && (v[left] <= pivot)) 
	{
            left++;
        }
 
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right)
	{
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
 

    if (start < end) {
      pivot = divide(start, end);
	}

    if (start < end) 
    {
        pivot = divide(start, end);

        // Ordeno la lista de los menores
        OrdQuick(start, pivot);
 
        // Ordeno la lista de los mayores
        OrdQuick(pivot + 1, end);
    }
}

vector <string> leer_archivo() //Metodo que se encarga de solo lectura de los archivos .txt
{
  freopen("1.txt","r",stdin); //Esta funcion abre un fichero para escritura/reescritura. El parametro es el fichero a abrir, la funcion que se va a cumplir y la accion
  string x;
  vector <string> v;
  while(cin >> x) v.push_back(x);
  return v;
}

int main() //Metodo principal que se encarga de ejecutar todos los metodos anteriores
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
  cout << "\n\nEl tiempo de ejecución es de: " << mil << " Milisegundos." << endl; //Muestra el tiempo de ejecucion en milisegundos
  cout << "El tiempo de ejecución es de: " << seg << " segundos." << endl; //Muesra el tiempo de ejecucion en segundos
  cout << "El tiempo de ejecución es de: " << min << " minutos." << endl; //Muestra el tiempo de ejecucion en minutos
  cout << "El tiempo de ejecución es de: " << hor << " horas." << endl; //Muestra el tiempo de ejecucion en horas
  cout << "Cantidad de palabras: " << v.size() << endl; //Muestra la cantidad de palabras ordenadas
  return 0;
}
