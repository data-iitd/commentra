#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int next_int() {
    int x;
    cin >> x;
    return x;
}

vector<int> next_ints() {
    string line;
    getline(cin, line);
    vector<int> numbers;
    string num = "";
    for (char c : line) {
        if (c == ' ') {
            numbers.push_back(stoi(num));
            num = "";
        } else {
            num += c;
        }
    }
    if (num != "") {
        numbers.push_back(stoi(num));
    }
    return numbers;
}

int main() {
    int n = next_int();
    int t = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 != 0) {
            t++;
        }
    }
    cout << (double)t / n << endl;
