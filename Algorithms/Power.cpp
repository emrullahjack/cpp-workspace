#include <iostream>
using namespace std;

int power(int base, int th) {
    if (th == 0) {
        return 1;
    } else {
        return base * power(base, th - 1);
    }
}
