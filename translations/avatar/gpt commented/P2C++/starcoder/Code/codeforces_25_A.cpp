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
    int odd_count = 0;
    for (int i = 0; i < n; i++) {
        if (list[i] % 2 == 1) {
            odd_count++;
        }
    }
    if (odd_count == 1) {
        for (int i = 0; i < n; i++) {
            if (list[i] % 2 == 1) {
                cout << i + 1 << endl;
                break;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (list[i] % 2 == 0) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}
