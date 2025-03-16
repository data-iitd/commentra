#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class FastReader {
    public:
    FastReader() {
        cin.tie(0);
        ios::sync_with_stdio(false);
    }

    string next() {
        string str;
        cin >> str;
        return str;
    }

    int nextInt() {
        int num;
        cin >> num;
        return num;
    }

    long long nextLong() {
        long long num;
        cin >> num;
        return num;
    }

    double nextDouble() {
        double num;
        cin >> num;
        return num;
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
    cout << t + n << endl; // Print the sum of the reversed integer and the first integer
    return 0;
}
