/*
* File Name: binarySearch.cpp
* Author: Emrullah Jack Oztosun
* Description: binary search algorithm implementation.
*/

#include <iostream>
using namespace std;

// returns the index of the 'key', if it exists in 'sArr', returns -1 otherwise
int binarySearch(int*, int, int, int, int);

int main(int argc, char** argv) {
    int sortedArr[7] = {12, 23, 35, 49, 51, 79, 92}; // array must be sorted in order to call binary search on it

    int key = 90;
    cout << "The index of key " << key << " is: " << binarySearch(sortedArr, 7, 0, 6, key) << endl;

    return 0;
}

int binarySearch(int* sArr, int n, int si, int fi, int key) {
    if (si == fi) {
        if (sArr[si] == key) {
            return si;
        } else {
            return -1; 
        }
    } 
    int midValue = sArr[(si + fi) / 2];
    if (midValue == key) {
        return (si + fi) / 2;
    } else if (midValue > key){
        return binarySearch(sArr, n/2, si, ((si + fi) / 2) - 1, key);
    } else {
        return binarySearch(sArr, n/2, ((si + fi) / 2) + 1, fi, key);
    }
}