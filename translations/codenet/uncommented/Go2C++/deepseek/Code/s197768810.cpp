#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

vector<int> readInts() {
    string line;
    getline(cin, line);
    vector<int> numbers;
    stringstream ss(line);
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

int main() {
    vector<int> inputs = readInts();
    int n = inputs[0];
    int m = inputs[1];
    vector<int> a = readInts();
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += a[i];
    }
    if (sum > n) {
        cout << "-1" << endl;
        return 0;
    }
    cout << n - sum << endl;
    return 0;
}

