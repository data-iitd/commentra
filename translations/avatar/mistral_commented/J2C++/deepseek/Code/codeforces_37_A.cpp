#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

class FastScanner {
public:
    FastScanner() {
        cin.sync_with_stdio(false);
        cin.tie(nullptr);
    }

    int nextInt() {
        int value;
        cin >> value;
        return value;
    }

    long long nextLong() {
        long long value;
        cin >> value;
        return value;
    }

    double nextDouble() {
        double value;
        cin >> value;
        return value;
    }

    string nextLine() {
        string line;
        getline(cin, line);
        return line;
    }
};

int main() {
    FastScanner input;
    int n = input.nextInt();

    unordered_map<int, int> map;

    for (int i = 0; i < n; i++) {
        int val = input.nextInt();
        map[val]++;
    }

    int max = INT_MIN;
    for (const auto& entry : map) {
        max = std::max(max, entry.second);
    }

    cout << max << " " << map.size() << "\n";

    return 0;
}

