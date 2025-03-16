// problem_b.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

const int constMod = 1e9 + 7;

int getInt() {
    int x;
    std::cin >> x;
    return x;
}

std::vector<int> getIntSlice(int n) {
    std::vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        ns[i] = getInt();
    }
    return ns;
}

void solve() {
    int n = getInt();
    int m = getInt();
    std::vector<int> a = getIntSlice(n);

    int sum = std::accumulate(a.begin(), a.end(), 0);

    int count = 0;
    double rate = static_cast<double>(sum) / (4 * m);
    for (int v : a) {
        if (static_cast<double>(v) >= rate) {
            count++;
        }
    }

    if (count >= m) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}

int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
