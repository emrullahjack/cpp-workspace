#include <iostream>
using namespace std;

int* longestContigiousSubArraySumNonNegative();

int* longestContigiousSubArraySumNonNegative(int *in, int *out) {
  int currentSum = 0;
  int numberOfElementsCovered = 0;
  for (int i = 0; i < (sizeof(in)/sizeof(*in)); i++) {
    // loop invariant: cumulative sum non-negative
  }

  return out;
}

int main(int argc, char const *argv[]) {
  int input[] = {1, -2, 4, -3, 3, -2, -1, -5, 2, 5, 4, -1, 4};
  int output[] = {2, 5, 7, 9};

  int *after = longestContigiousSubArraySumNonNegative(input, output);

  for (int i = 0; i < (sizeof(output)/sizeof(*output)); i++) {
    if (i == 0) printf("{");
    if (i == ((sizeof(output)/sizeof(*output)) - 1)) {
      printf("%d}\n", output[i]);
      break;
    }

    printf("%d, ", output[i]);
  }

  return 0;
}
