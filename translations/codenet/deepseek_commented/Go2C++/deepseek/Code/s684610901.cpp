#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Custom Sorting Types
struct Pair {
    int index;
    int p1, p2;
};

using Pairs = vector<Pair>;

bool comparePairs(const Pair& a, const Pair& b) {
    return a.index < b.index;
}

using Int64Slice = vector<int64_t>;

bool compareInt64(int64_t a, int64_t b) {
    return a < b;
}

// Constants and Variables
const int64_t INF = 1e8;

// Main Function
int main() {
    int64_t A, B, C;
    cin >> A >> B >> C;
    if (C >= A && C <= B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

// Library
template <typename T>
bool nextPermutation(T first, T last) {
    if (first == last) return false;
    auto i = last;
    if (first == --i) return false;

    while (true) {
        auto ii = i;
        if (*--i < *ii) {
            auto j = last;
            while (!(*i < *--j));
            iter_swap(i, j);
            reverse(ii, last);
            return true;
        }
        if (i == first) {
            reverse(first, last);
            return false;
        }
    }
}

vector<vector<int64_t>> doubleAry(int64_t h, int64_t w, int64_t init) {
    vector<vector<int64_t>> res(h, vector<int64_t>(w, init));
    return res;
}

bool aryEq(const vector<int64_t>& a, const vector<int64_t>& b) {
    return a == b;
}

vector<int64_t> clone(const vector<int64_t>& n) {
    return n;
}

void write(const string& s) {
    cout << s;
}

void print() {
    cout << flush;
}

string readLine() {
    string line;
    getline(cin, line);
    return line;
}

int64_t readInt() {
    int64_t value;
    cin >> value;
    return value;
}

double readFloat() {
    double value;
    cin >> value;
    return value;
}

vector<char> readRunes() {
    string line;
    getline(cin, line);
    vector<char> runes;
    for (char c : line) {
        runes.push_back(c);
    }
    return runes;
}

string readString() {
    string line;
    getline(cin, line);
    return line;
}

vector<string> readStrings() {
    string line;
    getline(cin, line);
    vector<string> strings;
    for (char c : line) {
        strings.push_back(string(1, c));
    }
    return strings;
}

int64_t s2i(const string& s) {
    return stoll(s);
}

string i2s(int64_t i) {
    return to_string(i);
}

double s2f(const string& s) {
    return stod(s);
}

int64_t abs(int64_t i) {
    return abs(i);
}

int64_t max(const vector<int64_t>& a) {
    return *max_element(a.begin(), a.end());
}

int64_t min(const vector<int64_t>& a) {
    return *min_element(a.begin(), a.end());
}

int64_t sum(const vector<int64_t>& i) {
    int64_t sum = 0;
    for (int64_t val : i) {
        sum += val;
    }
    return sum;
}

vector<string> split(const string& s) {
    vector<string> result;
    stringstream ss(s);
    string item;
    while (getline(ss, item, ' ')) {
        result.push_back(item);
    }
    return result;
}

vector<int64_t> strAry2intAry(const vector<string>& strs) {
    vector<int64_t> ret;
    for (const string& str : strs) {
        ret.push_back(s2i(str));
    }
    return ret;
}

vector<string> intAry2strAry(const vector<int64_t>& nums) {
    vector<string> ret;
    for (int64_t num : nums) {
        ret.push_back(i2s(num));
    }
    return ret;
}

string ary2str(const vector<string>& strs) {
    string result;
    for (size_t i = 0; i < strs.size(); ++i) {
        if (i > 0) result += " ";
        result += strs[i];
    }
    return result;
}

vector<int64_t> reverse(const vector<int64_t>& res) {
    vector<int64_t> reversed = res;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

vector<string> reverseStr(const vector<string>& res) {
    vector<string> reversed = res;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

void ini(vector<int>& res, int init) {
    if (res.empty()) return;
    res[0] = init;
    for (size_t i = 0; i < res.size(); ++i) {
        copy(res.begin() + i, res.begin() + i + 1, res.begin() + i);
    }
}

