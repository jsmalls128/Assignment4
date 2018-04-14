long compares = 0;                                       // comparison counter for merge and quick sort

void swap(int index1, int index2, long numbers[]){
  int temp;
  temp = numbers[index2];
  numbers[index2] =  numbers[index1];
  numbers[index1] = temp;  
}

long insertionSort(long numbers[]){
  int comparisons = 0;
  int size = 10000;
  for(int count = 0; count < size; count++){
    
    bool finished = false;
    int current = count;
    bool moreToSearch = (current != 0);
    
    while(moreToSearch && !finished){
      comparisons++;
      if (numbers[current] < numbers[current-1]){
        swap(current,current-1,numbers);
        current--;
        moreToSearch = (current != 0);
      }
      else
        finished = true;
    }
  }
  return comparisons;
}

void merge(long numbers[], int leftFirst, int leftLast, int rightFirst, int rightLast){
  int tempArr[10000];
  int leftBegin = leftFirst;
  int rightBegin =  rightFirst;
  int count = 0;
    
    while ((leftBegin <= leftLast) && (rightBegin <= rightLast))
    {
      compares++;
        if (numbers[leftBegin] < numbers[rightBegin])
        {
            tempArr[count++] = numbers[leftBegin++];
        }
        else
        {
            tempArr[count++] = numbers[rightBegin++];
        }
    }
 
    // copy the remaining elements of left side of merge if there are any
    while (leftBegin <= leftLast)
    {
        tempArr[count++] = numbers[leftBegin++];
    }
 
    // copy the remaining elements of right side of merge if there are any
    while (rightBegin <= rightLast)
    {
      tempArr[count++] = numbers[rightBegin++];
    }
    
    // copies sorted numbers from temp array to the original array
    for(leftBegin = leftFirst, rightBegin = 0; leftBegin <= rightLast; leftBegin++, rightBegin++){
      numbers[leftBegin] = tempArr[rightBegin]; 
    }
}

long mergeSort(long numbers[], int left, int right){
  long comparisons = 0;
    if (left < right)
    {
        int m = (left+right)/2;
 
        // sort first and second halves
        mergeSort(numbers, left, m);
        mergeSort(numbers, m+1, right);
 
        merge(numbers, left, m, m+1, right);
    }
   comparisons = compares;
   return comparisons;
}

void quickSort(long numbers[], int leftStart, int rightStart){
  int left, right, pivot;
  if(leftStart >= rightStart) return;
  
  pivot = numbers[(leftStart+rightStart)/2];
  left = leftStart;
  right = rightStart;
  
  // counts the initial compares for each while loop
  compares++;
  compares++;
  
  while(left <= right){
    while(numbers[left] < pivot){ compares++; left++;}
    while(numbers[right] > pivot){ compares++; right--;}
    if(left <= right){
      swap(left, right, numbers);
      left++; right--;
    }
  }
   
  quickSort(numbers, leftStart,right);
  quickSort(numbers,left,rightStart);
}