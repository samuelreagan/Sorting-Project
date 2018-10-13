/**
 * @file    Sorting.h
 *
 * Function definitions for Selection Sort, Bubble Sort,
 * Insertion Sort, Binary Insertion Sort, Merge Sort, 
 * Quick Sort, Random Quicksort, and Heap Sort
 *
 * @authors  Sam Reagan, Ariana Garcia
 *           Blake Poush, Carl Thirion
 * 
 * @date    October 11, 2018
 */

#ifndef SORTING_H
#define SORTING_H

#include <algorithm>
  using std::swap;
#include <cmath>
  using std::log;
  using std::floor;
#include <queue>
  using std::queue;
#include <random>
  using std::rand;

/********** Selection Sort **********/
/*
 * @brief This function sorts the contents of an array
 *        using the selection sort. This algorithm finds
 *         the smallest array element and exchanges it
 *        with the element at the first array index. It
 *        contiues to do this by finding the next smallest
 *        value and switching it to the correct place until
 *        the whole array is sorted.
 *
 *
 * @param arr    The array that contains the data.
 * @param size   The size of the array.
 *
 */
void selection_sort  (int arr[], int size) {
  int minValue, minIndex;
  for(int i = 0; i < size - 1; i++) {
    minValue = arr[i];
    minIndex = i;
    for(int j = i + 1; j < size; j++) {
      if(arr[j] < minValue) {
        minIndex = j;
        minValue = arr[j];
      }
    }
    arr[minIndex] = arr[i];
    arr[i] = minValue;
  }
}

/********** Bubble Sort **********/
/*
 * @brief This function sorts the contents of an array
 *        using the bubble sort algorithm. The array is
 *        scanned sequentially and two elements are
 *        switched if they're out of order.
 *
 * @param arr    The array that contains the data.
 * @param size   The size of the array.
 *
 */
void bubble_sort(int arr[], int size) {
  bool swap;
  int temp;

  do {
    swap = false;
    for(int count = 0; count < (size - 1); count++) {
      if(arr[count] > arr[count + 1]) {
        temp = arr[count];
        arr[count] = arr[count + 1];
        arr[count + 1] = temp;
        swap = true;
      }
    }
  } while(swap);
}

/********** Insertion Sort **********/
/*
 * @brief This function sorts the contents of an array
 *        using insertion sort. This algorithm
 *        interchanges array elements only if a exchange
 *        needs to take place but only one at a time.
 *
 * @param arr    The array that contains the data.
 * @param size   The size of the array.
 *
 */
void insertion_sort (int arr[], int size) {
  for(int i = 1, j; i < size; i++) {
    int temp = arr[i];
    for(j = i; j > 0 && temp < arr[j - 1]; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = temp;
  }
}

/********** Binary Insertion Sort **********/
/*
 * @brief This function sorts the contents of an array
 *        using insertion sort and binary search.
 *
 * @param arr    The array that contains the data.
 * @param size   The size of the array.
 *
 */
void binary_insertion_sort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int temp = arr[i];
        int left = 0;
        int right = i;
        while(left < right) {
            int middle = (left + right) / 2;
            if(temp >= arr[middle]) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        for(int j = i; j > left; j--) {
            swap(arr[j-1], arr[j]);
        }
    }
}

/********** Merge Sort **********/
/**
 * @brief        This function merges two subarrays located in the left and
 *               right halves of arr[] into a temporaroy array in sorted order.
 *               Then the temporary array is loaded back into the original array.
 *               The left subarray starts at i and ends at mid. The right subarray
 *               starts at j and ends at last.
 *
 * @param arr[in/out]             The array that containst the values to be merged.
 * @param first                   The first index of an array.
 * @param last                    The last index of an array.
 */
void merge(int arr[], int first, int last) {
  int mid = (first + last) / 2;  //Left Subarray End
  int i = first;                 //Left Subarray Start
  int j = mid + 1;               //Right Subarray Start
  int k = 0;                     //Index Counter
  int* temp= new int[last - first + 1];    //Temporary Array
  //Merge the Two Subarrays into Temp
  while(i <= mid && j <= last) {
    if(arr[i] < arr[j]) {
      temp[k] = arr[i];
      i++;
      k++;
    }
    else {
      temp[k] = arr[j];
      j++;
      k++;
    }
  }
  //Insert Remaining Values in the Left Subarray into Temp
  while(i <= mid) {
    temp[k] = arr[i];
    i++;
    k++;
  }
  //Insert Remaining Values in the Rigth Subarray into Temp
  while(j <= last) {
    temp[k] = arr[j];
    j++;
    k++;
  }
  //Load Temp Back Into the Original Array
  for(i = first; i <= last; i++) {
    arr[i] = temp[i - first];
  }
}

