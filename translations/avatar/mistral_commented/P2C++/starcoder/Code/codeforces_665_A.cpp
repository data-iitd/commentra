#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, at;
    cin >> a >> at;
    int b, bt;
    cin >> b >> bt;
    int t1, t2;
    cin >> t1 >> t2;
    int st = t2 + (t1 - 5) * 60;
    int fin = st + at;
    int now = 0;
    int ans = 0;
    while (now < fin && now < 1140) {
        if (now + bt > st) {
            ans += 1;
        }
        now += b;
    }
    cout << ans << endl;
    return 0;
}
