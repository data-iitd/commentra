
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int** black = new int*[N + 2];
    for (int i = 0; i < N + 2; i++) {
        black[i] = new int[N + 2];
    }

    for (int m = 1; m <= M; m++) {
        int x, y;
        cin >> x >> y;

        for (int xx = x - 1; xx <= x + 1; xx++) {
            for (int yy = y - 1; yy <= y + 1; yy++) {
                if (++black[xx][yy] == 9) {
                    cout << m << endl;
                    return 0;
                }
            }
        }
    }

    cout << "-1" << endl;

    return 0;
}

