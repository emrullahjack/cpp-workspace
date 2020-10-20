#include <iostream>
using namespace std;

int out[10] = {0};

int* longestSubarrayNonnegativeSum(int *arr, int n)
{
    int passedElementCounter = 0;
    for (int i = 0; i < n; i++)
    {
      int cumSum = 0;
      int passedElementCounterNew = 0;
      while (cumSum >= 0 && i < n)
      {
          cumSum += arr[i];
          passedElementCounterNew++;
          i++;
      }

      if (passedElementCounterNew > passedElementCounter)
      {
          passedElementCounter = passedElementCounterNew;
          int j = 0;
          while(j < passedElementCounter)
          {
              out[j] = arr[i - passedElementCounter + j];
              j++;
          }
      }
    }

    out[passedElementCounter - 1] = 0;
    return out;
}

// Driver code
int main()
{
    int arr[] = {1, 0, 4, 7, 1, -5, -1,
                           0, -15, 1, 0, 8, 12, 15, 21, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < 10; i++) {
      cout << longestSubarrayNonnegativeSum(arr, n)[i] << "\n";
    }

    return 0;
}
