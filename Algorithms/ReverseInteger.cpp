#include <iostream>
using namespace std;

// Pre-condition: Given a 32-bit signed integer

class Solution {
    public:
        int reverse(int x) {
            bool isNegative = x < 0;
            int result = 0;

            if (isNegative) {
                x *= -1;
            }

            int dCount = 0;
            while (x != 0) {
                // Loop invariant: digits until i (index of a digit) is reversed
                // Exit condition: when there is no digits left in x
                result *= 10;
                result += x % 10;

                dCount++;
                x /= 10;
            }

            if (isNegative) {
                result *= -1;
            }

            return result;
        }
};

// Post-condition: The digits of the integer reversed
