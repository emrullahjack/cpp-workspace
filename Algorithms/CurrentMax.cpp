#include <iostream>
#define ARR_MAX 5

using namespace std;


int max(int x, int y);
int currentMax(int* ptr);

/* PreCondition: Input is array A[0..n] of n + 1 values */

int main(int argc, char const *argv[]) {
    int arr[ARR_MAX] = {4, 5, 3, 7, 1};

    int cMax = currentMax(arr);
    printf("%d\n", cMax);

    return 0;
}

int currentMax(int* ptr) {
    int m = *ptr;
    for (int i = 0; i < ARR_MAX - 1; i++) {
        // Loop invariant: m is the max of arr[0..i]
        m = max(m, *(ptr + (i + 1)));
    }

    return m;
}

int max(int x, int y) {
    if (x >= y) {
        return x;
    } else {
        return y;
    }
}
