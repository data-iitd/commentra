#include <iostream>

using namespace std;

int solution(int n, int m) {
        n = n - 2;
        m = m - 2;
        if (n < 0) {
                n = 1;
        }
        if (m < 0) {
                m = 1;
        }
        return n * m;
}

int main() {
        int n, m;
        cin >> n >> m;
        cout << solution(n, m) << endl;
        return 0;
}

