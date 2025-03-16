#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N = 368;
    vector<int> m(N, 0);
    vector<int> f(N, 0);
    
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after the integer input

    for (int i = 0; i < T; i++) {
        string x;
        int a, b;
        getline(cin, x);
        size_t pos1 = x.find(' ');
        size_t pos2 = x.find(' ', pos1 + 1);
        
        a = stoi(x.substr(pos1 + 1, pos2 - pos1 - 1));
        b = stoi(x.substr(pos2 + 1)) + 1;

        if (x[0] == 'M') {
            m[a] += 2;
            m[b] -= 2;
        } else {
            f[a] += 2;
            f[b] -= 2;
        }
    }

    int a_sum = 0, b_sum = 0, c = 0;
    for (int i = 0; i < N; i++) {
        a_sum += m[i];
        b_sum += f[i];
        if (min(a_sum, b_sum) > c) {
            c = min(a_sum, b_sum);
        }
    }

    cout << c << endl;

    return 0;
}

// <END-OF-CODE>
