#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shop {
    int a, b;
};

bool compare(const Shop &x, const Shop &y) {
    return x.a < y.a;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Shop> shops(N);
    
    for (int i = 0; i < N; i++) {
        cin >> shops[i].a >> shops[i].b;
    }
    
    sort(shops.begin(), shops.end(), compare);
    
    int total = 0;
    for (const auto &shop : shops) {
        int n = min(shop.b, M);
        total += n * shop.a;
        M -= n;
        if (M == 0) {
            break;
        }
    }
    
    cout << total << endl;
    return 0;
}

// <END-OF-CODE>
