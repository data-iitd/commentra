#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int mod = 1e9 + 7;
    int N, A, B;
    cin >> N >> A >> B;
    
    long long ans = 0;
    int rep = N / (A + B);
    ans += rep * A;
    int res = N - rep * (A + B);
    ans += min(res, A);
    
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
