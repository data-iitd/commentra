
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N;
    cin >> N;

    int total = 0;
    for (int i = 0; i < N; i++) {
        int ai;
        cin >> ai;
        total ^= ai;
    }

    for (int i = 0; i < N; i++) {
        int ai;
        cin >> ai;
        cout << (ai ^ total) << " ";
    }

    return 0;
}

