

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    // Initialize week array with 7 days of the week
    string week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // Read input string from scanner
    string s;
    cin >> s;

    // Find index of the given day in week array
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (week[i] == s) {
            index = i;
            break;
        }
    }

    // If the given day is not present in the week array, panic with error message
    if (index == -1) {
        panic("Invalid day of the week");
    }

    // Calculate the number of days between the given day and Sunday
    // and print the result
    int daysUntilSunday = 7 - index;
    cout << "The number of days until Sunday is: " << daysUntilSunday << endl;

    return 0;
}

// Function to calculate the absolute value of a number
int abs(int num) {
    return abs(num);
}

// Function to calculate the power of a number
int pow(int base, int exp) {
    return pow(base, exp);
}

// Function to find the minimum of given numbers
int min(int nums...) {
    if (nums.size() == 0) {
        panic("min() requires at least one argument");
    }
    int min = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

// Function to find the maximum of given numbers
int max(int nums...) {
    if (nums.size() == 0) {
        panic("max() requires at least one argument");
    }
    int max = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

// Function to check if a string is present in a slice of strings
bool strSearch(vector<string> slice, string str) {
    for (int i = 0; i < slice.size(); i++) {
        if (slice[i] == str) {
            return true;
        }
    }
    return false;
}

// Function to print an integer array
void printIntArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Function to calculate the modulo of a number
int calcMod(int num) {
    return num % mod;
}

// Function to read a single line of input as string
string getString() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read a single line of input as integer
int getInt() {
    int num;
    cin >> num;
    return num;
}

// Main function
int main() {
    // Initialize week array with 7 days of the week
    string week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // Read input string from scanner
    string s = getString();

    // Find index of the given day in week array
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (week[i] == s) {
            index = i;
            break;
        }
    }

    // If the given day is not present in the week array, panic with error message
    if (index == -1) {
        panic("Invalid day of the week");
    }

    // Calculate the number of days between the given day and Sunday
    // and print the result
    int daysUntilSunday = 7 - index;
    cout << "The number of days until Sunday is: " << daysUntilSunday << endl;

    return 0;
}

// Function to calculate the absolute value of a number
int abs(int num) {
    return abs(num);
}

// Function to calculate the power of a number
int pow(int base, int exp) {
    return pow(base, exp);
}

// Function to find the minimum of given numbers
int min(int nums...) {
    if (nums.size() == 0) {
        panic("min() requires at least one argument");
    }
    int min = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

// Function to find the maximum of given numbers
int max(int nums...) {
    if (nums.size() == 0) {
        panic("max() requires at least one argument");
    }
    int max = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

// Function to check if a string is present in a slice of strings
bool strSearch(vector<string> slice, string str) {
    for (int i = 0; i < slice.size(); i++) {
        if (slice[i] == str) {
            return true;
        }
    }
    return false;
}

// Function to print an integer array
void printIntArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Function to calculate the modulo of a number
int calcMod(int num) {
    return num % mod;
}

// Function to read a single line of input as string
string getString() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read a single line of input as integer
int getInt() {
    int num;
    cin >> num;
    return num;
}

// Main function
int main() {
    // Initialize week array with 7 days of the week
    string week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // Read input string from scanner
    string s = getString();

    // Find index of the given day in week array
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (week[i] == s) {
            index = i;
            break;
        }
    }

    // If the given day is not present in the week array, panic("Invalid day of the week")

    // Calculate the number of days between the given day and Sunday
    int daysUntilSunday = 7 - index;
    cout << "The number of days until Sunday is: " << daysUntilSunday << endl;

    return 0;
}

// Function to calculate the absolute value of a number
int abs(int num) {
    return abs(num);
}

// Function to calculate the power of a number
int pow(int base, int exp) {
    return pow(base, exp);
}

// Function to find the minimum of given numbers
int min(int nums...) {
    if (nums.size() == 0) {
        panic("min() requires at least one argument")
    }
    int min = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < min {
            min = nums[i]
        }
    }
    return min;
}

// Function to find the maximum of given numbers
int max(int nums...) {
    if (nums.size() == 0) {
        panic("max() requires at least one argument")
    }
    int max = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > max {
            max = nums[i]
        }
    }
    return max;
}

// Function to check if a string is present in a slice of strings
bool strSearch(vector<string> slice, string str) {
    for (int i = 0; i < slice.size(); i++) {
        if (slice[i] == str {
            return true;
        }
    }
    return false;
}

// Function to print an integer array
void printIntArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Function to calculate the modulo of a number
int calcMod(int num) {
    return num % mod;
}

// Function to read a single line of input as string
string s = getString()

// Function to read a single line of input as integer
int getInt() {
    return int(bufio.Scan(bufio.Scan(s)
    return s
}

// Function to read a single line of input as integer
int getInt() {
    return int(bufio.Scan(bufio.Scan(s)
    return s
}

// Function to find the minimum of given numbers
int min(int nums...) {
    if (nums.size() == 0) {
        panic("min() requires at least one argument")
    }
    int min = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > min {
            min = nums[i]
        }
    }
    return min;
}

// Function to find the maximum of given numbers
int max(int nums...) {
    if (nums.size() == 0) {
        panic("max() requires at least one argument")
    }
    int max = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < max {
            max = nums[i]
        }
    }
    return max;
}

// Function to check if a string is present in a slice of strings
bool strSearch(vector<string> slice, string s) {
    for (int i = 0; i < slice.size(); i++) {
        if (slice[i] == s) {
            return true;
        }
    }
    return false;
}

// Function to print an integer array
void printIntArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (size == 0) {
            panic("Invalid day of the week")
        }
    }
    int daysUntilSunday := 7 - index
}

// Function to calculate the modulo of a number
int calcMod(int num) {
    return num % mod;
}

// Function to read a single line of input as string
string s = getString()

// Function to read a single line of input as integer
int getInt() {
    return int(bufio.Scan(bufio.Scan(s)
    return s
}

// Function to find the maximum of given numbers
int max(int nums...) {
    if (nums.size() == 0) {
        panic("max() requires at least one argument")
    }
    int max = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > max {
            max = nums[i]
        }
    }
    return max;
}

// Function to calculate the number of days between the given day and Sunday
int daysUntilSunday := 7 - index
}

// Function to read a single line of input as integer
int getInt() {
    return int(bufio.Scan(bufio.Scan(s)
    return s
}

// Function to read a single line of input as integer
int getInt() {
    return int(bufio.Scan(bufio.Scan(s)
    return s
}

// Function to find the minimum of given numbers
int min(int nums...) {
    if (nums.size() == 0) {
        panic("min() requires at least one argument")
    }
    int min = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > min {
            min = nums[0]
            max = nums[0]
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < max {
            max = nums[i]
        }
    }
    return max;
}

// Function to calculate the number of days between the given 