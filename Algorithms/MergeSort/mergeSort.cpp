/*
* File Name: mergeSort.cpp
* Author: Emrullah Jack Oztosun
* Description: merge sort algorithm implementation.
*/

#include <iostream>
#include <math.h>

#define INF 10001

using namespace std;

void merge(int*, int, int, int);
void mergeSort(int*, int, int);
void mergeWithoutSentinels(int*, int, int, int);
void printArray(int[], int);

void merge(int* arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1+1], right[n2+1];
    for (int i = 0; i < n1; i++)
        left[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[q + 1 + j];

    left[n1] = INF;
    right[n2] = INF;

    cout << "left subarray is: ";
    printArray(left, n1);
    cout << endl;

    cout << "right subarray is; ";
    printArray(right, n2);
    cout << endl;

    int j = 0, i = 0;
    for (int k = p; k < r + 1; k++) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
    }     
}

void mergeWithoutSentinels(int* arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[q + j + 1];

    int i = 0, j = 0;
    for (int k = p; k < r + 1; k++) {
        if (i > n1 - 1) {
            while (j < n2)
            {
                arr[k] = right[j];
                k++;
                j++;
            }
        } else if (j > n2 - 1) {
            while (i < n1) {
                arr[k] = left[i];
                k++;
                i++;
            }
        } else if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
    }
}

void mergeSort(int* arr, int p, int r) {
    if (p < r) {
        int q = floor((p+r)/2);
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        mergeWithoutSentinels(arr, p, q, r);
    }
}

int main(int argc, char** argv) {
    int arr[8] = {1, 28, 13, 73, 26, 4, 9, 2};

    cout << "Data prior sorting operation: ";
    printArray(arr, 8);
    cout << endl;
    
    mergeSort(arr, 0, 7);

    cout << "Data after sorting operation: ";
    printArray(arr, 8);
    cout << endl;

    return 0;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}