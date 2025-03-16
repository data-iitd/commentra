#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int mod = 1e9 + 7;

// Function to read integer input from standard input
int getInt() {
    int i;
    cin >> i;
    return i;
}

// Function to read string input from standard input
string getString() {
    string s;
    cin >> s;
    return s;
}

// Function to calculate absolute value of a number
int abs(int a) {
    return abs(a);
}

// Function to calculate power of a number
int pow(int p, int q) {
    return pow(p, q);
}

// Function to find minimum of given numbers
int min(int nums[], int size) {
    int min = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

// Function to find maximum of given numbers
int max(int nums[], int size) {
    int max = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

// Function to check if a string is present in a vector of strings
bool strSearch(vector<string> &vec, string &str) {
    for (auto &s : vec) {
        if (s == str) {
            return true;
        }
    }
    return false;
}

// Function to print an integer array
void printIntArray(int array[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Function to calculate modulo of a number
int calcMod(int x) {
    return x % mod;
}

// Main function
int main() {
    // Initialize week array with 7 days of the week
    vector<string> week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    // Read input string from standard input
    string s = getString();

    // Find index of the given day in week array
    int index = -1;
    for (int i = 0; i < week.size(); i++) {
        if (s == week[i]) {
            index = i;
            break;
        }
    }

    // If the given day is not present in the week array, exit with error message
    if (index == -1) {
        cerr << "Invalid day of the week" << endl;
        return 1;
    }

    // Calculate the difference between the index of the given day and the index of Sunday
    // and print the result
    cout << 7 - index << endl;

    return 0;
}
