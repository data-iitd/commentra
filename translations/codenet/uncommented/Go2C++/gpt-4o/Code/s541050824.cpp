#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int64_t divUp(int64_t x, int64_t y) {
    return (x + y - 1) / y;
}

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> T(N), A(N);
    
    for (int64_t i = 0; i < N; i++) {
        cin >> T[i] >> A[i];
    }
    
    int64_t t = T[0], a = A[0];
    for (int64_t i = 1; i < N; i++) {
        int64_t r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }
    
    cout << t + a << endl;
    return 0;
}

// <END-OF-CODE>
