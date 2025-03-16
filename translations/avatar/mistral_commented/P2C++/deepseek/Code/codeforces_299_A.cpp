#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int num_inp() {
    int input;
    cin >> input;
    return input;
}

vector<int> arr_inp() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

vector<int> sp_inp() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    // Read input from file instead of user input
    vector<int> a;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            a.push_back(num);
        }
    }
    sort(a.begin(), a.end());

    // Find the largest number that leaves a remainder when divided by any number in the list
    int largest = a[0];
    bool valid = true;
    for (int x : a) {
        if (x % largest == 0) {
            valid = false;
            break;
        }
    }
    if (valid) {
        cout << largest << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
