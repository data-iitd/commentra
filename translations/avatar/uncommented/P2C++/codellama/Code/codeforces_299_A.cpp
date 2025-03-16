#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int num_inp() {
    int n;
    cin >> n;
    return n;
}

vector<int> arr_inp() {
    string s;
    cin >> s;
    stringstream ss(s);
    vector<int> v;
    int n;
    while (ss >> n) {
        v.push_back(n);
    }
    return v;
}

vector<int> sp_inp() {
    string s;
    cin >> s;
    stringstream ss(s);
    vector<int> v;
    int n;
    while (ss >> n) {
        v.push_back(n);
    }
    return v;
}

int main() {
    vector<int> a = arr_inp();
    sort(a.begin(), a.end());
    if (any_of(a.begin(), a.end(), [&](int x) { return x % a[0] != 0; })) {
        cout << a[0] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

