/*
* File Name: sumExists.cpp
* Author: Emrullah Jack Oztosun
* Description: an algorithm to check if a given number exists as the sum of two numbers in an array.
* Notes: TO BE CONTINUED
*/

#include <iostream>
#include <math.h>
using namespace std;

// Given an array of n integers, determine wheter 's' exists as the sum of two integers in the array.
bool sumExists(int* arr, int n, int s);
void mergeSort(int*, int, int);
void mergeWithoutSentinels(int*, int, int, int);

int main(int argc, char** argv) {
    int arr[8] = {12, 23, 11, 73, 38, 41, 40, 89};
    cout << sumExists(arr, 8, 74) << endl;

    return 0;
}

bool sumExists(int* arr, int n, int s) {
    mergeSort(arr, 0, n-1);
    int i = 0;
    int j = n - 1;

    while (i < j) {
        if (arr[i] + arr[j] == s) {
            return true;
        } else if (arr[i] + arr[j] < s) {
            i++;
        } else if (arr[i] + arr[j] > s) {
            j--;
        }
    }

    return false;
}

void mergeSort(int* arr, int p, int r) {
    if (p < r) {
        int q = floor((p+r)/2);
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        mergeWithoutSentinels(arr, p, q, r);
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

