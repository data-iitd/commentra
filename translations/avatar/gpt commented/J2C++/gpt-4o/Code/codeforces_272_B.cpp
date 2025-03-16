#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class FastReader {
public:
    FastReader() {}

    string next() {
        string token;
        cin >> token;
        return token;
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
        string line;
        cin.ignore();
        getline(cin, line);
        return line;
    }
};

int rec(long long x) {
    int answer = 0;
    for (int k = 31; k >= 0; k--) {
        if (x & (1LL << k)) {
            answer++;
        }
    }
    return answer;
}

int main() {
    FastReader sc;
    long long n = sc.nextInt();
    vector<int> a(33, 0);

    for (long long i = 0; i < n; i++) {
        a[rec(sc.nextLong())]++;
    }

    double answer = 0;

    for (int i = 0; i < a.size(); i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
        answer += summ;
    }

    cout << static_cast<long long>(answer) << endl;
    return 0;
}

// <END-OF-CODE>
