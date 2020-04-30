#include <iostream>
using namespace std;

void maxHeapify(int arr[], int i, int n) {
  int l = 2*i + 1;
  int r = 2*i + 2;
  int largest = i;

  if (l < n && arr[l] > arr[i])
    largest = l;
  if (r < n && arr[r] > arr[largest])
    largest = r;
  if (largest != i) {
    swap(arr[i], arr[largest]);
    maxHeapify(arr, largest, n);
  }
}

// This function basically builds max heap
void convertMaxHeap(int arr[], int n) {

  // start from the bottommost and rightmost
  // internal node and heapify all internal
  // nodes in bottom-up way
  for (int i = (n-2)/2; i >= 0; --i)
    maxHeapify(arr, i, n);
}

void printArray(int *arr, int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", *(arr + i));
}

// Driver program
int main(int argc, char const *argv[]) {
  // array representing min heap
  int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
  int n = sizeof(arr)/sizeof(arr[0]);

  printf("Min Heap array : ");
  printArray(arr, n);

  convertMaxHeap(arr, n);

  printf("\nMax Heap array : ");
  printArray(arr, n);
  printf("\n");

  return 0;
}
