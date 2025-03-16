#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Segment {
public:
    int n, h, i, chunk;
    std::vector<int> unit;
    std::vector<std::vector<int>> bucket;

    void init(int n) {
        this->n = n;
        this->unit.push_back(1);
        this->bucket.push_back(std::vector<int>(n));

        this->chunk = 8;
        for (int i = 0; n > 1; ++i) {
            n = (n - 1) / this->chunk + 1;
            this->bucket.push_back(std::vector<int>(n));
            this->unit.push_back(this->unit[i] * this->chunk);
        }
        this->h = this->unit.size();
    }

    void maximize(int index, int value) {
        this->bucket[0][index] = value;
        for (this->i = 0; this->i < this->h - 1; ++this->i) {
            int s = index - index % this->chunk;
            int t = s + this->chunk;
            if (t > this->bucket[this->i].size()) {
                t = this->bucket[this->i].size();
            }
            int parent = index / this->chunk;
            int max = 0;
            for (int i = s; i < t; ++i) {
                if (max < this->bucket[this->i][i]) {
                    max = this->bucket[this->i][i];
                }
            }
            this->bucket[this->i + 1][parent] = max;
            index /= this->chunk;
        }
    }

    int top() {
        int index = 0;
        for (this->i = this->h - 2; this->i >= 0; --this->i) {
            int s = index * this->chunk;
            int t = s + this->chunk;
            if (t > this->bucket[this->i].size()) {
                t = this->bucket[this->i].size();
            }
            for (int i = s; i < t; ++i) {
                if (this->bucket[this->i][i] == this->bucket[this->i + 1][index]) {
                    index = i;
                    break;
                }
            }
        }
        return index;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    Segment seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        seg.maximize(i, value);
    }
    for (int i = 0; i < m; ++i) {
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
    }

    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += seg.bucket[0][i];
    }

    std::cout << ans << '\n';
    return 0;
}
