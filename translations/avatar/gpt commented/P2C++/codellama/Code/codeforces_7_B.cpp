#include <iostream>
#include <vector>

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
            int pos = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    pos++;
                    if (pos == stoi(op.substr(6))) {
                        for (int k = j - stoi(op.substr(6)) + 1; k <= j; k++) {
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
            if (pos == 0) {
                cout << "NULL" << endl;
            }
        }

        if (op == "erase") {
            int pos = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == stoi(op.substr(6))) {
                    alocuente[j] = 0;
                    break;
                }
            }
            if (alocuente[j] != stoi(op.substr(6))) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        }

        if (op == "defragment") {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    cnt++;
                }
            }
            vector<int> alocuente_new;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] != 0) {
                    alocuente_new.push_back(alocuente[j]);
                }
            }
            for (int j = 0; j < cnt; j++) {
                alocuente_new.push_back(0);
            }
            alocuente = alocuente_new;
        }
    }

    return 0;
}

