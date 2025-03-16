
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
        int a;
        cin >> a;
        m[a]++;
    }
    for (int i = 0; i < M; i++) {
        int B, C;
        cin >> B >> C;
        m[C] += B;
    }
    vector<int> ints;
    for (auto &p : m) {
        ints.push_back(p.first);
    }
    sort(ints.begin(), ints.end(), greater<int>());
    int rest = N;
    int sum = 0;
    for (int i : ints) {
        int num = m[i];
        if (num >= rest) {
            sum += rest * i;
            break;
        }
        sum += num * i;
        rest -= num;
    }
    cout << sum << endl;
}

