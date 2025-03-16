#include <iostream>
#include <vector>
#include <string>
#include <limits>

#define INF std::numeric_limits<int>::max()

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int w;
    std::cin >> w;
    std::vector<int> a(w + 1);
    std::vector<int> b(w + 1);
    int ans = 0, f = 0;

    for (int i = 1; i <= w; ++i) {
        std::cin >> a[i];
        if (a[i] == 0) f |= 1;
        else if (a[i] < 0) f |= 2;
        else ans += a[i];
    }

    if (ans == 0 || !(f & 1)) {
        std::cout << "0\n";
        return 0;
    }

    if (!(f & 2)) {
        std::cout << ans << '\n';
        return 0;
    }

    int close = 0, f_pos = 0;
    for (int i = 1; i <= w; ++i) {
        if (a[i] == 0) close = INF, f_pos = -1;
        else if (a[i] < 0) {
            if (f_pos < 0 || close - (i - f_pos) > -a[i]) close = -a[i], f_pos = i;
        } else {
            if (f_pos < 0) b[i] = INF;
            else {
                int k = close - (i - f_pos);
                if (k < 0) k = 0;
                b[i] = k;
            }
        }
    }

    close = 0, f_pos = w;
    for (int i = w; i >= 1; --i) {
        if (a[i] == 0) close = INF, f_pos = -1;
        else if (a[i] < 0) {
            if (f_pos < 0 || close - (f_pos - i) > -a[i]) close = -a[i], f_pos = i;
        } else {
            if (f_pos < 0) b[i] = INF;
            else {
                int k = close - (f_pos - i);
                if (k < 0) k = 0;
                if (k > b[i]) b[i] = k;
            }
        }
    }

    ans = 0;
    for (int i = 1; i <= w; ++i) {
        if (a[i] > 0) {
            if (b[i] > a[i]) ans += a[i];
            else ans += b[i];
        }
    }

    std::cout << ans << '\n';
    return 0;
}
