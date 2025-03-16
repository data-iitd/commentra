#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<vector<string>> t(4, vector<string>(1));
    for (int i = 0; i < 4; i++) {
        cin >> t[i][0]; // Read input as a single string
    }

    int black = 0;
    int white = 0;
    int correct = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            black = 0;
            white = 0;

            // Check the 2x2 square
            for (int di = 0; di < 2; di++) {
                for (int dj = 0; dj < 2; dj++) {
                    if (t[i + di][0][j + dj] == '#') {
                        black++;
                    } else {
                        white++;
                    }
                }
            }

            if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4) {
                correct = 1;
                break;
            }
        }
        if (correct == 1) {
            break;
        }
    }

    if (correct == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

// <END-OF-CODE>
