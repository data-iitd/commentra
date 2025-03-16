#include <bits/stdc++.h>
using namespace std;

bool isSolution(int columnsCount, string x) {
    bool allXs[columnsCount];
    for (int i = 0; i < columnsCount; i++) {
        allXs[i] = true;
    }
    for (int i = 0; i < 12; i++) {
        if (x[i]!= 'X') {
            allXs[i % columnsCount] = false;
        }
    }
    for (int i = 0; i < columnsCount; i++) {
        if (allXs[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int possibleSolutions = 0;
        string s;
        cin >> s;
        if (isSolution(12, s)) {
            cout << " 1x12" << endl;
            possibleSolutions++;
        }
        if (isSolution(6, s)) {
            cout << " 2x6" << endl;
            possibleSolutions++;
        }
        if (isSolution(4, s)) {
            cout << " 3x4" << endl;
            possibleSolutions++;
        }
        if (isSolution(3, s)) {
            cout << " 4x3" << endl;
            possibleSolutions++;
        }
        if (isSolution(2, s)) {
            cout << " 6x2" << endl;
            possibleSolutions++;
        }
        if (isSolution(1, s)) {
            cout << " 12x1" << endl;
            possibleSolutions++;
        }
        cout << possibleSolutions << endl;
    }
    return 0;
}

