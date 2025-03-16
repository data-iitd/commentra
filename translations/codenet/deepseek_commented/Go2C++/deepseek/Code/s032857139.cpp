#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <iomanip>

using namespace std;

// I/O functions for reading input efficiently.
string readString() {
    string str;
    cin >> str;
    return str;
}

int readInt() {
    return stoi(readString());
}

vector<int> readIntSlice(int n) {
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = readInt();
    }
    return b;
}

// Utility functions for dynamic programming.
template <typename T>
bool ChMin(T &updatedValue, const T &target) {
    if (updatedValue > target) {
        updatedValue = target;
        return true;
    }
    return false;
}

template <typename T>
bool ChMax(T &updatedValue, const T &target) {
    if (updatedValue < target) {
        updatedValue = target;
        return true;
    }
    return false;
}

int GetNthBit(int num, int nth) {
    return (num >> nth) & 1;
}

// Arithmetic functions for mathematical operations.
int Max(const vector<int> &integers) {
    int m = integers[0];
    for (int i = 1; i < integers.size(); i++) {
        if (m < integers[i]) {
            m = integers[i];
        }
    }
    return m;
}

int Min(const vector<int> &integers) {
    int m = integers[0];
    for (int i = 1; i < integers.size(); i++) {
        if (m > integers[i]) {
            m = integers[i];
        }
    }
    return m;
}

int CeilInt(int a, int b) {
    int res = a / b;
    if (a % b > 0) {
        res++;
    }
    return res;
}

int FloorInt(int a, int b) {
    int res = a / b;
    return res;
}

int PowInt(int a, int e) {
    if (a < 0 || e < 0) {
        throw invalid_argument("PowInt does not accept negative integers");
    }

    if (e == 0) {
        return 1;
    }

    if (e % 2 == 0) {
        int halfE = e / 2;
        int half = PowInt(a, halfE);
        return half * half;
    }

    return a * PowInt(a, e - 1);
}

int AbsInt(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

int Gcd(int a, int b) {
    if (a <= 0 || b <= 0) {
        throw invalid_argument("Gcd only accepts two NATURAL numbers");
    }
    if (a < b) {
        swap(a, b);
    }

    while (b > 0) {
        int div = a % b;
        a = b;
        b = div;
    }

    return a;
}

int Lcm(int a, int b) {
    if (a <= 0 || b <= 0) {
        throw invalid_argument("Gcd only accepts two NATURAL numbers");
    }

    int gcd = Gcd(a, b);
    return (a / gcd) * b;
}

// Utility functions for string manipulation and permutation.
vector<int> DeleteElement(const vector<int> &s, int i) {
    if (i < 0 || i >= s.size()) {
        throw out_of_range("Index error");
    }
    vector<int> n;
    n.insert(n.end(), s.begin(), s.begin() + i);
    n.insert(n.end(), s.begin() + i + 1, s.end());
    return n;
}

string Concat(const string &s, const string &t) {
    return s + t;
}

char UpperRune(char r) {
    string str = toupper(string(1, r));
    return str[0];
}

char LowerRune(char r) {
    string str = tolower(string(1, r));
    return str[0];
}

char ToggleRune(char r) {
    string str;
    if ('a' <= r && r <= 'z') {
        str = toupper(string(1, r));
    } else if ('A' <= r && r <= 'Z') {
        str = tolower(string(1, r));
    } else {
        str = string(1, r);
    }
    return str[0];
}

string ToggleString(const string &s) {
    string result;
    for (char r : s) {
        result += ToggleRune(r);
    }
    return result;
}

int Strtoi(const string &s) {
    try {
        return stoi(s);
    } catch (invalid_argument &e) {
        throw invalid_argument("Strtoi only accepts integer string");
    }
}

// Functions for generating permutations.
vector<vector<char>> CalcFactorialPatterns(const vector<char> &elements) {
    vector<char> copiedResidual = elements;
    return factorialRecursion({}, copiedResidual);
}

vector<vector<char>> factorialRecursion(vector<char> interim, vector<char> residual) {
    if (residual.empty()) {
        return {interim};
    }

    vector<vector<char>> res;
    for (int i = 0; i < residual.size(); i++) {
        vector<char> copiedInterim = interim;
        copiedInterim.push_back(residual[i]);
        vector<char> copiedResidual = genDeletedSlice(i, residual);
        auto subRes = factorialRecursion(copiedInterim, copiedResidual);
        res.insert(res.end(), subRes.begin(), subRes.end());
    }

    return res;
}

vector<char> genDeletedSlice(int delId, const vector<char> &S) {
    vector<char> res;
    res.insert(res.end(), S.begin(), S.begin() + delId);
    res.insert(res.end(), S.begin() + delId + 1, S.end());
    return res;
}

vector<vector<char>> CalcDuplicatePatterns(const vector<char> &elements, int digit) {
    return duplicateRecursion({}, elements, digit);
}

vector<vector<char>> duplicateRecursion(vector<char> interim, const vector<char> &elements, int digit) {
    if (interim.size() == digit) {
        return {interim};
    }

    vector<vector<char>> res;
    for (int i = 0; i < elements.size(); i++) {
        vector<char> copiedInterim = interim;
        copiedInterim.push_back(elements[i]);
        auto subRes = duplicateRecursion(copiedInterim, elements, digit);
        res.insert(res.end(), subRes.begin(), subRes.end());
    }

    return res;
}

// Binary search functions.
int GeneralLowerBound(const vector<int> &s, int key) {
    auto isOK = [&](int index, int key) {
        return s[index] >= key;
    };

    int ng = -1, ok = s.size();
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid, key)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    return ok;
}

