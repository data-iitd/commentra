#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> w;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    for (int i = 0; i < n; ++i) {
        ++w[weights[i]];
    }
    int c = 0;
    for (auto& p : w) {
        if (p.first == 0) {
            c += p.second * (p.second - 1);
        } else {
            if (w.find(-p.first) != w.end()) {
                c += p.second * w[-p.first];
            }
        }
    }
    cout << c / 2 << endl;
    return 0;
}
