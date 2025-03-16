#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) & 1) {
            t++;
        }
    }
    cout << t / n << endl;
    return 0;
}

