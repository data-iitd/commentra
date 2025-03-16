#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N = 368;
    vector<int> m(N, 0);
    vector<int> f(N, 0);

    int num_operations;
    cin >> num_operations;
    cin.ignore(); // To ignore the newline character after the number of operations

    for (int i = 0; i < num_operations; ++i) {
        string operation;
        int a, b;
        getline(cin, operation);
        // Extracting the relevant parts of the operation
        size_t pos_x = operation.find(' ');
        size_t pos_a = operation.find(' ', pos_x + 1);
        size_t pos_b = operation.find(' ', pos_a + 1);
        string x = operation.substr(0, pos_x);
        a = stoi(operation.substr(pos_x + 1, pos_a - pos_x - 1));
        b = stoi(operation.substr(pos_a + 1, pos_b - pos_a - 1));
        b += 1; // Adjusting the end index

        if (x == "M") {
            m[a] += 2;
            m[b] -= 2;
        } else if (x == "F") {
            f[a] += 2;
            f[b] -= 2;
        }
    }

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < N; ++i) {
        a += m[i];
        b += f[i];
        if (min(a, b) > c) {
            c = min(a, b);
        }
    }

    cout << c << endl;

    return 0;
}
