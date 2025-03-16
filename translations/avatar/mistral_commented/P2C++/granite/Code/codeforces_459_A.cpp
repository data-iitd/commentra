
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Get user input and convert it to a vector of strings
    string given;
    getline(cin, given);
    vector<string> l1;
    string temp = "";
    for (int i = 0; i < given.length(); i++) {
        if (given[i] =='') {
            l1.push_back(temp);
            temp = "";
        } else {
            temp += given[i];
        }
    }
    l1.push_back(temp);

    // Convert the vector of strings to a vector of integers
    vector<int> l2;
    for (int i = 0; i < l1.size(); i++) {
        l2.push_back(stoi(l1[i]));
    }

    // Assign the first two elements of the vector to x1, y1 and the last two elements to x2, y2
    int x1 = l2[0], y1 = l2[1];
    int x2 = l2[2], y2 = l2[3];

    // Calculate the denominator and numerator of the slope
    int denominator = x2 - x1;
    int numerator = y2 - y1;

    // Check if the denominator is zero
    if (denominator == 0) {
        // Calculate the distance between the two points and print the result
        int d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        int x3 = x1, x4 = x2, y3 = y2 + d, y4 = y1 + d;
        cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    }

    // If the denominator is not zero, calculate the quotient
    else if (denominator!= 0) {
        double quotient = (double) numerator / denominator;

        // Check if the quotient is equal to 1 or -1
        if (quotient == 1 || quotient == -1) {
            // Swap the x and y coordinates of the two points and print the result
            if (quotient == 1) {
                int x3 = x2, x4 = x1, y3 = y1, y4 = y2;
                cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
            } else {
                int x3 = x1, x4 = x2, y3 = y2, y4 = y1;
                cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
            }
        }

        // If the quotient is not 1 or -1, print -1
        else {
            cout << -1 << endl;
        }
    }

    return 0;
}
