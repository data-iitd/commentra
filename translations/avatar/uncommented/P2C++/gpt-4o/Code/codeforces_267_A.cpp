#include <iostream>
#include <vector>

using namespace std;

int substract(int a, int b) {
    int total = 0;
    if (a > b) {
        while (a > 0 && b > 0) {
            total += a / b;
            a = a % b;
            if (a > 0) {
                total += b / a;
                b = b % a;
            }
        }
    } else if (a < b) {
        while (a > 0 && b > 0) {
            total += b / a;
            b = b % a;
            if (b > 0) {
                total += a / b;
                a = a % b;
            }
        }
    } else { // a == b
        return 1;
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    vector<int> lst;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        lst.push_back(substract(a, b));
    }
    for (int i : lst) {
        cout << i << endl;
    }
    return 0;
}

// <END-OF-CODE>
