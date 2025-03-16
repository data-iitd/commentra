#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int>> shops(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        shops[i] = make_tuple(a, b);
    }
    sort(shops.begin(), shops.end());

    ll total = 0;
    for (const auto& shop : shops) {
        int a = get<0>(shop);
        int b = get<1>(shop);
        int n = min(b, M);
        total += static_cast<ll>(n) * a;
        M -= n;
        if (M == 0) {
            break;
        }
    }
    cout << total << endl;
    return 0;
}
