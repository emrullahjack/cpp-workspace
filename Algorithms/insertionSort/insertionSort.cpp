/*
* File Name: insertionSort.cpp
* Author: Emrullah Jack Oztosun
* Description: insertion sort algorithm implementation.
*/

#include <iostream>
using namespace std;

void insertionSort(int[], int);
void printArray(int[], int);
void insertionSortRecursive(int*, int);

// A sample usage 
int main(int argc, char** argv) {
    int data[] = {3, 41, 52, 26, 38, 57, 9, 49};
    int n = sizeof(data)/sizeof(data[0]);

    cout << "Data prior sorting operation: ";
    printArray(data, n);
    cout << endl;

    insertionSortRecursive(data, n);

    cout << "Data after sorting operation: ";
    printArray(data, n);
    cout << endl;

    return 0;
}

// Insertion sort iterative
void insertionSort(int* arr, int n) {

    for (int j = 1; j < n; j++) {
        int key = arr[j];
        int i = j - 1;

        while(i > -1 && arr[i] > key) {
            arr[i+1] = arr[i];
            i--;
        }

        arr[i+1] = key; // insert the key to it's right position 
    }

    return;
}

// Insertion sort recursive
void insertionSortRecursive(int* arr, int n) {
    if (n > 1) {
        insertionSortRecursive(arr, n - 1);
        if (arr[n - 1] < arr[n - 2]) {
            int temp = arr[n-2];
            arr[n-2] = arr[n-1];
            arr[n-1] = temp;
            insertionSortRecursive(arr, n - 1);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
