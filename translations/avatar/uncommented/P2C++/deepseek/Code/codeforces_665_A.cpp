#include <iostream>
#include <string>
#include <sstream>

int main() {
    int a, at;
    int b, bt;
    int t1, t2;
    int st, fin, now, ans;

    std::cin >> a >> b;
    std::cin >> t1 >> t2;

    st = t2 + (t1 - 5) * 60;
    fin = st + at;
    now = 0;
    ans = 0;

    while (now < fin && now < 1140) {
        if (now + bt > st) {
            ans += 1;
        }
        now += b;
    }

    std::cout << ans << std::endl;

    return 0;
}

