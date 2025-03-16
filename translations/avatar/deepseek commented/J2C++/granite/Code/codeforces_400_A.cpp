

#include <bits/stdc++.h>
using namespace std;

bool isSolution(int columnsCount, string x) {
    bool allXs[columnsCount];
    fill(allXs, allXs + columnsCount, true);
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
    while (t--) {
        int possibleSolutions = 0;
        string solutions = "";
        string s;
        cin >> s;
        if (isSolution(12, s)) {
            solutions += " 1x12";
            possibleSolutions++;
        }
        if (isSolution(6, s)) {
            solutions += " 2x6";
            possibleSolutions++;
        }
        if (isSolution(4, s)) {
            solutions += " 3x4";
            possibleSolutions++;
        }
        if (isSolution(3, s)) {
            solutions += " 4x3";
            possibleSolutions++;
        }
        if (isSolution(2, s)) {
            solutions += " 6x2";
            possibleSolutions++;
        }
        if (isSolution(1, s)) {
            solutions += " 12x1";
            possibleSolutions++;
        }
        cout << possibleSolutions << endl << solutions << endl;
    }
    return 0;
}

