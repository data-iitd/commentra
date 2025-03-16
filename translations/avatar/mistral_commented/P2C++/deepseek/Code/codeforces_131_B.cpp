#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> w;
    vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        w[numbers[i]]++;
    }

    int c = 0;

    for (const auto& pair : w) {
        int i = pair.first;
        if (i == 0) {
            c += pair.second * (pair.second - 1);
        } else if (w.find(-i) != w.end()) {
            c += pair.second * w[-i];
        }
    }

    cout << c / 2 << endl;

    return 0;
}

