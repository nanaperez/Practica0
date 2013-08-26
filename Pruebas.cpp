#include<iostream>
#include<algorithm>
using namespace std;
int x;
class heap
{
    int a[30],n;// a[30] to store the input

public:
    void read()
    {
        cout<<"Enter the size\n";
        cin>>n;
        x=n;
        cout<<"Enter the elements\n";
        for(int i=1;i<=n;i++)cin>>a[i];
    }
    void heapsort();
    void maxd()
    {
        swap(a[1],a[n]);   //swap first and last element
        n--;                      //decrease size of array by 1
        heapsort();            //call heapsort function
    }
    void disp()
    {
        cout<<"Sorted Array is\n";
        for(int i=1;i<=x;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
};

void heap::heapsort()
{
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

int main()
{
    heap H;//object created
    H.read();//read function to read input//leerarchivo()
    H.heapsort();//to perform heapsort
    H.disp();//to display sorted array
    return 0;
}
