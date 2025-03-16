#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to perform the logic of the program
string mainLogic(int x, int t, int a, int b, int da, int db) {
    // Check if x is equal to zero
    if (x == 0) {
        // If yes, print "YES" and return
        cout << "YES" << endl;
        return "Result Found";
    }

    // Calculate the minimum time it takes for a and b to reach x
    int a_time = min(a / da, t - 1);
    int b_time = min(b / db, t - 1);

    // Loop through all possible combinations of a_time and b_time
    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            // Check if x is equal to a after 'i' time steps or b after 'j' time steps
            if (a - da * i == x || b - db * j == x) {
                // If yes, print "YES" and return
                cout << "YES" << endl;
                return "Result Found";
            }

            // Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
            if ((a - da * i) + (b - db * j) == x) {
                // If yes, print "YES" and return
                cout << "YES" << endl;
                return "Result Found";
            }
        }
    }
    return "Result Not Found";
}

int main() {
    // Input the string of numbers separated by spaces
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> numbers;
    int number;

    // Split the input into a list of integers
    while (ss >> number) {
        numbers.push_back(number);
    }

    // Extract the first six numbers as integers
    int x = numbers[0], t = numbers[1], a = numbers[2], b = numbers[3], da = numbers[4], db = numbers[5];

    // Call the main logic function and assign the result to a variable
    string result = mainLogic(x, t, a, b, da, db);

    // If the result is "Result Not Found", print "NO"
    if (result == "Result Not Found") {
        cout << "NO" << endl;
    }

    return 0;
}

// <END-OF-CODE>
