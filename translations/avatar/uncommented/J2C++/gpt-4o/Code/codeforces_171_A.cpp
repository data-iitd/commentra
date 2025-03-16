#include <iostream>
#include <sstream>
#include <string>

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
            return stoi(next());
        }

        long long nextLong() {
            return stoll(next());
        }

        double nextDouble() {
            return stod(next());
        }

        string nextLine() {
            string s;
            cin.ignore();
            getline(cin, s);
            return s;
        }
};

int reverse(int n) {
    if (n < 10) return n * 10;
    int t = n, r = 0;
    while (t > 0) {
        r = (r * 10) + t % 10;
        t = t / 10;
    }
    return r;
}

int main() {
    FastReader sc;
    int n = sc.nextInt();
    int m = sc.nextInt();
    int t = reverse(m);
    cout << t + n << endl;
    return 0;
}

// <END-OF-CODE>
