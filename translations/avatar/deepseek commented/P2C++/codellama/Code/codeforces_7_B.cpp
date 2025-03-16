
#include <iostream>
#include <string>
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
            int size;
            cin >> size;
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
            if (pos == 0) {
                cout << "NULL" << endl;
            }
        }
        if (op == "erase") {
            int pos;
            cin >> pos;
            if (alocuente[pos - 1] == 0 || pos == 0) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            } else {
                alocuente[pos - 1] = 0;
            }
        }
        if (op == "defragment") {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (alocuente[j] == 0) {
                    cnt++;
                }
            }
            alocuente.erase(alocuente.begin() + m - cnt, alocuente.end());
            for (int j = 0; j < cnt; j++) {
                alocuente.push_back(0);
            }
        }
    }
    return 0;
}

