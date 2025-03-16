#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    // Define input variables 's' and 'l'
    string s;
    int l = 2019;

    // Initialize list 'm' with initial value 1 for index 0 and zeros for other indices
    int m[l] = {1};

    // Initialize variables 'a' and 'r' with zero values
    int a = 0, r = 0;

    // Iterate through the string 's' in reverse order
    for (int i = 0; i < s.length(); i++) {
        // Calculate the current digit's power and add it to 'a'
        a += (s[s.length() - i - 1] - '0') * pow(10, i, l);

        // Increment the index 'a % l' in list 'm'
        m[a % l] += 1;

        // Update 'r' with the current sum
        r += m[a % l];
    }

    // Print the final result 'r'
    cout << r << endl;

    return 0;
}

