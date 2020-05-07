#include <iostream>
using namespace std;

#define MAX 1000

bool has[MAX + 1][2];

bool search(int x) {

    if (x >= 0) {
      if (has[x][0] == 1) {
        return true;
      } else {
        return false;
      }
    }


    int abs_x = abs(x);

    if (has[abs_x][1] == 1)
      return true;

    return false;
}

void insert(int a[], int n) {

  for (int i = 0; i < n; i++) {
    if (a[i] >= 0)
      has[a[i]][0] = 1;
    else
      has[abs(a[i])][1] = 1;
  }
}

// Driver Program
int main(int argc, char const *argv[]) {
  int a[] = {-1, 9, -5, -8, -5, -2};
  int n = sizeof(a)/sizeof(a[0]);
  insert(a, n);
  int x = -5;
  if (search(x) == true)
    cout << "Present \n";
  else
    cout << "Not Present \n";

  return 0;
}