/**
 * @brief        This function mergesorts an array in ascending order
 *               by sorting and merging the left and right halves of the
 *               array recursively.
 *
 * @param arr[in/out]             The array to be sorted.
 * @param first                   The first index of an array.
 * @param last                    The last index of an array.
 */
void merge_sort(int arr[], int first, int last) {
  if(first < last) {
    int mid = (first + last) / 2;
    merge_sort(arr, first, mid);
    merge_sort(arr, mid + 1, last);
    merge(arr, first, last);
  }
}

/**
 * @brief        This function mergesorts an array in ascending order
 *               by calling the other less-user friendly mergesort
 *               function.
 *
 * @param arr[in/out]             The array to be sorted.
 * @param size                    The size of the array.
 */
void merge_sort(int arr[], int size) {
  merge_sort(arr, 0, size - 1);
}

/********** Quick Sort **********/
/**
 * @brief        This function partitons an array based on the choice
 *               of a pivot index. The values less that the value at
 *               the pivot index are on the left and the values greater
 *               than the pivot index value are on the right.
 *
 * @param arr[in/out]             The array to be partioned.
 * @param left_index              The left index of an array.
 * @param right_index             The right index of an array.
 *
 * @return The pivot index of an array.
 */
int partition(int arr[], int left_index, int right_index, bool is_random_pivot) {
  // Ternary operator to determine if the pivot should be random or the last element.
  int pivot_index = (is_random_pivot == true) ? rand() % (right_index - left_index + 1) + left_index : right_index; 
  int pivot_value = arr[pivot_index];                       // pivot value for easy reference
  swap(arr[pivot_index], arr[right_index]);                 // move pivot to end (out of the way)
  pivot_index = left_index;                                 // start looking for "correct" location
  for(int i = left_index; i <= right_index - 1; i++){       // each i from left_index to right_index-1: // by scanning the entire arr
    if(arr[i] < pivot_value){                               // if value smaller than pivot is found
      swap(arr[i], arr[pivot_index]);                       // swap it into left partition
      pivot_index++;
    }
  }                                                         // and move the dividing point
  swap(arr[pivot_index], arr[right_index]);                 // swap pivot into its correct location
  return pivot_index;                                       // and return the location of the split
}
/**
 * @brief        This function quicksorts an array in ascending order
 *               using recursion based on the left and right index.
 *
 * @param arr[in/out]             The array to be partioned.
 * @param left_index              The left index of an array.
 * @param right_index             The right index of an array.
 */
void quick_sort(int arr[], int left_index, int right_index) {
  if(left_index < right_index){                                    // being "unsorted" requires 2 or more values...
    int division = partition(arr, left_index, right_index, false);        // smaller values to left of division, larger to right
    quick_sort(arr, left_index, division-1);                        // now quicksort everything left of division
    quick_sort(arr, division+1, right_index);                       // and everything right of division
  }
  return;
}

/**
 * @brief        This function quicksorts an array in ascending order
 *               by calling the other less-user friendly quicksort
 *               function.
 *
 * @param arr[in/out]             The array to be partioned.
 * @param size                    The size of the array.
 */
void quick_sort(int arr[], int size) {
  quick_sort(arr, 0, size - 1);
}

/********** Random Quick Sort **********/
/**
 * @brief        This function quicksorts an array in ascending order
 *               using recursion based on the left and right index.
 *
 * @param arr[in/out]             The array to be partioned.
 * @param left_index              The left index of an array.
 * @param right_index             The right index of an array.
 */
void random_quick_sort(int arr[], int left_index, int right_index) {
  if(left_index < right_index){                                    // being "unsorted" requires 2 or more values...
    int division = partition(arr, left_index, right_index, true);        // smaller values to left of division, larger to right
    random_quick_sort(arr, left_index, division-1);                        // now quicksort everything left of division
    random_quick_sort(arr, division+1, right_index);                       // and everything right of division
  }
  return;
}

/**
 * @brief        This function quicksorts an array in ascending order
 *               by calling the other less-user friendly quicksort
 *               function.
 *
 * @param arr[in/out]             The array to be partioned.
 * @param size                    The size of the array.
 */
void random_quick_sort(int arr[], int size) {
  random_quick_sort(arr, 0, size - 1);
}

