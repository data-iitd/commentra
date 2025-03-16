#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <cmath>

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

int main() {
    FastReader sc;
    int x = sc.nextInt();
    int count = 0;
    int tmp = x;
    x = 0;
    while (x != 360) {
        x = x + tmp;
        if (x > 360) {
            x = x - 360;
        }
        count++;
    }
    cout << count << endl;
    return 0;
}

