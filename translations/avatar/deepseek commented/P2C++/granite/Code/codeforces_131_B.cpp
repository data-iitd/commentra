

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> w;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        w[x]++;
    }

    int c = 0;
    for (auto p : w) {
        if (p.first == 0) {
            c += p.second * (p.second - 1);
        } else {
            if (w.count(-p.first)) {
                c += p.second * w[-p.first];
            }
        }
    }

    cout << c / 2 << endl;

    return 0;
}

