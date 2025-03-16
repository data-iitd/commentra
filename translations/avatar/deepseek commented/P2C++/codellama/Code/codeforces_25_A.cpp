
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string input;
    cin >> input;
    istringstream iss(input);
    vector<int> list;
    int x;
    while (iss >> x) {
        list.push_back(x % 2);
    }
    if (sum(list) == 1) {
        cout << list.index(1) + 1 << endl;
    } else {
        cout << list.index(0) + 1 << endl;
    }
    return 0;
}

