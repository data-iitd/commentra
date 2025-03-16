#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += list[i];
    }
    if (sum == 1) {
        cout << "The first number with remainder 1 is: " << list.at(0) + 1 << endl;
    } else {
        cout << "The first number with remainder 0 is: " << list.at(0) + 1 << endl;
    }
    return 0;
}
