#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int f(int n) {
    int y = 1;
    while (n != 1) {
        if (n % 2) {
            y += 1;
        }
        n /= 2;
    }
    return y;
}

int nPairsWithCommonFX(const vector<int>& sequence) {
    unordered_map<int, vector<int>> storage;
    vector<int> FXs;

    for (int value : sequence) {
        int y = f(value);
        if (storage.find(y) == storage.end()) {
            storage[y] = {value};
            FXs.push_back(y);
        } else {
            storage[y].push_back(value);
        }
    }

    int totalPairs = 0;
    for (int y : FXs) {
        int count = storage[y].size();
        totalPairs += count * count;
    }

    int totalSingleCounts = 0;
    for (int y : FXs) {
        totalSingleCounts += storage[y].size();
    }

    return (totalPairs - totalSingleCounts) / 2;
}

int main() {
    int n;
    cin >> n; // Read the number of elements
    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i]; // Read the elements
    }
    cout << nPairsWithCommonFX(sequence) << endl;
    return 0;
}

// <END-OF-CODE>
