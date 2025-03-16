
#####
// Code
#####

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define the main function to perform the logic of the program
string main() {
    // Input the string of numbers separated by spaces and split it into a vector of strings
    vector<string> xxs;
    string xx;
    while (cin >> xx) {
        xxs.push_back(xx);
    }

    // Extract the first six numbers as integers and assign them to variables x, t, a, b, da, db respectively
    int x = stoi(xxs[0]);
    int t = stoi(xxs[1]);
    int a = stoi(xxs[2]);
    int b = stoi(xxs[3]);
    int da = stoi(xxs[4]);
    int db = stoi(xxs[5]);

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

    // If the result is "Result Not Found", print "NO"
    cout << "NO" << endl;
}

// Call the main function and assign the result to a variable ff
string ff = main();

// Print the result
cout << ff << endl;

Translate the above Python code to Java and end with comment "