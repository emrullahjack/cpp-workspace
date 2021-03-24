/*
* File Name: reversedBinaryValue.cpp
* Author: Emrullah Jack Oztosun
* Description: Given an arbitrary number of booleans, find the corresponding number when the order of these booleans
* reversed and they get concatenated.
* Notes: 
*/

#include <iostream>
using namespace std;

template<bool v>
int reversed_binary_value() {
    return v;
}

template <bool p1, bool p2, bool... pack>
int reversed_binary_value() {
    return p1 + reversed_binary_value<p2, pack...>() * 2;
}


template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}
