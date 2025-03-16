
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int inp;
    cin >> inp;

    vector<int> lista;
    int temp;
    for (int i = 0; i < inp; i++) {
        cin >> temp;
        lista.push_back(temp);
    }

    for (int i = 0; i < inp; i++) {
        if (i == 0) {
            cout << lista[i + 1] - lista[i] << " " << lista[inp - 1] - lista[i] << endl;
            continue;
        }

        if (i == inp - 1) {
            cout << lista[inp - 1] - lista[inp - 2] << " " << lista[inp - 1] - lista[0] << endl;
            continue;
        }

        if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            cout << lista[i + 1] - lista[i] << " ";
        } else {
            cout << lista[i] - lista[i - 1] << " ";
        }

        if (lista[inp - 1] - lista[i] > lista[i] - lista[0]) {
            cout << lista[inp - 1] - lista[i] << endl;
        } else {
            cout << lista[i] - lista[0] << endl;
        }
    }

    return 0;
}
