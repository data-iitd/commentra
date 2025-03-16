#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> w;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        w[x]++;
    }
    
    long long c = 0;
    for (const auto& pair : w) {
        int i = pair.first;
        if (i == 0) {
            c += (long long)w[i] * (w[i] - 1);
        } else {
            if (w.count(-i)) {
                c += (long long)w[i] * w[-i];
            }
        }
    }
    
    cout << c / 2 << endl;
    return 0;
}

// <END-OF-CODE>
