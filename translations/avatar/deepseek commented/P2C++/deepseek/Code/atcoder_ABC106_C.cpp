#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <functional>
#include <numeric>
#include <bitset>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

using namespace std;

// Functions to read input more efficiently
vector<int> LI() {
    string line;
    getline(cin, line);
    vector<int> nums;
    stringstream ss(line);
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }
    return nums;
}

int I() {
    string line;
    getline(cin, line);
    return stoi(line);
}

string S() {
    string line;
    getline(cin, line);
    return line;
}

// Main function to execute the program
string main() {
    string s = S();
    int k = I();
    int l = 0;
    for (char c : s) {
        if (c != '1') {
            break;
        }
        l++;
    }
    if (l >= k) {
        return "1";
    }
    return string(1, s[l]);
}

// Print the result of the main function
int main() {
    cout << main() << endl;
    return 0;
}
