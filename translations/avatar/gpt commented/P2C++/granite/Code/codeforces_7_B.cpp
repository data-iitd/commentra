
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, m;
    cin >> t >> m;
    vector<int> alocuente(m, 0);
    int ind = 1;

    for (int i = 0; i < t; i++) {
        string op;
        cin >> op;
        if (op == "alloc") {
            int size;
            cin >> size;
            int pos = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    pos++;
                    if (pos == size) {
                        for (int k = j - size + 1; k <= j; k++) {
                            alocuente[k] = ind;
                        }
                        cout << ind << endl;
                        ind++;
                        break;
                    }
                } else {
                    pos = 0;
                }
            }
            if (pos < size) {
                cout << "NULL" << endl;
            }
        } else if (op == "erase") {
            int id;
            cin >> id;
            if (id <= 0 || id > ind - 1) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            } else {
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == id) {
                        alocuente[j] = 0;
                    }
                }
            }
        } else if (op == "defragment") {
            int cnt = count(alocuente.begin(), alocuente.end(), 0);
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                if (alocuente[j]!= 0) {
                    temp.push_back(alocuente[j]);
                }
            }
            for (int j = 0; j < cnt; j++) {
                temp.push_back(0);
            }
            alocuente = temp;
        }
    }
    return 0;
}
