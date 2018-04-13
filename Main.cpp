#include <iostream>
#include <fstream>
#include "Sorting.cpp"

using namespace std;

int main(int argc, char * argv[]){
  char input;
  int numbArray[10000];
  int count = 0;
  int numbers;
  // Command prompt
  cout << "Commands - insertion-sort (i)\tmerge-sort (m)\tquick-sort (q)" << endl << "Enter the algorithm: ";
  cin >> input;
  ifstream inFile;
  inFile.open(argv[1]);       // attempt to open file
  if(!inFile){
    cout << "Unable to open file";
    return EXIT_FAILURE;
  }
  while(inFile >> numbers){                    // Insert all numbers in file into an array
    numbArray[count] = numbers;
    count++;
  }
  if(input == 'i'){
    long comparisions =  insertionSort(numbArray);
    cout << "Insertion sort: ";
    for (int i = 0; i < 5; i++){
      cout << numbArray[i] <<" ";
    } 
    cout << "\n\tTotal # of comparisons: " << comparisions << endl;
  }
  else if(input == 'm'){
    long comparisions =  mergeSort(numbArray,0,9999);
    cout << "Merge sort: ";
    for (int i = 0; i < 5; i++){
      cout << numbArray[i] <<" ";
    } 
    cout << "\n\tTotal # of comparisons: " << comparisions << endl;
  }
  else if(input == 'q'){
    quickSort(numbArray,0,9999);
    long comparisions =  compares;
    cout << "Quick sort: ";
    for (int i = 0; i < 5; i++){
      cout << numbArray[i] <<" ";
    } 
    cout << "\n\tTotal # of comparisons: " << comparisions << endl;
  }
  else{
  
  }
            
  return EXIT_SUCCESS;    
} // main