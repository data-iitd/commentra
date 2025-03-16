#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

class Segment {
public:
    int n, h, i, chunk;
    std::vector<int> unit;
    std::vector<std::vector<int>> bucket;

    void init(int n) {
        this->n = n;
        unit.push_back(1);
        bucket.push_back(std::vector<int>(n));

        int chunk = 8;
        while (n > 1) {
            n = (n - 1) / chunk + 1;
            bucket.push_back(std::vector<int>(n));
            unit.push_back(unit.back() * chunk);
        }
        h = unit.size();
        this->chunk = chunk;
    }

    void maximize(int index, int value) {
        bucket[0][index] = value;
        for (i = 0; i < h - 1; i++) {
            int s = index - index % chunk;
            int t = s + chunk;
            if (t > bucket[i].size()) {
                t = bucket[i].size();
            }
            int parent = index / chunk;
            int max_val = 0;
            for (int j = s; j < t; j++) {
                max_val = std::max(max_val, bucket[i][j]);
            }
            bucket[i + 1][parent] = max_val;
            index /= chunk;
        }
    }

    int top() {
        int index = 0;
        for (i = h - 2; i >= 0; i--) {
            int s = index * chunk;
            int t = s + chunk;
            if (t > bucket[i].size()) {
                t = bucket[i].size();
            }
            for (int j = s; j < t; j++) {
                if (bucket[i][j] == bucket[i + 1][index]) {
                    index = j;
                    break;
                }
            }
        }
        return index;
    }
};

int main(int argc, char* argv[]) {
    std::istream* input = &std::cin;
    std::ifstream file;
    if (argc > 1) {
        file.open(argv[1]);
        input = &file;
    }

    int n, m;
    *input >> n >> m;
    Segment seg;
    seg.init(n);
    for (int i = 0; i < n; i++) {
        int value;
        *input >> value;
        seg.maximize(i, value);
    }
    for (int i = 0; i < m; i++) {
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg.bucket[0][i];
    }

    std::cout << ans << std::endl;

    if (file.is_open()) {
        file.close();
    }
    return 0;
}

// <END-OF-CODE>
