#include <iostream>
#include <algorithm>

using namespace std;

class FastReader {
    public:
        FastReader() {}

        string next() {
            string s;
            cin >> s;
            return s;
        }

        long long nextLong() {
            long long x;
            cin >> x;
            return x;
        }
};

int main() {
    FastReader in;
    long long a[4];
    for (int i = 0; i < 4; i++) {
        a[i] = in.nextLong();
    }
    cout << max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))) << endl;
    return 0;
}

// <END-OF-CODE>
