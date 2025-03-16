#include <iostream>
#include <vector>

using namespace std;

void kansu(int a, int b);

int main() {
    int a, b;

    cin >> a >> b;
    while (a != 0 && b != 0) {
        kansu(a, b);
        cin >> a >> b;
    }
    return 0;
}

void kansu(int a, int b) {
    int i, j, x, y, n;
    vector<vector<int>> suu(a + 1, vector<int>(b + 1, 0));
    vector<vector<int>> kouji(a + 1, vector<int>(b + 1, 0));

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        kouji[x][y] = 1;
    }

    for (i = 1; i <= a; i++) {
        for (j = 1; j <= b; j++) {
            if (kouji[i][j] == 1) {
                suu[i][j] = 0;
            } else {
                if (i == 1 && j == 1) {
                    suu[i][j] = 1;
                } else {
                    if (i == 1) {
                        suu[i][j] = suu[i][j - 1];
                    } else if (j == 1) {
                        suu[i][j] = suu[i - 1][j];
                    } else {
                        suu[i][j] = suu[i][j - 1] + suu[i - 1][j];
                    }
                }
            }
        }
    }
    cout << suu[a][b] << endl;
}

// <END-OF-CODE>
