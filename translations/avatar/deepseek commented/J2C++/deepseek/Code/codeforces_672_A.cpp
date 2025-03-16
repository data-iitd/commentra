#include <iostream>
#include <string>
#include <vector>

using namespace std;

// This function generates a string of numbers from 1 to 1000
string generateString() {
    string result;
    for (int i = 1; i <= 1000; i++) {
        result += to_string(i);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    string str = generateString();
    cout << str[n - 1] << endl;
    return 0;
}

