#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
using namespace std;
int ini, fin;
vector <string> v; 

void shiftRight(int low, int high)
{
    //cout << low << endl;
    //cout << high << endl;
    int root = low;
    while ((root*2)+1 <= high)
    {
        
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        /*Check if root is less than left child*/
        if (v[swapIdx] < v[leftChild])
        {
            swapIdx = leftChild;
        }
        /*If right child exists check if it is less than current root*/
        if ((rightChild <= high) && (v[swapIdx] < v[rightChild]))
        {
            swapIdx = rightChild;
        }
        /*Make the biggest element of root, left and right child the root*/
        if (swapIdx != root)
        {
            string tmp = v[root];
            v[root] = v[swapIdx];
            v[swapIdx] = tmp;

            //cout << "tmp1 " << tmp << endl;
            //cout << "v[root]2 " << v[root] << endl;
            //cout << "v[swapIdx]3 " << v[swapIdx] << endl;
            /*Keep shifting right and ensure that swapIdx satisfies
            heap property aka left and right child of it is smaller than
            itself*/
            root = swapIdx;
        }
        else
        {
            break;
        }
    }
    return;
}


void heapify(int low, int high)
{
    cout << "heapify" << endl;
    /*Start with middle element. Middle element is chosen in
    such a way that the last element of array is either its
    left child or right child*/
    int midIdx = (high - low -1)/2;
    //cout << low << endl;
    //cout << high << endl;
    //cout << midIdx << endl;
    while (midIdx >= 0)
    {
        //cout << midIdx << endl;
        //cout << high << endl;
        shiftRight(midIdx, high);
        --midIdx;
    }
    return;
}

vector <string> leer_archivo()
{
  freopen("1.txt","r",stdin);
  string x;
  vector <string> v;
  while(cin >> x) v.push_back(x);
  return v;
}

void heapSort()
{
    cout << "heapsort" << endl;
    //cout << v.size()-1 << endl;
    heapify(0, v.size()-1);
    int high = v.size() - 1;
    while (high > 0)
    {
        /*Swap max element with high index in the array*/
        string tmp = v[high];
        v[high] = v[0];
        v[0] = tmp;
        --high;
        /*Ensure heap property on remaining elements*/
        shiftRight(0, v.size()-1);
    }
    return;
}

int main(){
    cout << "Empezando" << endl;
     v = leer_archivo();
     heapSort();
     for (int i = 0; i<v.size(); i++)
        cout << v[i] << endl;
    return 0;
}