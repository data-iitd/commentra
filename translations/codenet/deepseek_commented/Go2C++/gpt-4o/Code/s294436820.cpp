#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

const int Black = 35;

// Function to count the number of black cells
int countBlack(int h, int w, const vector<vector<int>>& m) {
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == Black) {
                count++;
            }
        }
    }
    return count;
}

// Function to solve the problem
int solve(int h, int w, int a, const vector<vector<int>>& m) {
    int result = 0;
    for (int i = 0; i < (1 << h); i++) {
        for (int k = 0; k < (1 << w); k++) {
            vector<vector<int>> tmp = m; // Create a copy of the original matrix
            for (int j = 0; j < h; j++) {
                if (i & (1 << j)) { // Check if the j-th row is painted
                    fill(tmp[j].begin(), tmp[j].end(), 1);
                }
            }
            for (int j = 0; j < w; j++) {
                if (k & (1 << j)) { // Check if the j-th column is painted
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1;
                    }
                }
            }
            if (countBlack(h, w, tmp) == a) {
                result++;
            }
        }
    }
    return result;
}

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> m(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            m[i][j] = static_cast<int>(s[j]);
        }
    }

    int answer = solve(h, w, k, m);
    cout << answer << endl;

    return 0;
}

// <END-OF-CODE>
