// ABC 152-D
// 2020.1.19 bal4u

#include <iostream>
#include <vector>

#define gc() getchar_unlocked()

int in() {   // Non-negative integer input
    int n = 0, c = gc();
    do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
    return n;
}

std::vector<int> f1(100), f2(100);

void calc(int n) {
    int k = n % 10;
    while (n >= 10) n /= 10;
    ++f1[10 * k + n];
    ++f2[n * 10 + k];
}

int main() {
    int i, N, ans;

    N = in();
    while (N) calc(N--);

    ans = 0;
    for (i = 0; i < 100; ++i) ans += f1[i] * f2[i];
    std::cout << ans << std::endl;
    return 0;
}

// <END-OF-CODE>
