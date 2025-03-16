#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>

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
        string x;
        getline(cin, x);
        return x;
    }
};

int rec(long long x) {
    int answer = 0;
    for (int k = 31; k >= 0; k--) {
        if ((x & (1LL << k)) != 0) {
            answer++;
        }
    }
    return answer;
}

int main() {
    FastReader sc;
    int n = sc.nextInt();
    vector<int> a(33, 0);

    for (int i = 0; i < n; i++) {
        int num = sc.nextInt();
        int index = rec(num);
        a[index]++;
    }

    double answer = 0;
    for (int i = 0; i < a.size(); i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
        answer += summ;
    }
    cout << (long long)answer << endl;
    return 0;
}

