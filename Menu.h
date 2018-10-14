#ifndef MENU_H
#define MENU_H

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
                    break;
                    case 2: sortType = "bubble_sort";
                    break;
                    case 3: sortType = "insertion_sort";
                    break;
                    case 4: sortType = "binary_insertion_sort";
                    break;
                    case 5: sortType = "merge_sort";
                    break;
                    case 6: sortType = "quick_sort";
                    break;
                    case 7: sortType = "random_quick_sort";
                    break;
                    case 8: sortType = "heap_sort";
                    break;
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
                    break;
                    case 2: sortOrder = "ascending";
                    break;
                    case 3: sortOrder = "decending";
                    break;
                    case 4: sortOrder = "all";
                    break;
                }
                subMenu = 0;
                selection = 0;
            }
            break;
            default: exit(0);
        }
    }
    return size;   
}

/*
void sort(int size, string sortType, string sortOrder){
    int (*sort_func)(int[],int);
    int* random     = new int[size];
    int* ascending  = new int[size];
    int* decending    = new int[size];
    fill_arrays(random, ascending, decending, size);
    std::map<string, int (*)(int[],int)> sorting_functions;
    sorting_functions.insert(std::pair<string, int(*)(int[],int)>("selection_sort",&selection_sort));
   sorting_functions.insert("bubble_sort",&bubble_sort);
    sorting_functions.insert("insertion_sort",&insertion_sort);
    sorting_functions.insert("binary_insertion_sort",&binary_insertion_sort);
    sorting_functions.insert("merge_sort",&merge_sort);
    sorting_functions.insert("quick_sort",&quick_sort);
    sorting_functions.insert("random_quick_sort",&random_quick_sort);
    sorting_functions.insert("heap_sort",&heap_sort);
    //sorting_functions.insert("all_sorts",&all_sorts);
    sort_func = sorting_functions[sortType];
    
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
}
*/
#endif