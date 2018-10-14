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
#include <map>
#include <vector>
#include "Sorting.h"
#include "Menu.h"

void print(int arr[], int size);
void fill_arrays(int random[], int ascend[], int descending[], int size);
void create_csv(string file_name);
void benchmarks(int(*funct)(int[],int), string sort_name);
double sort_time(int(*func_ptr)(int [], int),int array[], int size, double& count);
void write_to_csv(double arr[], string filename, string sort_name);
const int NUM_SORTS   = 8;
const int NUM_ARRAYS  = 12;
const int NUM_TESTS   = 4;
const int NUM_FILES   = 2;


int main() { 
    /** Create CSV Files */
    create_csv("num_comparisons.csv");
    create_csv("times.csv");

    /** Benchmark Sorts */
    string sort_names[NUM_SORTS] = {"selection", "bubble", "insertion", "modified insertion", "quick", "randomized quick", "merge", "heap"};
    std::vector<int(*)(int[],int)> sorting_functions = {&selection_sort,&bubble_sort,&insertion_sort,&binary_insertion_sort,&quick_sort,&random_quick_sort,&merge_sort,&heap_sort};
    
    for(int i = 0; i < NUM_SORTS; i++) {
        benchmarks(sorting_functions[i], sort_names[i]);
    }

    return 0;
}

void write_to_csv(double arr[], string filename, string sort_name) {
    ofstream fout(filename, std::ios::out | std::ios::app);
    if(fout.is_open()) {
        fout << sort_name << ",";
        for(int i = 0; i < NUM_ARRAYS; i++) {
            fout << arr[i];
            if(i < NUM_ARRAYS - 1) {
                fout << ",";
            } else {
                fout << endl;
            }
        }
    }
}

void benchmarks(int(*funct)(int[],int), string sort_name) {
    double times[NUM_ARRAYS];
    double comps[NUM_ARRAYS];
    int sizes[NUM_TESTS] = {100,1000,10000,30000};
    
    /** Run Benchmarks for Each of the Array Sizes */
    for(int j = 0; j < NUM_TESTS; j++) {
        int* random       = new int[sizes[j]];
        int* ascending    = new int[sizes[j]];
        int* descending    = new int[sizes[j]];
        fill_arrays(random, ascending, descending, sizes[j]);

        times[j*3] = sort_time(funct, ascending, sizes[j],comps[j*3]);
        times[j*3+1] = sort_time(funct, descending, sizes[j],comps[j*3+1]);
        times[j*3+2] = sort_time(funct, random, sizes[j], comps[j*3+2]);
    }

    /** Printing Data --- Test*/
    for(int i = 0; i < 12; i++) {
        cout << "Times: " << std::setprecision(10) << times[i] << endl;
        cout << "Comparisons: " << std::setprecision(10) << comps[i] << endl;
    }

    /** Write Data to CSV */
    write_to_csv(comps, "num_comparisons.csv", sort_name);
    write_to_csv(times, "times.csv", sort_name);
}

/**
* The function times a sort function
* 
* @param func_ptr pointer to the fuction being tested
* @param array array being tested
* @param size size of the array being tested 
* @param count the number of comparisons
*/
double sort_time(int(*func_ptr)(int [], int),int array[], int size, double& count){
    std::chrono::high_resolution_clock::time_point begin, end;
    std::chrono::duration<double> elapsed_time;

    begin = std::chrono::high_resolution_clock::now();
    count = (double)func_ptr(array, size);
    end = std::chrono::high_resolution_clock::now();

    elapsed_time = end - begin;
    return elapsed_time.count();
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
void fill_arrays(int random[], int ascend[], int descending[], int size) {
    for(int i = 0; i < size; i++) {
        random[i]  = rand() % 1000;
        ascend[i]  = i;
        descending[i] = size - i;
    }
}

/*
 * @brief This function creates a csv file and writes the
 * header info to the file.
 *
 *  @param file_name The name of the csv file.
 *
 */
void create_csv(string file_name) {
    ofstream fout(file_name, std::ios::out);
    if (fout.is_open()) {
        fout << "Array Size" << ",," << "100" << ",,," << "1000" 
             << ",,," << "10000" << ",,," << "30000" << endl;
        fout << "Array Type";
        for(int i = 0; i < 4; i++) {
            fout << ",inc,dec,ran";
        }
        fout << endl;
    }
    fout.close();
}