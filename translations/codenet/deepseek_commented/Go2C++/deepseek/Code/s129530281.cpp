#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Segment {
public:
    void init(int n);
    void maximize(int index, int value);
    int top();

private:
    int n, h, i, chunk;
    std::vector<int> unit;
    std::vector<std::vector<int>> bucket;
};

void Segment::init(int n) {
    this->n = n;
    unit.push_back(1);
    bucket.push_back(std::vector<int>(n));

    chunk = 8;
    while (n > 1) {
        n = (n - 1) / chunk + 1;
        bucket.push_back(std::vector<int>(n));
        unit.push_back(unit.back() * chunk);
    }
    h = unit.size();
}

void Segment::maximize(int index, int value) {
    bucket[0][index] = value;
    for (i = 0; i < h - 1; i++) {
        int s = index - index % chunk;
        int t = s + chunk;
        if (t > bucket[i].size()) {
            t = bucket[i].size();
        }
        int parent = index / chunk;
        int max = 0;
        for (int j = s; j < t; j++) {
            if (max < bucket[i][j]) {
                max = bucket[i][j];
            }
        }
        bucket[i + 1][parent] = max;
        index /= chunk;
    }
}

int Segment::top() {
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

int main() {
    std::istream& fp = std::cin;
    if (argc > 1) {
        std::ifstream file(argv[1]);
        fp = file;
    }
    std::istringstream scanner(fp);
    std::ostream& writer = std::cout;

    int n, m;
    scanner >> n >> m;

    Segment seg;
    seg.init(n);

    for (int i = 0; i < n; i++) {
        int value;
        scanner >> value;
        seg.maximize(i, value);
    }

    for (int i = 0; i < m; i++) {
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
    }

    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg.bucket[0][i];
    }

    writer << ans << std::endl;
    return 0;
}
