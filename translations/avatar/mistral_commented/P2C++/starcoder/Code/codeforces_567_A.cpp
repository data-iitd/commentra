#include <iostream>
#include <vector>

using namespace std;

int main() {
    int inp;
    cin >> inp;
    vector<int> lista;
    for (int i = 0; i < inp; i++) {
        int x;
        cin >> x;
        lista.push_back(x);
    }
    for (int i = 0; i < lista.size(); i++) {
        if (i == 0) {
            cout << lista[i+1] - lista[i] << " " << lista.back() - lista[i] << endl;
            continue;
        }
        if (i == lista.size() - 1) {
            cout << lista.back() - lista[i-1] << " " << lista.back() - lista[0] << endl;
            continue;
        }
        if (lista[i] - lista[i-1] > lista[i+1] - lista[i]) {
            cout << lista[i+1] - lista[i] << " ";
        } else {
            cout << lista[i] - lista[i-1] << " " << lista[i] - lista[0] << endl;
        }
    }
    return 0;
}
