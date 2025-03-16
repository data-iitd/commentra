
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> scanArrayInt() {
    vector<int> ret;
    string s;
    getline(cin, s);
    stringstream ss(s);
    int i;
    while (ss >> i) {
        ret.push_back(i);
    }
    return ret;
}

int main() {
    vector<int> arr = scanArrayInt();
    int a = arr[0], b = arr[1];
    int tap = 0, consent = 1;
    while (consent < b) {
        consent = consent + a - 1;
        tap++;
    }
    cout << tap << endl;
    return 0;
}

