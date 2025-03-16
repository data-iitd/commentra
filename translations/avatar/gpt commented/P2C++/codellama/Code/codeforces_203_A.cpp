#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // Read input values and split them into a list
    string xxs;
    getline(cin, xxs);
    istringstream iss(xxs);
    vector<string> xxs_list;
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(xxs_list));

    // Convert the input strings to integers
    int x = stoi(xxs_list[0]);
    int t = stoi(xxs_list[1]);
    int a = stoi(xxs_list[2]);
    int b = stoi(xxs_list[3]);
    int da = stoi(xxs_list[4]);
    int db = stoi(xxs_list[5]);

    // Check if the target value x is zero
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

    // If no valid combination is found, return "Result Not Found"
    cout << "NO" << endl;
    return 0;
}

