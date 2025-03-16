#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class FastReader {
    public:
        FastReader() {}

        int nextInt() {
            int x;
            cin >> x;
            return x;
        }
};

int main() {
    FastReader in;
    int n = in.nextInt(), m = in.nextInt();
    set<int> bannedRows, bannedCols;

    for (int i = 0; i < m; i++) {
        int r = in.nextInt();
        if (r > 1 && r < n) bannedRows.insert(r);
        int c = in.nextInt();
        if (c > 1 && c < n) bannedCols.insert(c);
    }

    int answer = (n - 2) * 2;
    answer -= bannedRows.size();
    answer -= bannedCols.size();

    if (n % 2 != 0) {
        int mid = (n + 1) / 2;
        if (bannedRows.find(mid) == bannedRows.end() && bannedCols.find(mid) == bannedCols.end()) {
            answer--;
        }
    }

    cout << answer << endl;
    return 0;
}

// <END-OF-CODE>
