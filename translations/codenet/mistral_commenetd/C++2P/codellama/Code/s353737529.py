/*
これを入れて実行
python code.py
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;

// Function to check if first pair has greater second value than second pair
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b){
	if (b == 0)return a;
	return gcd(b, a % b);
}

//-----------------------Main function-----------------------
int main(void){
	// Input the number of digits in binary representation
	cin >> n;

	// Initialize an empty string 's' to store binary representation
	string s = "";

	// Check if the number is zero and print '0' if it is
	if(n == 0){
		cout << '0' << endl;
		return 0;
	}

	// Iterate through the number from the least significant bit to the most significant bit
	int i = 1;
	while(n != 0){
		// If the number is even, add '0' to the binary representation
		if(n % 2 == 0){
			s += '0';
		} else {
			// If the number is odd, add '1' to the binary representation
			s += '1';
		}

		// Update the number by subtracting the absolute value of the remainder when the number is divided by 2 and the remainder itself
		n -= abs(n % 2);

		// Update the number by dividing it by -2 (since we subtracted the remainder in the previous step, we need to divide by -2 to get the next number)
		n /= -2;
	}

	// Reverse the binary representation and print it
	reverse(s.begin(), s.end());

	cout << s << endl;
}


