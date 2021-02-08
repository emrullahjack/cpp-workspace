/*
* File Name: insertionSort.cpp
* Author: Emrullah Jack Oztosun
* Description: insertion sort algorithm implementation.
*/

#include <iostream>
using namespace std;

void insertionSort(int[], int);
void printArray(int[], int);

// Usage
int main(int argc, char** argv) {
    int data[] = {187, 234, 123, 12, 5, 28, 192, 23};
    int n = sizeof(data)/sizeof(data[0]);

    cout << "Data prior sorting operation: ";
    printArray(data, n);
    cout << endl;

    insertionSort(data, n);

    cout << "Data after sorting operation: ";
    printArray(data, n);
    cout << endl;

    return 0;
}

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

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}