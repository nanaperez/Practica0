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
	if(n==0)return;
    int i,k,v,h,j;
    for(i=n/2;i>0;i--) //we start at i=n/2 as it gives index of right most sub-tree's parent
    {
        k=i;
        v=a[k];        //this assigns the value of parent node of the sub-tree under consideration to variable v
        h=0;
        while(!h&&2*k<=n) //checking whether array is heapified
        {
            j=2*k;
            if(j<n)          //checking if given sub-tree has 2 children
            {
                if(a[j]<a[j+1])j++;  //variable j points to higher valued node between the 2 children
            }
            if (v>=a[j])  //if parent node of the sub-tree is >= to the greater child, no need to heapify
                h=1;
            else               //else swap contents of parent and child using variables k and j
            {
                a[k]=a[j]; 
                k=j;
            }
        }
        a[k]=v;
    }
    maxd();
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
