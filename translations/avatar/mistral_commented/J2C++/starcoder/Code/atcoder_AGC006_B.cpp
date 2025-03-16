
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    print(x, n);
    return 0;
}

void print(int x, int n) {
    int max = n * 2 - 1;
    if (x == 1 || x == max) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    string sep = "\n";
    string ans = accumulate(IntStream.range(x + n - 1, x + n + max - 1).mapToObj(e -> to_string(e % max + 1) + sep),
                          "",
                          [](string a, string b) { return a + b; });
    cout << ans;
}

