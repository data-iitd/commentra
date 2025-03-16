#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    map<int, int> m;
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        m[x]++;
    }

    for (int i = 0; i < M; i++) {
        int B, C;
        cin >> B >> C;
        m[C] += B;
    }

    vector<int> ints;
    for (const auto& pair : m) {
        ints.push_back(pair.first);
    }

    sort(ints.rbegin(), ints.rend());
    int rest = N;
    long long sum = 0;

    for (int i : ints) {
        int num = m[i];
        if (num >= rest) {
            sum += static_cast<long long>(rest) * i;
            break;
        }
        sum += static_cast<long long>(num) * i;
        rest -= num;
    }

    cout << sum << endl;
    return 0;
}

// <END-OF-CODE>
