
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
    for (auto it = w.begin(); it!= w.end(); it++) {
        if (it->first == 0) {
            c += it->second * (it->second - 1);
        } else if (w.find(-it->first)!= w.end()) {
            c += it->second * w[-it->first];
        }
    }

    cout << c / 2 << endl;

    return 0;
}

