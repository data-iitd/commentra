#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class FastReader {
public:
    FastReader() {
        cin.tie(0);
        ios::sync_with_stdio(false);
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
        string str;
        getline(cin, str);
        return str;
    }
};

FastReader scan;

void solve() {
    int t = scan.nextInt();
    vector<int> arr(t);
    for (int i = 0; i < arr.size(); i++) {
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
                cout << 2 << '\n';
                prevWinner = 2;
            } else {
                cout << 1 << '\n';
                prevWinner = 1;
            }
        } else {
            if ((arr[i] - 1) % 2 == 0) {
                cout << 1 << '\n';
                prevWinner = 1;
            } else {
                cout << 2 << '\n';
                prevWinner = 2;
            }
        }
    }
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
