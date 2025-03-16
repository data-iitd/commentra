#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    # ceil((N-1) / (K-1))
    count = ((N - 1) + ((K - 1) - 1)) / (K - 1)
    print(count)
}