int GeneralUpperBound(const vector<int> &s, int key) {
    auto isOK = [&](int index, int key) {
        return s[index] > key;
    };

    int ng = -1, ok = s.size();
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid, key)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    return ok;
}

// Union-Find data structure.
vector<int> parents;

void InitParents(int maxNodeId) {
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
    if (parents[x] == x) {
        return x;
    }

    return parents[x] = root(parents[x]);
}

// Prime factorization and checking.
map<int, int> TrialDivision(int n) {
    if (n <= 1) {
        throw invalid_argument("TrialDivision only accepts a NATURAL number");
    }

    map<int, int> p;
    for (int i = 2; i * i <= n; i++) {
        int exp = 0;
        while (n % i == 0) {
            exp++;
            n /= i;
        }

        if (exp > 0) {
            p[i] = exp;
        }
    }
    if (n > 1) {
        p[n] = 1;
    }

    return p;
}

bool IsPrime(int n) {
    if (n == 1) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Functions for modular arithmetic.
int CalcNegativeMod(int val, int m) {
    int res = val % m;
    if (res < 0) {
        res += m;
    }
    return res;
}

int modpow(int a, int e, int m) {
    if (e == 0) {
        return 1;
    }

    if (e % 2 == 0) {
        int halfE = e / 2;
        int half = modpow(a, halfE, m);
        return half * half % m;
    }

    return a * modpow(a, e - 1, m) % m;
}

int CalcModInv(int a, int m) {
    return modpow(a, m - 2, m);
}

// Min-heap implementation using the priority_queue.
struct IntComp {
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
};

using MinHeap = priority_queue<int, vector<int>, IntComp>;
using MaxHeap = priority_queue<int, vector<int>, less<int>>;

// Main function to read input, sort the array, and calculate the answer.
int n, x;
vector<int> A;

int main() {
    cin >> n >> x;
    A = readIntSlice(n);

    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x >= A[i]) {
            ans++;
            x -= A[i];
        } else {
            break;
        }
    }
    if (ans == n && x > 0) {
        ans--;
    }
    cout << ans << endl;

    return 0;
}

