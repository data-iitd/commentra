
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> lista(a);
    vector<int> listb(b);
    for (int i = 0; i < a; i++) {
        cin >> lista[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> listb[i];
    }
    for (int i = 1; i <= n; i++) {
        if (find(lista.begin(), lista.end(), i)!= lista.end()) {
            cout << 1 << " ";
        } else {
            cout << 2 << " ";
        }
    }
    return 0;
}

