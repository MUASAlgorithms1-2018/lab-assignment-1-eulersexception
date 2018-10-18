/**
 *  Algorithms and Data Structures - Lab 2
 *  Sorting Algorithms - Bubble Sort, Insertion Sort, Selection
 *
 *  @author Bahadir Suezer
 *  @version 2018-17-10
 */


#include <iostream>
#include <string>

using namespace std;

void insertion_sort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j > 0 && a[j-1] > a[j]){
            int tmp = a[j-1];
            a[j-1] = a[j];
            a[j] = tmp;
            j--;
        }
    }
}

void selection_sort(int a[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min = a[i];
        int minIndex = 0;
        for(int j = i; j < n-1; j++) {
            if(min > a[j+1]) {
                min = a[j+1];
                minIndex = j+1;
            }
        }
        if(a[i] > min) {
            int tmp = a[i];
            a[i] = min;
            a[minIndex] = tmp;
        }
    }
}

void bubble_sort(int a[], int n)
{
    int temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void merge(int *a, int *first, int sizeFirst, int *second, int sizeSecond) {

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < sizeFirst && j < sizeSecond) {
        if(first[i] <= second[j]) {
            a[k++] = first[i++];
        }
        else {
            a[k++] = second[j++];
        }
    }
    while(i < sizeFirst) {
        a[k++] = first[i++];
    }
    while(j < sizeSecond) {
        a[k++] = second[j++];
    }
}


void merge_sort(int* a, int size) {
    if(size == 1) {
        return;
    }
    int start = 0;
    int end = start + size - 1;
    int mid = (start + end) / 2;
    int sizeFirst = mid - start + 1;
    int sizeSecond = end - mid;
    int *first = new int[sizeFirst];
    int *second = new int[sizeSecond];

    for(int i = start; i <= mid; i++) {
        first[i] = a[i];
    }

    for(int i = mid+1; i <= end; i++) {
        second[i-mid-1] = a[i];
    }

    merge_sort(first, sizeFirst);
    merge_sort(second, sizeSecond);

    merge(a, first, sizeFirst, second, sizeSecond);
}



// print an array with length n to standard output
void print_array(int a[], int n)
{
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


int main(int argc, char* argv[]) {
    std::string sort_type = std::string(argv[1]);
    int n = argc - 2; // do not count executable name or first argument
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i+2]);
    }
    cout << "Original list: ";
    print_array(arr, n);

    if (sort_type == "bubble") {
        bubble_sort(arr, n);
        cout << "Sorted list: ";
        print_array(arr, n);
    }
    else if (sort_type == "insertion") {
        insertion_sort(arr, n);
        cout << "Sorted list: ";
        print_array(arr, n);
    }
    else if (sort_type == "selection") {
        selection_sort(arr, n);
        cout << "Sorted list: ";
        print_array(arr, n);
    }
    else if (sort_type == "merge") {
        merge_sort(arr, n);
        cout << "Sorted list: ";
        print_array(arr, n);
    }
    else {
        cout << "Sorry, " << sort_type << " sort is not implemented!" << endl;
    }

    delete[] arr;

    return 0;
}