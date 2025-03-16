
#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N < 4) {
        cout << 0 << endl;
        return 0;
    }

    string S;
    cin >> S;

    int nr = 0, nb = 0, ng = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            nr++;
        } else if (S[i] == 'B') {
            nb++;
        } else if (S[i] == 'G') {
            ng++;
        }
    }

    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0, j = a, k = 2 * a;
        while (k < N) {
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++;
            }
            i++;
            j++;
            k++;
        }
    }

    int tot = nr * nb * ng;
    cout << tot - same << endl;

    return 0;
}

