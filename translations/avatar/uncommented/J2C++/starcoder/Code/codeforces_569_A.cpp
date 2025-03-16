#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, S, q, previous, answer;
    cin >> T >> S >> q;
    previous = S;
    answer = 0;
    while (previous < T) {
        answer++;
        previous *= q;
    }
    cout << answer << endl;
    return 0;
}
