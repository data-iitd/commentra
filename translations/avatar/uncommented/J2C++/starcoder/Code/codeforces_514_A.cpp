#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    long x;
    cin >> x;
    vector<long> list;
    while (x > 0) {
        long r = x % 10;
        if (9 - r < r) {
            if (x / 10 == 0 && 9 - r == 0) list.push_back(r);
            else list.push_back(9 - r);
        } else list.push_back(r);
        x = x / 10;
    }
    int pow = 0;
    long newNumber = 0;
    for (int i = 0; i < list.size(); i++) {
        newNumber = newNumber + list.at(i) * pow(10, pow);
        pow++;
    }
    cout << newNumber << endl;
    return 0;
}

