#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> cake;
    double happiness = 0;
    int chocCount = 0;
    int nfat = 1;

    // Read the cake input
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        cake.push_back(line);
        for (char j : line) {
            if (j == 'C') {
                chocCount++;
            }
        }
        if (chocCount > 1) {
            for (int k = chocCount; k > chocCount - 2; k--) {
                nfat *= k;
            }
            happiness += nfat / 2.0;
        }
        nfat = 1;
        chocCount = 0;
    }

    // Count chocolates in columns
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }
        if (chocCount > 1) {
            for (int k = chocCount; k > chocCount - 2; k--) {
                nfat *= k;
            }
            happiness += nfat / 2.0;
        }
        nfat = 1;
        chocCount = 0;
    }

    cout << static_cast<int>(happiness) << endl;

    return 0;
}

// <END-OF-CODE>
