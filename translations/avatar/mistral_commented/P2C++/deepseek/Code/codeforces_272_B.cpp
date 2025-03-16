#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;

// This function takes an integer as input and returns its FX value
int f(int n) {
    int fx = 1;
    while (n != 1) {
        if (n % 2) {
            fx += 1;
        }
        n /= 2;
    }
    return fx;
}

// This function takes a sequence as input and returns the number of pairs with common FX
int nPairsWithCommonFX(vector<int>& sequence) {
    unordered_map<int, vector<int>> storage;
    vector<int> FXs;

    for (int value : sequence) {
        int fx = f(value);
        if (storage.find(fx) == storage.end()) {
            storage[fx] = {value};
            FXs.push_back(fx);
        } else {
            storage[fx].push_back(value);
        }
    }

    int result = 0;
    for (int fx : FXs) {
        int n = storage[fx].size();
        result += n * (n - 1) / 2;
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    int result = nPairsWithCommonFX(sequence);
    cout << result << endl;

    return 0;
}

