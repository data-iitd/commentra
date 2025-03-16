#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // Read a line of input, split it into components, and convert each component to an integer, storing them in a tuple
    string input;
    getline(cin, input);
    istringstream iss(input);
    vector<int> ABC;
    int temp;
    while (iss >> temp) {
        ABC.push_back(temp);
    }

    // Check if the number 5 appears exactly twice in the tuple
    int count = 0;
    for (int i = 0; i < ABC.size(); i++) {
        if (ABC[i] == 5) {
            count++;
        }
    }
    if (count == 2) {
        // If 5 appears twice, check if the sum of the numbers in the tuple equals 17
        int sum = 0;
        for (int i = 0; i < ABC.size(); i++) {
            sum += ABC[i];
        }
        if (sum == 17) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        // If 5 does not appear exactly twice, print 'NO'
        cout << "NO" << endl;
    }

    return 0;
}

