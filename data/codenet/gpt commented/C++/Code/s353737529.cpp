/*
これを入れて実行
g++ code.cpp
./a.out
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

// Direction vectors for moving in 4 directions (up, right, down, left)
int dy[4] = {-1, 0, +1, 0};
int dx[4] = {0, +1, 0, -1};

// Constants for infinity and modulo operations
const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;

// Comparator function to sort pairs based on the second element
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}

// Function to compute the greatest common divisor (GCD) using recursion
int gcd(int a, int b){
	if (b == 0) return a; // Base case: if b is 0, return a
	return gcd(b, a % b); // Recursive case
}

//-----------------------ここから-----------

int main(void){
    int n; // Variable to hold the input number

    // Read an integer from standard input
	cin >> n;

    // Initialize an empty string to hold the binary representation
	string s = "";

    // Special case: if the input number is 0, output '0' and exit
	if(n == 0){
		cout << '0' << endl;
		return 0;
	}
	
    // Loop to convert the number to its binary representation in a specific format
	int i = 1;
	while(n != 0){
        // Check if the current number is even or odd
		if(n % 2 == 0){
			s += '0'; // Append '0' for even numbers
		} else {
			s += '1'; // Append '1' for odd numbers
		}

        // Adjust the number for the next iteration
		n -= abs(n % 2); // Reduce n by 1 if it's odd
		n /= -2; // Divide n by -2 to continue the conversion
	}

    // Reverse the string to get the correct binary representation
	reverse(s.begin(), s.end());

    // Output the final binary string
	cout << s << endl;

}
