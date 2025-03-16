#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int f(int n) {
    int y = 1;
    while (n != 1) {
        if (n % 2) {
            y++;
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
        int size = storage[y].size();
        totalPairs += size * size;
    }

    int singleOccurrences = 0;
    for (int y : FXs) {
        singleOccurrences += storage[y].size();
    }

    return (totalPairs - singleOccurrences) / 2;
}

int main() {
    // Read input from the user (not stored, just consumed)
    string temp;
    getline(cin, temp);
    
    // Read the sequence of integers
    vector<int> sequence;
    int value;
    while (cin >> value) {
        sequence.push_back(value);
    }

    // Process the input sequence and return the number of pairs with common factors
    cout << nPairsWithCommonFX(sequence) << endl;

    return 0;
}

// <END-OF-CODE>
