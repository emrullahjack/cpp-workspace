#include <iostream>
using namespace std;

// for this case, arrays have 4 elements
#define n 4

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]) {
  int i = 0, j = 0, k = 0;

  // Traverse both arrays
  while (i < n1 && j < n2) {

    // Check if current element of first
    // array is smaller than current element
    // of second array. If yes, store first
    // array element and increment first array
    // index. Otherwise do same with second array
    if (arr1[i] < arr2[j])
      arr3[k++] = arr1[i++];
    else {
      arr3[k++] = arr2[j++];
    }
  }

  // Store the remaining elements of the first array
  if (i < n1)
    arr3[k++] = arr1[i++];

  // Store the remaining elements of the second array
  if (j < n2)
    arr3[k++] = arr2[j++];
}

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
void mergeKArrays(int arr[][n], int i, int j, int output[]) {
  if (i == j) {
    for (int k = 0; k < n; k++)
      output[k] = arr[i][k];

    return;
  }

  if (j - i == 1) {
    mergeArrays(arr[i], arr[j], n, n, output);
    return;
  }

  int out1[n*(((i+j)/2)-i+1)], out2[n*(j-((i+j)/2))];
}

void printArray(int* arr, int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
}

int main(int argc, char const *argv[]) {

  return 0;
}
