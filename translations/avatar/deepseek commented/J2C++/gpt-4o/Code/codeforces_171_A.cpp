#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class FastReader {
    public:
        FastReader() {}

        string next() {
            string input;
            getline(cin, input);
            return input;
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

int reverse(int n) {
    if (n < 10) return n * 10; // If the number is a single digit, return it multiplied by 10
    int t = n, r = 0;
    while (t > 0) {
        r = (r * 10) + t % 10; // Reverse the number
        t = t / 10;
    }
    return r;
}

int main() {
    FastReader sc;
    int n = sc.nextInt(); // Read the first integer
    int m = sc.nextInt(); // Read the second integer
    int t = reverse(m); // Reverse the second integer
    cout << (t + n) << endl; // Print the sum of the reversed integer and the first integer
    return 0;
}

// <END-OF-CODE>
