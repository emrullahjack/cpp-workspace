/*
* File name: frequencyCount.cpp
* Author: Emrullah Jack Oztosun
* Description: count the number of occurrences in a given array, and find the number that occurs more than n/2 times
* Notes:
*/

#include <iostream>
using namespace std;

int getWinningDay(int* A, int n) {    
    int maxOcc = A[0];
    int maxCount = 1;
    int currOcc = A[0];
    int currCount = 1;

    for (int i = 0; i < n; i++) {
        currOcc = A[i];
        for (int j = 0; j < n; j++) {
            if (currOcc == A[j] && i != j) {
                currCount++;

                if (currCount > maxCount) {
                    maxCount = currCount;
                    maxOcc = A[i];

                    if (maxCount > n/2) {
                        return maxOcc;
                    }
                }
            }
        }

        currCount = 1;
    }

    return maxOcc;
}

int getWinningDayDnC(int* A, int l, int h) {
    if (l >= h) {
        return A[h];
    }

    int winning = A[l];
    int mid = (l + h) / 2;
    int leftWinning = getWinningDayDnC(A, l, mid);
    int rightWinning = getWinningDayDnC(A, mid+1, h);

    int lwCount = 0;
    int rwCount = 0;
    for (int i = l; i < h; i++) {
        if (A[i] == leftWinning) {
            lwCount++;
        } else if (A[i] == rightWinning) {
            rwCount++;
        }
    }

    if (lwCount > rwCount) {
        return leftWinning;
    } else {
        return rightWinning;
    }
}

int getWinningDayinSevenDays(int *A, int n) {
    int week[7] = {0, 0, 0, 0, 0, 0, 0};
    
    for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
            week[0]++;
        } else if (A[i] == 2) {
            week[1]++;
        } else if (A[i] == 3) {
            week[2]++;
        } else if (A[i] == 4) {
            week[3]++;
        } else if (A[i] == 5) {
            week[4]++;
        } else if (A[i] == 6) {
            week[5]++;
        } else if (A[i] == 7) {
            week[6]++;
        }
    }

    int maxOccDay = 0;
    int maxCount = week[0];
    for (int i = 1; i < 7; i++) {
        if (week[i] > maxCount) {
            maxCount = week[i];
            maxOccDay = i;
        }
    }

    return ++maxOccDay;
}

int main(int argc, char** argv) {
    int arr[14] = {3, 7, 2, 4, 7, 7, 4, 7, 7, 3, 7, 7, 1, 7};
    cout << "The winning day is " << getWinningDay(arr, 14) << endl;
    cout << "\n-------------------------\n" << "Using Divide & Conquer" << "\n-------------------------\n" << endl;
    cout << "The winning day is " << getWinningDayDnC(arr, 1, 14) << endl;
    cout << "\n-------------------------\n" << "Winning Day in Seven Days" << "\n-------------------------\n" << endl;
    cout << "The winning day in seven days is " << getWinningDayinSevenDays(arr, 14) << endl;

    return 0;
}