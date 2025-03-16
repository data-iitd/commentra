#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to compute the Greatest Common Divisor (GCD) of two numbers
int G(int a, int b) {
    // Continue looping until b becomes 0
    while (a % b!= 0) {
        // Update a and b using the Euclidean algorithm
        a = b;
        b = a % b;
    }
    // Return the GCD
    return b;
}

// Function to compute the Least Common Multiple (LCM) of two numbers
int L(int a, int b) {
    // Calculate LCM using the relationship between GCD and LCM
    return a * b / G(a, b);
}

// Main function
int main() {
    // Read input values and split them into a list
    string l;
    cin >> l;
    vector<string> v;
    int i = 0;
    while (l[i]!= '\0') {
        string s = "";
        while (l[i]!='') {
            s += l[i];
            i++;
        }
        v.push_back(s);
        i++;
    }

    // Convert the input strings to integers
    int x = stoi(v[0]);
    int y = stoi(v[1]);
    int a = stoi(v[2]);
    int b = stoi(v[3]);

    // Calculate the LCM of x and y
    int lcm = L(x, y);

    // Calculate and print the count of multiples of LCM in the range [a, b]
    cout << (b / lcm - (a - 1) / lcm) << endl;

    return 0;
}

