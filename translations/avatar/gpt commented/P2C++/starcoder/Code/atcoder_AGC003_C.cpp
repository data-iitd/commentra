#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = (i * N + cin.get()) % 2;
    }
    sort(A.begin(), A.end());
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] % 2!= i % 2) {
            cnt++;
        }
    }
    cout << cnt / 2 << endl;
    return 0;
}
