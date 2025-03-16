#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    print(x, n);
}

void print(int x, int n) {
    int max = n * 2 - 1;
    if (x == 1 || x == max) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    string sep = "\n";
    string ans = accumulate(
        IntStream.range(x + n - 1, x + n + max - 1).boxed(),
        "",
        [](string a, int b) { return a + to_string(b % max + 1) + sep; });
    cout << ans;
}

