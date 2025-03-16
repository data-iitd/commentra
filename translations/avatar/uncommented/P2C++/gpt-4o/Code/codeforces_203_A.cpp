#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string mainFunction() {
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;

    if (x == 0) {
        cout << "YES" << endl;
        return "Result Found";
    }

    int a_time = min(a / da, t - 1);
    int b_time = min(b / db, t - 1);

    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            if (a - da * i == x || b - db * j == x) {
                cout << "YES" << endl;
                return "Result Found";
            }
            if ((a - da * i) + (b - db * j) == x) {
                cout << "YES" << endl;
                return "Result Found";
            }
        }
    }
    return "Result Not Found";
}

int main() {
    string result = mainFunction();
    if (result == "Result Not Found") {
        cout << "NO" << endl;
    }
    return 0;
}

// <END-OF-CODE>
