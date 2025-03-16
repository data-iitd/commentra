

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t, m;
    cin >> t >> m;
    vector<int> memory(m, 0);
    int id = 1;
    for (int i = 0; i < t; i++) {
        string op;
        cin >> op;
        if (op == "alloc") {
            int size;
            cin >> size;
            int pos = 0;
            for (int j = 0; j < m; j++) {
                if (memory[j] == 0) {
                    pos++;
                    if (pos == size) {
                        for (int k = j - size + 1; k <= j; k++) {
                            memory[k] = id;
                        }
                        cout << id << endl;
                        id++;
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
            int num;
            cin >> num;
            if (num <= 0 || num > id - 1) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            } else {
                for (int j = 0; j < m; j++) {
                    if (memory[j] == num) {
                        memory[j] = 0;
                    }
                }
            }
        } else if (op == "defragment") {
            int cnt = count(memory.begin(), memory.end(), 0);
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                if (memory[j]!= 0) {
                    temp.push_back(memory[j]);
                }
            }
            for (int j = 0; j < cnt; j++) {
                temp.push_back(0);
            }
            memory = temp;
        }
    }
    return 0;
}
