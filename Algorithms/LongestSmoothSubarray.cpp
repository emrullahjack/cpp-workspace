/*
* delta-smooth means max(S) - min(S) <= delta where delta is a real number and delta > 0,
* and S is an array of numbers. The algorithm below finds the longest smooth subarray of a
* given array with given delta.
*
* This is a brute-force algorithm, there are more efficient ways of solving this problem.
* Time complexity: takes O(n^3) time.
*
* Author: Emrullah Jack Oztosun
*/

#include <iostream>

using namespace std;

// An function to print out all the subarrays of a given array.
// It also prints out the number of subarrays.
int*** AllSubarray(int arr[], int len, int*** xppp) {
  int x, y, z;
  int numOfSubarray = 0;

  for (x = 0; x < len; x++) {
    xppp[x] = new int* [len-x];

    for (y = x; y < len; y++) {
      int i = 0;
      xppp[x][i] = new int [y-x+1];

      for (z = x; z <= y; z++) {
        int j = 0;
        xppp[x][i][j] = arr[z];

        if (z == x && z == y) {
          printf("{%d}", xppp[x][i][j]);
          numOfSubarray++;
        } else if (z == x) {
          printf("{%d, ", xppp[x][i][j]);
        } else if (z == y) {
          printf("%d}", xppp[x][i][j]);
          numOfSubarray++;
        } else {
          printf("%d, ", xppp[x][i][j]);
        }

        j++;
      }

       printf("\n");
       i++;
    }

  }

  printf("\nNumber of Subarrays: %d \n\n", numOfSubarray);

  return xppp;
}

int*** LSS(int arr[], int len, int delta, int** out[len]) {
  // Input: an array arr[1..n] of integers, and an integer delta > 0.
  // Output: the longest contigious delta-smooth subarray of arr[1..n]

  // To be continued...

  return out;
}

int main(int argc, char const *argv[]) {
  int a[] = {1, 12, 4, 7, -2, 8, -5, 3, 6, 10, -27, 5};
  int len = sizeof(a)/sizeof(int);

  // All subarrays stored in this pointer to pointer to integer array
  // x is the start index, y is the end index, z is the values inside
  // the subarray for this particular (x, y) pair.
  int*** xppp = new int** [len];
  xppp = AllSubarray(a, len, xppp);

  return 0;
}
