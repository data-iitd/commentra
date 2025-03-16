#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    if (N < 4) {
        cout << 0 << endl;
        return 0;
    }

    int nr = 0, nb = 0, ng = 0;
    for (char c : S) {
        if (c == 'R') {
            nr++;
        } else if (c == 'B') {
            nb++;
        } else if (c == 'G') {
            ng++;
        }
    }

    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0, j = 1 * a, k = 2 * a;
        if (k >= N) {
            break;
        }
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

// <END-OF-CODE>
