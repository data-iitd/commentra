
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> lista;
    vector<int> listb;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        lista.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        listb.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (lista[i] == i + 1) {
            cout << 1 << " ";
        } else {
            cout << 2 << " ";
        }
    }
    return 0;
}

