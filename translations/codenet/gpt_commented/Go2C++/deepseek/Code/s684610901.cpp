#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <limits>
#include <cstring>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <bitset>

using namespace std;

// Define a structure for sorting pairs
struct pair {
    int64_t index;
    int64_t p1, p2;
};

using pairs = vector<pair>;

// Implement sort.Interface for pairs
struct PairComparator {
    bool operator()(const pair& a, const pair& b) const {
        return a.index < b.index;
    }
};

// Define a structure for sorting int64 slices
struct Int64Slice {
    vector<int64_t> data;
    int64_t operator[](size_t index) const { return data[index]; }
    size_t size() const { return data.size(); }
};

// Implement sort.Interface for Int64Slice
struct Int64SliceComparator {
    bool operator()(const Int64Slice& a, const Int64Slice& b) const {
        for (size_t i = 0; i < a.size() && i < b.size(); ++i) {
            if (a[i] < b[i]) return true;
            if (a[i] > b[i]) return false;
        }
        return a.size() < b.size();
    }
};

// Utility functions for sorting int64 slices
void sortInt64s(vector<int64_t>& a) {
    sort(a.begin(), a.end());
}

bool isInt64sSorted(const vector<int64_t>& a) {
    return is_sorted(a.begin(), a.end());
}

// Constants for buffer sizes and infinity value
const int64_t initialBufSize = 1e4;
const int64_t maxBufSize = 1e8;
const int64_t INF = 1e8;

// Global variables for input/output handling and direction vectors
vector<int64_t> di = {-1, 0, 1, 0}; // Direction vectors for row movement
vector<int64_t> dj = {0, -1, 0, 1}; // Direction vectors for column movement

int64_t readInt() {
    int64_t value;
    cin >> value;
    return value;
}

float readFloat() {
    float value;
    cin >> value;
    return value;
}

string readLine() {
    string line;
    getline(cin, line);
    return line;
}

vector<string> readStrings() {
    vector<string> result;
    string line;
    getline(cin, line);
    stringstream ss(line);
    string word;
    while (ss >> word) {
        result.push_back(word);
    }
    return result;
}

int64_t s2i(const string& s) {
    return stoll(s);
}

string i2s(int64_t i) {
    return to_string(i);
}

float s2f(const string& s) {
    return stof(s);
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

int64_t sum(const vector<int64_t>& a) {
    return accumulate(a.begin(), a.end(), 0LL);
}

vector<string> split(const string& s) {
    vector<string> result;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        result.push_back(word);
    }
    return result;
}

vector<int64_t> strAry2intAry(const vector<string>& strs) {
    vector<int64_t> ret;
    for (const auto& str : strs) {
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
        if (i != 0) result += " ";
        result += strs[i];
    }
    return result;
}

vector<int64_t> reverse(const vector<int64_t>& res) {
    vector<int64_t> reversed(res.rbegin(), res.rend());
    return reversed;
}

vector<string> reverseStr(const vector<string>& res) {
    vector<string> reversed(res.rbegin(), res.rend());
    return reversed;
}

void ini(vector<int>& res, int init) {
    if (res.empty()) return;
    res[0] = init;
    for (size_t i = 0; i < res.size(); ++i) {
        copy(res.begin() + i, res.begin() + i + 1, res.begin() + i);
    }
}

int main() {
    // Set up the scanner buffer and read three integers A, B, C
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t A = readInt();
    int64_t B = readInt();
    int64_t C = readInt();

    // Check if C is within the range [A, B] and print the result
    if (C >= A && C <= B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

