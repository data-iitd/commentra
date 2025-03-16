#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Main {
public:
    Main() : out(cout), sc(cin) {
        // Constructor initializes the output stream and the scanner
    }

    void main() {
        int n, k;
        sc >> n >> k;
        vector<int> bb(n);
        for (int i = 0; i < n; i++) {
            sc >> bb[i];
        }

        // Initialize an array to store the result
        vector<int> aa(n);
        int m = 0;

        // Process the array bb in reverse order
        for (int a = n - 1; a >= 0; a--) {
            int j = 0;
            while (bb[a] > 0) {
                if (j < m && aa[j] >= a + k) {
                    bb[a]--;
                }
                j++;
            }
            for (int j_ = m++; j_ > j; j_--) {
                aa[j_] = aa[j_ - 1];
            }
            aa[j] = a;
        }

        // Print the contents of the array aa, incrementing each element by 1
        for (int i = 0; i < n; i++) {
            out << aa[i] + 1 << " ";
        }
        out << endl;
    }

private:
    ostream& out;
    istream& sc;
};

int main() {
    Main o;
    o.main();
    return 0;
}

