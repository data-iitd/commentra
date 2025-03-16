#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, d, x;
    cin >> N >> d >> x;

    auto main_cpp = [&](int N, int d, int x) -> int {
        int ret = 0;

        while (N) {
            ret += d + (N - 0.5) * x;
            d = d + (d / N) + (5 * x) / (2 * N);
            x += 2 * x / N;
            N -= 1;
        }

        return ret;
    };

    cout << main_cpp(N, d, x) << endl;

    return 0;
}

