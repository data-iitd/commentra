// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

#include <iostream>
#include <vector>
#include <limits>

#define INF 0x5fffffff

int main() {
    int w, k, f, close, ans;
    std::cin >> w;

    std::vector<int> a(w + 1);
    std::vector<int> b(w + 1);

    ans = 0;
    f = 0;

    for (int i = 1; i <= w; i++) {
        std::cin >> k;
        a[i] = k;
        if (k == 0) f |= 1;
        else if (k < 0) f |= 2;
        else ans += k;
    }

    if (ans == 0 || !(f & 1)) {
        std::cout << "0\n";
        return 0;
    }
    if (!(f & 2)) {
        std::cout << ans << "\n";
        return 0;
    }

    close = 0;
    f = 0;

    for (int i = 1; i <= w; i++) {
        if (a[i] == 0) {
            close = INF;
            f = -1;
        } else if (a[i] < 0) {
            if (f < 0 || close - (i - f) > -a[i]) {
                close = -a[i];
                f = i;
            }
        } else {
            if (f < 0) {
                b[i] = INF;
            } else {
                k = close - (i - f);
                if (k < 0) k = 0;
                b[i] = k;
            }
        }
    }

    close = 0;
    f = w;

    for (int i = w; i >= 1; i--) {
        if (a[i] == 0) {
            close = INF;
            f = -1;
        } else if (a[i] < 0) {
            if (f < 0 || close - (f - i) > -a[i]) {
                close = -a[i];
                f = i;
            }
        } else {
            if (f < 0) {
                b[i] = INF;
            } else {
                k = close - (f - i);
                if (k < 0) k = 0;
                if (k > b[i]) b[i] = k;
            }
        }
    }

    ans = 0;
    for (int i = 1; i <= w; i++) {
        if (a[i] > 0) {
            if (b[i] > a[i]) ans += a[i];
            else ans += b[i];
        }
    }

    std::cout << ans << "\n";
    return 0;
}

// <END-OF-CODE>
