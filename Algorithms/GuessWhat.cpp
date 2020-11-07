#include <iostream>
using namespace std;

int GuessWhat(int n);

int GuessWhat(int n) {
  // Pre-cond: input n is a natural number
  // Post-cond:

  int i = 0, j = 1;

  while (i < n) {
    j = j + j;
    i = i + 1;
  }

  return j;
}

int main(int argc, char const *argv[]) {
  printf("%d\n", GuessWhat(6));
  return 0;
}
