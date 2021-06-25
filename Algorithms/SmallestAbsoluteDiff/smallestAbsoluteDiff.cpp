/*
* File name: smallestAbsoluteDiff.cpp
* Author: Emrullah Jack Oztosun (emrullahjack@gmail.com)
* Description: Suppose you are given two arrays A[1..n] and B[1..n] of integers. You are required to find
*   a pair of elements (A[i], B[j]) such that their absolute difference is the smallest over all such pairs.
* Notes: Assume A and B are sorted in non-decreasing order. 
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int outPair[2] = {-1, -1};

void smallestAbsoluteDiff(int* A, int* B, int len) {
    int smallestAbsoluteDiff = abs(A[0] - B[0]); // Base case: n = 1
    int ind1 = 0, ind2 = 0;

    outPair[0] = A[ind1]; outPair[1] = B[ind2];

    int i = 0, j = 0;
    while (i < len && j < len) {
        if (abs(A[i] - B[j]) < smallestAbsoluteDiff) {
            smallestAbsoluteDiff = abs(A[i] - B[j]);
            ind1 = i;
            ind2 = j;
        }

        if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
        
    }

    outPair[0] = A[ind1]; outPair[1] = B[ind2];
}

int main(int argc, char** argv) {
    // an arbitrary input size
    const int n = 5;

    // two arbitrary inputs of size n, sorted in non-decreasing order.
    int A[n] = {3, 4, 8, 12, 19};
    int B[n] = {1, 7, 11, 20, 21};

    smallestAbsoluteDiff(A, B, n);

    // output the pair
    cout << "(" << outPair[0] << ", " << outPair[1] << ")" << endl;

    return 0;
}