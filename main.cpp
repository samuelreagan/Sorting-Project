/**
 * @file    main.cpp
 *
 *  Project 1: Analyzing Sorting Algorithms
 *
 * @remarks
 *      Course:        CS 4713
 *      Assignment #:  Project 1
 *      Due Date:      October 15, 2018
 *      Instructor:    X. Huang
 *
 * @authors       Sam Reagan, Ariana Garcia
 *                Blake Poush, Carl Thirion
 * @date          October 11, 2018
 */

#include<iostream>
    using std::cin;
    using std::cout;
    using std::endl;
#include <fstream>
   using std::ofstream;
#include <string>
    using std::string;
#include <chrono>
#include <cstdlib>
#include "Sorting.h"

void print(int arr[], int size);
void fill_arrays(int random[], int ascend[], int reverse[], int size);

/** Array Sizes -- Commented the others out b/c of compilation warning */
const int TEST_ONE   = 100; 
//const int TEST_TWO   = 1000; 
//const int TEST_THREE = 10000; 
//const int TEST_FOUR  = 30000; 

//This is not how main will look, this is just to test the sorts
int main() { 
    // Declare Test Arrays
    int random_1[TEST_ONE];
    int ascend_1[TEST_ONE];
    int reverse_1[TEST_ONE];

    //Fill Arrays
    fill_arrays(random_1, ascend_1, reverse_1, TEST_ONE);

    //Print Arrays Before sorting
    cout << "Before Sorting: " << endl;
    cout << "Random: ";
    print(random_1, TEST_ONE);
    cout << "\nAscending: ";
    print(ascend_1, TEST_ONE);
    cout << "\nReverse: ";
    print(reverse_1, TEST_ONE);
    cout << endl << endl;

    //Sort Arrays
    binary_insertion_sort(random_1, TEST_ONE);
    binary_insertion_sort(ascend_1, TEST_ONE);
    binary_insertion_sort(reverse_1, TEST_ONE);

    //Print Arrays
    cout << "After Sorting: " << endl;
    cout << "Random: ";
    print(random_1, TEST_ONE);
    cout << "\nAscending: ";
    print(ascend_1, TEST_ONE);
    cout << "\nReverse: ";
    print(reverse_1, TEST_ONE);
    cout << endl << endl;

    return 0;
}

/** Test Function to Test Sorting Algoithms */
void print(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
 * @brief This function fill the three arrays and puts
 *        them in their desired order.
 *
 * @param random[in/out]   The array to be sorted in random order.
 * @param ascend[in/out]   The array to be sorted in ascending order.
 * @param reverse[in/out]  The array to be sorted in reverse order.
 * @param size             The size of the arrays.
 *
 */
void fill_arrays(int random[], int ascend[], int reverse[], int size) {
    for(int i = 0; i < size; i++) {
        random[i]  = rand() % 1000;
        ascend[i]  = i;
        reverse[i] = size - i;
    }
}