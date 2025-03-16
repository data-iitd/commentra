#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k;
    string input;
    getline(cin, input);
    n = stoi(input.substr(0, input.find(' ')));
    k = stoi(input.substr(input.find(' ') + 1));

    vector<int> M(n);
    getline(cin, input);
    int index = 0;
    for (int i = 0; i < n; ++i) {
        int num = 0;
        while (input[index] != ' ' && index < input.size()) {
            num = num * 10 + (input[index] - '0');
            ++index;
        }
        ++index; // skip the space
        M[i] = num;
    }

    int m = 0;
    for (int j = 0; j < n; ++j) {
        for (int p = 0; p < n; ++p) {
            if (M[p] == 0) {
                cout << p + 1 << " ";
                break;
            }
        }
        for (int l = 0; l < p + 1 - k; ++l) {
            M[l] -= 1;
        }
        M[p] -= 1;
    }

    cout << endl;
    return 0;
}