/********** Heap Sort **********/
/**
 * @brief        This function calculates the index of the left child
 *               for a parent index.
 *
 * @param i      The index of the parent.
 *
 * @return       The index of the left child.
 */
int left(int i){         // calculate index of left child
   return 2 * i + 1;     // which must be bounds-checked!
}

/**
 * @brief        This function calculates the index of the right child
 *               for a parent index.
 *
 * @param i      The index of the parent.
 *
 * @return       The index of the right child.
 */
int right(int i){        // calculate index of right-child
   return 2 * i + 2;     // which must be bounds-checked!
}

/**
 * @brief        This function calculates the index of the parent
 *               for a given child index.
 *
 * @param i      The index of the child.
 *
 * @return The index of the parent.
 */
int parent(int i){       // parent is at floor( (i+1)/2 )
   return (i - 1) / 2;   // this too must be bounds-checked!
}

/**
 * @brief        This function sifts values down the max heap in order
 *               to restore the max heap property.
 *
 * @param heap_array[in/out]      The array with the heap property.
 * @param left_index              The left index of an array.
 * @param right_index             The right index of an array.
 */
void max_heap_sift_down(int heap_array[], int left_index, int right_index){
  bool done = false;                                                                 // assume there is work to be done
  int i     = left_index;                                                            // starting with the "root" (left-most item)
  while(!done && left(i) <= right_index){                                            // scanning until done or h[i] has no children
      int max_child = left(i);                                                       // assume left child is max
      if(right(i) <= right_index && heap_array[right(i)] > heap_array[left(i)]){     // see if right child exists and is larger than left
          max_child = right(i);                                                      // if so, mark right child as max_child
      }
      if(heap_array[max_child] > heap_array[i]){                                     // if the max_child is bigger than h[i]
          swap(heap_array[max_child], heap_array[i]);                                // swap h[i] with its max_child
          i = max_child;                                                             // and continue scanning from that index
      }
      else{                                                                          // otherwise, no swap was made, so
          done = true;                                                               // the heap property holds, and we can stop
      }
  }
  return;
}

/**
 * @brief        This function is a simpler interface for the max_heap_sift_down
 *               function. This function accepts only the array and the size.
 *
 * @param heap_array[in/out]      The array with the heap property.
 * @param heap_size               The size of the heap_array (not array size).
 */
void max_heap_sift_down(int heap_array[], int heap_size){
  max_heap_sift_down(heap_array, 0, heap_size-1);     // calls the more general algorithm shown below
}

/**
 * @brief        This function removes the max value from the max heap and
 *               uses the max_heap_sift_down function to restore the max heap
 *               property.
 *
 * @param heap_array[in/out]      The array with the heap property.
 * @param heap_size[out]          The size of the heap(passed by reference).
 *
 * @return The max value that was removed from the heap.
 */
int heap_remove(int heap_array[], int & heap_size) {
  int result = heap_array[0];                         // save the result to return later
  swap(heap_array[0], heap_array[heap_size-1]);       // swap root to the end
  heap_size--;                                        // mark the heap as one item smaller
  max_heap_sift_down(heap_array, heap_size);          // sift down the element just swapped to root

  return result;
}

/**
 * @brief        This function "heapifys" an array so that its becomes a
 *               a max heap using the bottom up algorithm.
 *
 * @param arr[in/out]      The array that will have the max heap property.
 * @param size             The size of the array.
 */
void make_max_heap_bottom_up(int arr[], int size){
  int subroot = parent(size - 1);                     // start with the last non-leaf node
  while(subroot >= 0){                                // run until we reach the true root
    max_heap_sift_down(arr, subroot, size-1);         // sift down the new subroot's value
    subroot--;
  }
}

/**
 * @brief        This function heap sorts an array in ascending order
 *               by making an array into a max heap and then "removing"
 *               the values from the heap. The array is left in order
 *               when the function ends.
 *
 * @param arr[in/out]           The array to be partioned.
 * @param size                  The size of the array.
 */
void heap_sort(int arr[], int size){
  make_max_heap_bottom_up(arr, size);                 // begin by making the array a heap
  int elements_remaining = size;                      // store the initial number of elements
  while(elements_remaining > 1){                      // while the unsorted part of the array is non-empty
    heap_remove(arr, elements_remaining);             // "remove" the max (which moves it to the end!)
  }
}

void all_sorts(int arr[], int size){
  cout << "This feature is unavailable at this time.\n"
       << "In the meantime, enjoy this ASCII wizard on a skateboard.\n"
       << "<O<-<|8\n";
}
#endif
