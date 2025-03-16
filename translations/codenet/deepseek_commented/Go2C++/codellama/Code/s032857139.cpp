
// Package main defines the entry point of the application.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <climits>
#include <string>

using namespace std;



// I/O functions for reading input efficiently.
template<class T>
void Read(T& a) {
    cin >> a;
}

template<class T>
void Read(vector<T>& a) {
    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
}

template<class T>
void Read(vector<vector<T>>& a) {
    for (size_t i = 0; i < a.size(); i++) {
        Read(a[i]);
    }
}



// Utility functions for dynamic programming.
template<class T>
bool ChMin(T& a, const T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ChMax(T& a, const T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
T GetNthBit(T num, int nth) {
    return num >> nth & 1;
}



// Arithmetic functions for mathematical operations.
template<class T>
T Max(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}

template<class T>
T Min(T a, T b) {
    if (a < b) {
        return a;
    }
    return b;
}

template<class T>
T CeilInt(T a, T b) {
    return (a + b - 1) / b;
}

template<class T>
T FloorInt(T a, T b) {
    return a / b;
}

template<class T>
T PowInt(T a, T b) {
    if (a < 0 || b < 0) {
        return -1;
    }
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return PowInt(a, b / 2) * PowInt(a, b / 2);
    }
    return a * PowInt(a, b - 1);
}

template<class T>
T AbsInt(T a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

template<class T>
T Gcd(T a, T b) {
    if (a < 0 || b < 0) {
        return -1;
    }
    if (a == 0 || b == 0) {
        return 1;
    }
    while (b != 0) {
        T tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

template<class T>
T Lcm(T a, T b) {
    if (a < 0 || b < 0) {
        return -1;
    }
    if (a == 0 || b == 0) {
        return 0;
    }
    return a / Gcd(a, b) * b;
}



// Utility functions for string manipulation and permutation.
template<class T>
vector<T> DeleteElement(vector<T> a, int i) {
    if (i < 0 || a.size() <= i) {
        return a;
    }
    vector<T> b;
    for (int j = 0; j < a.size(); j++) {
        if (j == i) {
            continue;
        }
        b.push_back(a[j]);
    }
    return b;
}

template<class T>
vector<T> Concat(vector<T> a, vector<T> b) {
    vector<T> c;
    for (int i = 0; i < a.size(); i++) {
        c.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        c.push_back(b[i]);
    }
    return c;
}

template<class T>
T UpperRune(T r) {
    string str = to_string(r);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    return str[0];
}

template<class T>
T LowerRune(T r) {
    string str = to_string(r);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
    return str[0];
}

template<class T>
T ToggleRune(T r) {
    string str = to_string(r);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
    return str[0];
}

template<class T>
string ToggleString(string s) {
    string t = "";
    for (int i = 0; i < s.size(); i++) {
        t += ToggleRune(s[i]);
    }
    return t;
}

template<class T>
T Strtoi(string s) {
    T n = 0;
    for (int i = 0; i < s.size(); i++) {
        n = n * 10 + s[i] - '0';
    }
    return n;
}



// Functions for generating permutations.
template<class T>
vector<vector<T>> CalcFactorialPatterns(vector<T> elements) {
    vector<T> copiedResidual = elements;
    return factorialRecursion(vector<T>(), copiedResidual);
}

template<class T>
vector<vector<T>> factorialRecursion(vector<T> interim, vector<T> residual) {
    if (residual.size() == 0) {
        return vector<vector<T>>{interim};
    }

    vector<vector<T>> res;
    for (int i = 0; i < residual.size(); i++) {
        vector<T> copiedInterim = interim;
        copiedInterim.push_back(residual[i]);
        vector<T> copiedResidual = DeleteElement(residual, i);
        res.insert(res.end(), factorialRecursion(copiedInterim, copiedResidual).begin(), factorialRecursion(copiedInterim, copiedResidual).end());
    }

    return res;
}

template<class T>
vector<vector<T>> CalcDuplicatePatterns(vector<T> elements, int digit) {
    return duplicateRecursion(vector<T>(), elements, digit);
}

template<class T>
vector<vector<T>> duplicateRecursion(vector<T> interim, vector<T> elements, int digit) {
    if (interim.size() == digit) {
        return vector<vector<T>>{interim};
    }

    vector<vector<T>> res;
    for (int i = 0; i < elements.size(); i++) {
        vector<T> copiedInterim = interim;
        copiedInterim.push_back(elements[i]);
        res.insert(res.end(), duplicateRecursion(copiedInterim, elements, digit).begin(), duplicateRecursion(copiedInterim, elements, digit).end());
    }

    return res;
}



// Binary search functions.
template<class T>
int GeneralLowerBound(vector<T> s, T key) {
    auto isOK = [&](int index, T key) {
        if (s[index] >= key) {
            return true;
        }
        return false;
    };

    int ng = -1, ok = s.size();
    while (abs(ok - ng) > 1) {
        int mid = (ng + ok) / 2;
        if (isOK(mid, key)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    return ok;
}

template<class T>
int GeneralUpperBound(vector<T> s, T key) {
    auto isOK = [&](int index, T key) {
        if (s[index] > key) {
            return true;
        }
        return false;
    };

    int ng = -1, ok = s.size();
    while (abs(ok - ng) > 1) {
        int mid = (ng + ok) / 2;
        if (isOK(mid, key)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    return ok;
}



// Union-Find data structure.
template<class T>
void InitParents(vector<T>& parents, int maxNodeId) {
    for (int i = 0; i <= maxNodeId; i++) {
        parents[i] = i;
    }
}

template<class T>
void unite(T x, T y, vector<T>& parents) {
    T xp = root(x, parents), yp = root(y, parents);
    if (xp == yp) {
        return;
    }

    parents[xp] = yp;
}

template<class T>
bool same(T x, T y, vector<T>& parents) {
    return root(x, parents) == root(y, parents);
}

template<class T>
T root(T x, vector<T>& parents) {
    if (parents[x] == x) {
        return x;
    }

    parents[x] = root(parents[x], parents);
    return parents[x];
}



// Prime factorization and checking.
template<class T>
map<T, int> TrialDivision(T n) {
    if (n <= 1) {
        return map<T, int>();
    }

    map<T, int> p;
    for (T i = 2; i * i <= n; i++) {
        int exp = 0;
        while (n % i == 0) {
            exp++;
            n /= i;
        }

        if (exp == 0) {
            continue;
        }
        p[i] = exp;
    }
    if (n > 1) {
        p[n] = 1;
    }

    return p;
}

template<class T>
bool IsPrime(T n) {
    if (n == 1) {
        return false;
    }

    for (T i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}



// Min-heap implementation using the heap package.
template<class T>
struct IntHeap {
    vector<T> heap;
    int size;

    IntHeap() {
        heap.push_back(0);
        size = 0;
    }

    void push(T x) {
        heap.push_back(x);
        size++;
        int i = size;
        while (i > 1 && heap[i] < heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }

    T pop() {
        T x = heap[1];
        heap[1] = heap[size];
        size--;
        int i = 1;
        while (i * 2 <= size) {
            int j = i * 2;
            if (j + 1 <= size && heap[j + 1] < heap[j]) {
                j++;
            }
            if (heap[j] < heap[i]) {
                swap(heap[i], heap[j]);
                i = j;
            } else {
                break;
            }
        }
        return x;
    }
};



// Main function to read input, sort the array, and calculate the answer.
int n, x;
vector<int> A;

int main() {
    Read(n, x);
    A.resize(n);
    Read(A);

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
}



// Translate the above C++ code to C and end with comment "