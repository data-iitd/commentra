
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int inp;
    cin >> inp;

    vector<int> lista;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    while (ss >> x) {
        lista.push_back(x);
    }

    for (int i = 0; i < lista.size(); i++) {
        if (i == 0) {
            cout << lista[i+1] - lista[i] << " " << lista[lista.size()-1] - lista[i] << endl;
            continue;
        }

        if (i == lista.size() - 1) {
            cout << lista[lista.size()-1] - lista[lista.size()-2] << " " << lista[lista.size()-1] - lista[0] << endl;
            continue;
        }

        if (lista[i] - lista[i-1] > lista[i+1] - lista[i]) {
            cout << lista[i+1] - lista[i] << " ";
        } else {
            cout << lista[i] - lista[i-1] << " ";
            if (lista[lista.size()-1] - lista[i] > lista[i] - lista[0]) {
                cout << lista[lista.size()-1] - lista[i] << endl;
            } else {
                cout << lista[i] - lista[0] << endl;
            }
        }
    }

    return 0;
}
