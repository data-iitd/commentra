#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int nr = 0, nb = 0, ng = 0;
    for (char c : S) {
        if (c == 'R') nr++;
        else if (c == 'B') nb++;
        else if (c == 'G') ng++;
    }

    int same = 0;
    for (int a = 1; a < N; ++a) {
        for (int i = 0, j = a, k = 2 * a; k < N; ++i, ++j, ++k) {
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++;
            }
        }
    }

    int tot = nr * nb * ng;
    cout << (tot - same) << endl;

    return 0;
}

