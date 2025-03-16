
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int a, b;
    int tap = 0;
    int consent = 1;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    a = arr[0];
    b = arr[1];
    while (consent < b) {
        consent = consent + a - 1;
        tap++;
    }
    cout << tap << endl;
    return 0;
}

