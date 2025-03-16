#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int t, m;
    cin >> t >> m;
    vector<int> alocuente(m, 0);
    int ind = 1;
    cin.ignore(); // To ignore the newline after reading integers

    for (int i = 0; i < t; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string op;
        ss >> op;

        if (op == "alloc") {
            int size;
            ss >> size;
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
        }

        if (op == "erase") {
            int arg;
            ss >> arg;
            if (find(alocuente.begin(), alocuente.end(), arg) == alocuente.end() || arg == 0) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            } else {
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == arg) {
                        alocuente[j] = 0;
                    }
                }
            }
        }

        if (op == "defragment") {
            int cnt = count(alocuente.begin(), alocuente.end(), 0);
            alocuente.erase(remove(alocuente.begin(), alocuente.end(), 0), alocuente.end());
            alocuente.resize(alocuente.size() + cnt, 0);
        }
    }

    return 0;
}

// <END-OF-CODE>
