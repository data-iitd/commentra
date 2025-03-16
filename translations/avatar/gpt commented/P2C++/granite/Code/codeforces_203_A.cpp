
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input values and split them into a vector
    vector<string> xxs;
    string input;
    getline(cin, input);
    size_t start = 0;
    size_t end = input.find(" ");
    while (end!= string::npos) {
        xxs.push_back(input.substr(start, end - start));
        start = end + 1;
        end = input.find(" ", start);
    }
    xxs.push_back(input.substr(start));

    // Convert the input strings to integers
    int x = stoi(xxs[0]);
    int t = stoi(xxs[1]);
    int a = stoi(xxs[2]);
    int b = stoi(xxs[3]);
    int da = stoi(xxs[4]);
    int db = stoi(xxs[5]);

    if (x == 0) {
        cout << "YES" << endl;  // If x is zero, print "YES" and return
        return 0;
    }

    // Calculate the maximum time available for a and b, constrained by t
    int a_time = min(a / da, t - 1);
    int b_time = min(b / db, t - 1);

    // Iterate through all possible values of i and j within the calculated time limits
    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            // Check if either a or b can be reduced to x by subtracting multiples of da or db
            if (a - da * i == x || b - db * j == x) {
                cout << "YES" << endl;  // If found, print "YES" and return
                return 0;
            }
            // Check if the sum of the remaining values of a and b equals x
            if ((a - da * i) + (b - db * j) == x) {
                cout << "YES" << endl;  // If found, print "YES" and return
                return 0;
            }
        }
    }

    // If no valid combination is found, print "NO"
    cout << "NO" << endl;

    return 0;
}

