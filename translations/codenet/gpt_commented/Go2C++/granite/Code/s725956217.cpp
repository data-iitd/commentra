
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shop {
    int a, b;
};

bool compareShops(const Shop& s1, const Shop& s2) {
    return s1.a < s2.a;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Shop> shops(N);
    for (int i = 0; i < N; i++) {
        cin >> shops[i].a >> shops[i].b;
    }

    sort(shops.begin(), shops.end(), compareShops);

    int total = 0;
    for (int i = 0; i < N; i++) {
        int n = min(shops[i].b, M);
        total += n * shops[i].a;
        M -= n;
        if (M == 0) {
            break;
        }
    }

    cout << total << endl;

    return 0;
}
