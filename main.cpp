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
#include <iomanip>
    using std::setw;
    using std::setfill;
#include "Sorting.h"

int menu();
void print(int arr[], int size);
void fill_arrays(int random[], int ascend[], int reverse[], int size);
void printMenu(int subMenu);
void sort(int size, string sortType, string sortOrder);
/** Array Sizes -- Commented the others out b/c of compilation warning */
const int TEST_ONE   = 100; 
//const int TEST_TWO   = 1000; 
//const int TEST_THREE = 10000; 
//const int TEST_FOUR  = 30000; 

//This is not how main will look, this is just to test the sorts
int main() { 

    /******************MENU******************/
    menu();

    /****************END MENU****************/
    /*
    // Declare Test Arrays
    int* random_1  = new int[size];
    int* ascend_1  = new int[size];
    int* reverse_1 = new int[size];

    //Fill Arrays
    fill_arrays(random_1, ascend_1, reverse_1, size);

    //Print Arrays Before sorting
    cout << "Before Sorting: ";
    cout << "\nRandom:";
    print(random_1, size);
    cout << "\nAscending: ";
    print(ascend_1, size);
    cout << "\nReverse: ";
    print(reverse_1, size);
    cout << endl << endl;

    //Sort Arrays
    binary_insertion_sort(random_1, size);
    binary_insertion_sort(ascend_1, size);
    binary_insertion_sort(reverse_1, size);

    //Print Arrays
    cout << "After Sorting: ";
    cout << "\nRandom: ";
    print(random_1, size);
    cout << "\nAscending: ";
    print(ascend_1, size);
    cout << "\nReverse: ";
    print(reverse_1, size);
    cout << endl << endl;
    */
    return 0;
}

/** Test Function to Test Sorting Algoithms */
void print(int arr[], int size) {
    cout << endl;
    for(int i = 0; i < size && i < 100; i++) {
        if(i % 10){
            cout << setw(4) << setfill(' ') << arr[i];
        }
        else{
            cout << "\n\n" << setw(4) << setfill(' ') << arr[i];
        }
    }
    cout << "\n\n";
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
void fill_arrays(int random[], int ascend[], int decending[], int size) {
    for(int i = 0; i < size; i++) {
        random[i]  = rand() % 1000;
        ascend[i]  = i;
        decending[i] = size - i;
    }
}

void printMenu(int subMenu){
    cout << setw(15) << setfill('-'); 
    cout << subMenu;
    cout << setw(15) << setfill('-') << "";
    cout << endl;
    switch (subMenu){
        case 1:{
            cout << "1) Run a specific sort\n"
                 << "2) Run all sorts\n"; 
        }
        break;
        case 2:{
            cout << "1) Selection Sort\n"
                 << "2) Bubble Sort\n"
                 << "3) Insertion Sort\n"
                 << "4) Modified Insertion Sort\n"
                 << "5) Merge Sort\n"
                 << "6) Quick Sort\n"
                 << "7) Randomized Quick Sort\n"
                 << "8) Heap Sort\n";
        }
        break;
        case 3:{
            cout << "Input size of testing array: ";
        }
        break;
        case 4:{
            cout << "Select Array type\n"
                 << "1) Random Order\n"
                 << "2) Ascending Order\n"
                 << "3) Decending Order\n"
                 << "4) All\n";

        }
        break;
        default:{
            cout << "Exiting...\n";
        }
        break;
    }
}

int menu(){
    int subMenu = 1;
    int selection = 1;
    string sortType = "all";
    string sortOrder;
    int size;

    while(selection){
        system("clear");
        printMenu(subMenu);
        if(subMenu == 3){
            cin >> size; 
        }
        else{
            cin >> selection;
        }
        switch (subMenu){
            case 1:{
                switch (selection){
                    case 1:subMenu = 2;
                    break;
                    case 2:subMenu = 3;
                    break;
                }
            }
            break;
            case 2:{
                switch (selection){
                    case 1: sortType = "selection_sort";
                    case 2: sortType = "bubble_sort";
                    case 3: sortType = "insertion_sort";
                    case 4: sortType = "binary_insertion_sort";
                    case 5: sortType = "merge_sort";
                    case 6: sortType = "quick_sort";
                    case 7: sortType = "random_quick_sort";
                    case 8: sortType = "heap_sort";
                }
                subMenu = 3;
            }
            break;
            case 3:{
                subMenu = 4;
            }
            break;
            case 4:{
                switch (selection){
                    case 1: sortOrder = "random";
                    case 2: sortOrder = "ascending";
                    case 3: sortOrder = "decending";
                    case 4: sortOrder = "all";
                }
                subMenu = 0;
                selection = 0;
                sort(size,sortType,sortOrder);
            }
            break;
            default: exit(0);
        }
    }
    return size;   
}
void sort(int size, string sortType, string sortOrder){
    void (*sort_func)(int[],int);
    int* random     = new int[size];
    int* ascending  = new int[size];
    int* decending    = new int[size];
    fill_arrays(random, ascending, decending, size);
    //Determine Sort Types
    if(sortType == "selection_sort"){
        sort_func = &selection_sort;
    }
    else if(sortType == "bubble_sort"){
        sort_func = &bubble_sort;
    }
    else if(sortType == "insertion_sort"){
        sort_func = &insertion_sort;
    }
    else if(sortType == "binary_insertion_sort"){
        sort_func = &binary_insertion_sort;
    }
    else if(sortType == "merge_sort"){
        sort_func = &merge_sort;
    }
    else if(sortType == "quick_sort"){
        sort_func = &quick_sort;
    }
    else if(sortType == "random_quick_sort"){
        sort_func = &random_quick_sort;
    }
    else if(sortType == "heap_sort"){
        sort_func = &heap_sort;
    }
    else{ //sortType = "all"
        sort_func = &all_sorts;
    }

    //Determine Sorting Order
    if(sortOrder == "random"){
        cout << "Before Sorting: ";
        cout << "\nRandom:";
        print(random, size);
        (*sort_func)(random,size);
        cout << "After Sorting: ";
        cout << "\nRandom:";
        print(random, size);
    }
    else if(sortOrder == "ascending"){
        cout << "Before Sorting: ";
        cout << "\nAscending: ";
        print(ascending, size);
        (*sort_func)(ascending,size);
        cout << "After Sorting: ";
        cout << "\nAscending: ";
        print(ascending, size);
    }
    else if(sortOrder == "decending"){
        cout << "Before Sorting: ";
        cout << "\nDecending: ";
        print(decending, size);
        (*sort_func)(decending,size);
        cout << "After Sorting: ";
        cout << "\nDecending: ";
        print(decending, size);
    }
    else{ //sortOrder = "all"
        cout << "Before Sorting: ";
        cout << "\nRandom:";
        print(random, size);
        (*sort_func)(random,size);
        cout << "After Sorting: ";
        cout << "\nRandom:";
        print(random, size);

        cout << "Before Sorting: ";
        cout << "\nAscending: ";
        print(ascending, size);
        (*sort_func)(ascending,size);
        cout << "After Sorting: ";
        cout << "\nAscending: ";
        print(ascending, size);

        cout << "Before Sorting: ";
        cout << "\nDecending: ";
        print(decending, size);
        (*sort_func)(decending,size);
        cout << "After Sorting: ";
        cout << "\nDecending: ";
        print(decending, size);
    }

    //menu();
}