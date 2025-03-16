#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <utility>
#include <functional>
#include <bitset>
#include <tuple>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <array>
#include <random>
#include <chrono>

using namespace std;

/*********** I/O ***********/

string readString() {
    string str;
    getline(cin, str);
    return str;
}

int readInt() {
    return stoi(readString());
}

vector<int> readInts(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = readInt();
    }
    return vec;
}

vector<string> readStrings(int n) {
    vector<string> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = readString();
    }
    return vec;
}

/*********** DP sub-functions ***********/

template<typename T>
void chmin(T &a, const T &b) {
    if (a > b) a = b;
}

template<typename T>
void chmax(T &a, const T &b) {
    if (a < b) a = b;
}

int getNthBit(int num, int nth) {
    return (num >> nth) & 1;
}

/*********** Arithmetic ***********/

int max(const vector<int> &vec) {
    return *max_element(vec.begin(), vec.end());
}

int min(const vector<int> &vec) {
    return *min_element(vec.begin(), vec.end());
}

int ceilInt(int a, int b) {
    return (a + b - 1) / b;
}

int floorInt(int a, int b) {
    return a / b;
}

int powInt(int a, int e) {
    int result = 1;
    for (int i = 0; i < e; ++i) {
        result *= a;
    }
    return result;
}

int absInt(int a) {
    return abs(a);
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

/*********** Utilities ***********/

vector<int> deleteElement(const vector<int> &s, int i) {
    vector<int> result(s.begin(), s.end());
    result.erase(result.begin() + i);
    return result;
}

vector<char> concat(const vector<char> &s, const vector<char> &t) {
    vector<char> result(s.begin(), s.end());
    result.insert(result.end(), t.begin(), t.end());
    return result;
}

char upperRune(char r) {
    return toupper(r);
}

char lowerRune(char r) {
    return tolower(r);
}

char toggleRune(char r) {
    return isupper(r) ? tolower(r) : toupper(r);
}

string toggleString(const string &s) {
    string result;
    for (char c : s) {
        result += toggleRune(c);
    }
    return result;
}

int strtoi(const string &s) {
    try {
        return stoi(s);
    } catch (invalid_argument &e) {
        throw invalid_argument("Strtoi only accepts integer string");
    }
}

/*********** Permutation ***********/

vector<vector<char>> calcFactorialPatterns(const vector<char> &elements) {
    vector<vector<char>> result;
    vector<char> indices(elements.size());
    iota(indices.begin(), indices.end(), 0);
    do {
        vector<char> perm;
        for (char i : indices) {
            perm.push_back(elements[i]);
        }
        result.push_back(perm);
    } while (next_permutation(indices.begin(), indices.end()));
    return result;
}

vector<vector<char>> calcDuplicatePatterns(const vector<char> &elements, int digit) {
    vector<vector<char>> result;
    vector<char> current(digit, 0);
    function<void(int)> generate = [&](int pos) {
        if (pos == digit) {
            vector<char> pattern;
            for (int i = 0; i < digit; ++i) {
                pattern.push_back(elements[current[i]]);
            }
            result.push_back(pattern);
            return;
        }
        for (int i = 0; i < elements.size(); ++i) {
            current[pos] = i;
            generate(pos + 1);
        }
    };
    generate(0);
    return result;
}

/*********** Binary Search ***********/

int generalLowerBound(const vector<int> &s, int key) {
    int ok = s.size(), ng = -1;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (s[mid] >= key) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int generalUpperBound(const vector<int> &s, int key) {
    int ok = s.size(), ng = -1;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (s[mid] > key) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

/*********** Union Find ***********/

vector<int> parents;

void initParents(int maxNodeId) {
    parents.resize(maxNodeId + 1);
    iota(parents.begin(), parents.end(), 0);
}

void unite(int x, int y) {
    int xp = root(x), yp = root(y);
    if (xp == yp) return;
    parents[xp] = yp;
}

bool same(int x, int y) {
    return root(x) == root(y);
}

int root(int x) {
    if (parents[x] == x) return x;
    return parents[x] = root(parents[x]);
}

/*********** Factorization, Prime Number ***********/

map<int, int> trialDivision(int n) {
    map<int, int> factors;
    for (int i = 2; i * i <= n; ++i) {
        int exp = 0;
        while (n % i == 0) {
            exp++;
            n /= i;
        }
        if (exp > 0) {
            factors[i] = exp;
        }
    }
    if (n > 1) {
        factors[n] = 1;
    }
    return factors;
}

bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

/*********** Inverse Element ***********/

int calcNegativeMod(int val, int m) {
    int res = val % m;
    if (res < 0) res += m;
    return res;
}

int modpow(int a, int e, int m) {
    if (e == 0) return 1;
    if (e % 2 == 0) {
        int halfE = e / 2;
        int half = modpow(a, halfE, m);
        return half * half % m;
    }
    return a * modpow(a, e - 1, m) % m;
}

int calcModInv(int a, int m) {
    return modpow(a, m - 2, m);
}

/********** heap package (Integer Priority Queue) **********/

class IntHeap {
public:
    IntHeap() {}
    void push(int x) {
        h.push_back(x);
        push_heap(h.begin(), h.end());
    }
    void pop() {
        pop_heap(h.begin(), h.end());
        h.pop_back();
    }
    int top() {
        return h.front();
    }
    bool empty() {
        return h.empty();
    }
private:
    vector<int> h;
};

/********** sort package (snippets) **********/
//sort(s.begin(), s.end());
//sort(s.rbegin(), s.rend());

/********** copy function (snippets) **********/
//b = a;

/********** I/O usage **********/

//string str = readString();
//int i = readInt();
//vector<int> X = readInts(n);
//string S = readString();

/********** String Split **********/

//vector<string> strs = split(string(runeSlice), '+');

/*******************************************************************/

const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;

int n, x;
vector<int> A;

int main() {
    cin >> n >> x;
    A = readInts(n);

    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (x >= A[i]) {
            ++ans;
            x -= A[i];
        } else {
            break;
        }
    }
    if (ans == n && x > 0) {
        --ans;
    }
    cout << ans << endl;

    return 0;
}
