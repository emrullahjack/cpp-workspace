/*
* File name: stringToInt.cpp
* Author: Emrullah Jack Oztosun
* Description: An algorithm to parse a string to an integer
* Notes: TO BE CONTINUED
*/

#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int stringToInt(string s);

int main(int argc, char** argv) {
    int r = stringToInt("42");
    cout << "The string \"42\" is parsed as: " << r << endl;

    return 0;
}

int stringToInt(string s) {
    bool is_negative = false;
    bool found_first_nonwhite_char = false;
    string s_in = "";
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (found_first_nonwhite_char) {
                break;
            } else {
                continue;
            }
        } else if (s[i] == '-') {
            is_negative = true;
            found_first_nonwhite_char = true;
        } else if ('0' <= s[i] && s[i] <= '9') {
            s_in = s_in + s[i];
            found_first_nonwhite_char = true;
        } else {
            break;
        }
    }

    int result = 0;
    for (int i = 0; i < s_in.length(); i++) {
        result = result * 10 + (s_in[i] - '0');
    }

    if (is_negative) {
        result *= -1;
    }
        
    // if ()
    
    return result;
}