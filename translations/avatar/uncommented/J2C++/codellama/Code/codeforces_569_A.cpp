#include <iostream>
using namespace std;
int main() {
    int T, S, q, answer;
    cin >> T >> S >> q;
    long previous = S;
    while (previous < T) {
        answer++;
        previous *= q;
    }
    cout << answer << endl;
    return 0;
}
