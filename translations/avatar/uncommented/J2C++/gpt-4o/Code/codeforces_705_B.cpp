#include <iostream>
#include <vector>
using namespace std;

class FastReader {
    public:
        FastReader() {}

        string next() {
            string s;
            cin >> s;
            return s;
        }

        int nextInt() {
            int x;
            cin >> x;
            return x;
        }

        long long nextLong() {
            long long x;
            cin >> x;
            return x;
        }

        double nextDouble() {
            double x;
            cin >> x;
            return x;
        }

        string nextLine() {
            string s;
            cin.ignore();
            getline(cin, s);
            return s;
        }
};

void solve() {
    FastReader scan;
    int t = scan.nextInt();
    vector<int> arr(t);
    for (int i = 0; i < t; i++) {
        arr[i] = scan.nextInt();
    }
    
    int prevWinner = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            if (prevWinner == 0) {
                prevWinner = 2;
            }
        }
        if (prevWinner == 2 || prevWinner == 0) {
            if ((arr[i] - 1) % 2 == 0) {
                cout << 2 << endl;
                prevWinner = 2;
            } else {
                cout << 1 << endl;
                prevWinner = 1;
            }
        } else {
            if ((arr[i] - 1) % 2 == 0) {
                cout << 1 << endl;
                prevWinner = 1;
            } else {
                cout << 2 << endl;
                prevWinner = 2;
            }
        }
    }
}

int main() {
    int t = 1;
    while (t-- > 0) {
        solve();
    }
    return 0;
}

// <END-OF-CODE>
