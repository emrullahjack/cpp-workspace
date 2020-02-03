// ----- Multiplication - Divide and Conquer - Karatsuba -----
// The below algorithm is called Karatsuba algorithm and it can be used for any base
#include <iostream>
#include <stdio.h>

using namespace std;

// Helper method: Given two unequal sized bit strings, converts them to same length
// by adding leading 0's in the smaller string. Returns the new length.
int makeEqualLength(string &str1, string &str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    if (len1 < len2) {
        for (int i = 0; i < len2 - len1; i++) {
            str1 = '0' + str1;
        }

        return len2;
    } else if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            str2 = '0' + str2;
        }

        return len1;
    }

    return len1;
}

// The main function that adds two bit sequences and returns the addition
string addBitStrings(string first, string second) {
    string result;  // To store the sum bits

    int length = makeEqualLength(first, second);
    int carry = 0;

    for (int i = length - 1; i >= 0; i--) {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';

        int sum = (firstBit ^ secondBit ^ carry) + '0';
        result = char(sum) + result;

        carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
    }

    // if overflow, then add a leading 1
    if (carry)  result = '1' + result;

    return result;
}

// A utility function to multiply single bits of strings a and b
int multiplySingleBit(string a, string b) {
    return (a[0] - '0') * (b[0] - '0');
}

// The main function that multiplies two bit strings X and Y
// and returns result as long integer
long int multiply(string X, string Y) {
    // Find the maximum of lengths of X and Y, make length of
    // the smaller string same as that of larger string

    int n = makeEqualLength(X, Y);

    // Base cases
    if (n == 0) return 0;
    if (n == 1) return multiplySingleBit(X, Y);

    int fh = n / 2;     // first half of string, floor(n / 2)
    int sh = (n - fh);  // second half of string, ceil(n / 2)

    // Find the first half and second half of the first string
    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);

    // Find the first half and second half of the second string
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);

    // Recursively calculate the three products of inputs of size n / 2
    long int P1 = multiply(Xl, Yl);
    long int P2 = multiply(Xr, Yr);
    long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));

    return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}

int main(int argc, char const *argv[]) {
    printf ("%ld\n", multiply("1100", "1010"));
    printf ("%ld\n", multiply("110", "1010"));
    printf ("%ld\n", multiply("11", "1010"));
    printf ("%ld\n", multiply("1", "1010"));
    printf ("%ld\n", multiply("0", "1010"));
    printf ("%ld\n", multiply("111", "111"));
    printf ("%ld\n", multiply("11", "11"));

    return 0;
}
