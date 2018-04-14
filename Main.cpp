#include <iostream>
#include <fstream>
#include "Sorting.cpp"

using namespace std;

int main(int argc, char * argv[]){
  char input;
  long numbArray[10000];
  int numbers; int count = 0;
  
  ifstream inFile;
  inFile.open(argv[1]);                         // attempt to open file
  if(!inFile){
    cout << "Unable to open file";
    return EXIT_FAILURE;
  }
  while(inFile >> numbers){                    // Insert all numbers in file into the array
    numbArray[count] = numbers;
    count++;
  }
  
  // Command prompt
  cout << "Commands - insertion-sort (i)\tmerge-sort (m)\tquick-sort (q)" << endl << "Enter the algorithm: ";
  cin >> input;
  
  if(input == 'i'){
    long comparisions =  insertionSort(numbArray);
    cout << "Insertion sort: ";
    for (int i = 0; i < 9999; i++){
      cout << numbArray[i] <<" ";
    } 
    cout << numbArray[9999]<< "\n\tTotal # of comparisons: " << comparisions << endl;
  }
  else if(input == 'm'){
    long comparisions =  mergeSort(numbArray,0,9999);
    cout << "Merge sort: ";
    for (int i = 0; i < 9999; i++){
      cout << numbArray[i] <<" ";
    } 
    cout << numbArray[9999]<< "\n\tTotal # of comparisons: " << comparisions << endl;
  }
  else if(input == 'q'){
    quickSort(numbArray,0,9999);
    long comparisions =  compares;
    cout << "Quick sort: ";
    for (int i = 0; i < 9999; i++){
      cout << numbArray[i] <<" ";
    } 
    cout << numbArray[9999]<< "\n\tTotal # of comparisons: " << comparisions << endl;
  }
  else{
    cout << "ERROR, Invalid_Input\n";
  }
            
  return EXIT_SUCCESS;    
} // main