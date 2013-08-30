#include <iostream>
#include <cmath>
#include <vector>
#include <string> // For getline()
#include <sstream>
using namespace std;

const int SIZE = 11;  // Assuming array size = 10, 1-indexed

void maxHeapify(vector<string>& iVector, int i, int heapSize) {
  int l = 2 * i;
  int r = 2 * i + 1;
  int largest;
  if(l <= heapSize && iVector[l] > iVector[i]) 
    largest = l;
  else
    largest = i;

  if(r <= heapSize && iVector[r] > iVector[largest])
    largest = r;

  if(largest != i) {
    swap(iVector[i], iVector[largest]);
    maxHeapify(iVector, largest, heapSize);   
  }
}

void buildMaxHeap(vector<string>& iVector, int heapSize) {
  for(int i = floor(SIZE / 2); i >= 1; i--)
    maxHeapify(iVector, i, heapSize);
}

void heapSort(vector<string>& iVector) {
  int heapSize = iVector.size() - 1; 
  buildMaxHeap(iVector, heapSize);
  for(int i = iVector.size()-1; i>=2; i--) {
    swap(iVector[1], iVector[i]);
    heapSize--;
    maxHeapify(iVector, 1, heapSize);
  }
}

void getUserInput(vector<string>& iVector) {
  for(int i = 1; i < SIZE; i++) {
      string s;
      int in;
      stringstream checker;
      getline(cin, s);
      checker << s;
      iVector[i] = s;
  }
}

void displayOutput(vector<string>& iVector) {
  cout <<  "The sorted list is: " << endl;

  for(int i = 1; i < iVector.size() - 1; i++)
    cout << iVector[i] << " -- ";

  cout << iVector[iVector.size() - 1] << endl;
  cout << "HeapSort successful." << endl;
}

int main() {

  vector<string> iVector;
  iVector.resize(SIZE); // Or use ::push_back()

  cout << "Enter 10 numbers below: " << endl;
  getUserInput(iVector);

  heapSort(iVector);

  displayOutput(iVector); 

  return 0;
}