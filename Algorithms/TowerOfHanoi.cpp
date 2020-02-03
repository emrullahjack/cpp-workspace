// C++ recursive function to
// solve tower of hanoi puzzle
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {

    if (n == 1) {
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << "\n";

        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << "\n";
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);

}

int main(int argc, char const *argv[]) {
    int n = 5;  // Number of disks
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
