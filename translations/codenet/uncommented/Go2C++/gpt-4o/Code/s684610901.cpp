#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>

using namespace std;

const int64_t INF = 1e8;

bool isInRange(int64_t A, int64_t B, int64_t C) {
    return C >= A && C <= B;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t A, B, C;
    cin >> A >> B >> C;

    if (isInRange(A, B, C)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

/*==========================================
 *             Library
 *==========================================*/
template <typename T>
bool nextPermutation(vector<T>& x) {
    int n = x.size() - 1;
    if (n < 1) return false;
    int j = n - 1;
    while (j >= 0 && x[j] >= x[j + 1]) {
        j--;
    }
    if (j < 0) return false;
    int l = n;
    while (!x[j] < x[l]) {
        l--;
    }
    swap(x[j], x[l]);
    reverse(x.begin() + j + 1, x.end());
    return true;
}

vector<vector<int64_t>> doubleAry(int64_t h, int64_t w, int64_t init) {
    return vector<vector<int64_t>>(h, vector<int64_t>(w, init));
}

bool aryEq(const vector<int64_t>& a, const vector<int64_t>& b) {
    return a == b;
}

vector<int64_t> clone(const vector<int64_t>& n) {
    return vector<int64_t>(n);
}

void write(const string& s) {
    cout << s;
}

void print() {
    cout.flush();
}

string readLine() {
    string s;
    getline(cin, s);
    return s;
}

int64_t readInt() {
    int64_t read;
    cin >> read;
    return read;
}

double readFloat() {
    double read;
    cin >> read;
    return read;
}

vector<int64_t> strAry2intAry(const vector<string>& strs) {
    vector<int64_t> ret;
    for (const auto& str : strs) {
        ret.push_back(stoi(str));
    }
    return ret;
}

vector<string> intAry2strAry(const vector<int64_t>& nums) {
    vector<string> ret;
    for (const auto& num : nums) {
        ret.push_back(to_string(num));
    }
    return ret;
}

string ary2str(const vector<string>& strs) {
    stringstream ss;
    for (size_t i = 0; i < strs.size(); ++i) {
        ss << strs[i];
        if (i < strs.size() - 1) ss << " ";
    }
    return ss.str();
}

vector<int64_t> reverse(const vector<int64_t>& res) {
    vector<int64_t> reversed = res;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

vector<string> reverseStr(const vector<string>& res) {
    vector<string> reversed = res;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

int64_t abs(int64_t i) {
    return std::abs(i);
}

int64_t max(int64_t a, int64_t b) {
    return std::max(a, b);
}

int64_t min(int64_t a, int64_t b) {
    return std::min(a, b);
}

int64_t sum(const vector<int64_t>& i) {
    return std::accumulate(i.begin(), i.end(), int64_t(0));
}

vector<string> split(const string& s) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, ' ')) {
        tokens.push_back(item);
    }
    return tokens;
}

