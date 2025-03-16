#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    int k, n, w;
    sscanf(input.c_str(), "%d %d %d", &k, &n, &w);

    if (k >= 1 && w <= 1000) {
        int total = 0;
        for (int i = 1; i <= w; ++i) {
            total += i * k;
        }
        if (total > n) {
            cout << total - n << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}

