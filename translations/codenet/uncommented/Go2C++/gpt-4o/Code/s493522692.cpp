#include <iostream>
#include <algorithm>
using namespace std;

// Utility functions
int nextInt() {
    int x;
    cin >> x;
    return x;
}

int main() {
    // 'S'がN個、'c'がM個
    int N = nextInt();
    int M = nextInt();
    
    int tmp = min(N, M / 2);
    int ans = 0;
    ans += tmp;
    N -= tmp;
    M -= tmp * 2;

    cout << ans + M / 4 << endl;

    return 0;
}

// <END-OF-CODE>
