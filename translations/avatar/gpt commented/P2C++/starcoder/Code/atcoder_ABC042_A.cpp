#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v = {a, b, c};
    if (count(v.begin(), v.end(), 5) == 2) {
        if (a + b + c == 17) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

