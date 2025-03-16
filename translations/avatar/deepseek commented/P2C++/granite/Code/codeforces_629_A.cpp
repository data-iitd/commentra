

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> cake(n);
    for (int i = 0; i < n; i++) {
        cin >> cake[i];
    }
    int happiness = 0;
    int chocCount = 0;
    int nfat = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }
        if (chocCount > 1) {
            for (int i = chocCount; i > 1; i--) {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }
    int posCount = 0;
    for (int j = 0; j < n; j++) {
        chocCount = 0;
        for (int i = 0; i < n; i++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }
        if (chocCount > 1) {
            for (int i = chocCount; i > 1; i--) {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }
    cout << happiness << endl;
    return 0;
}
