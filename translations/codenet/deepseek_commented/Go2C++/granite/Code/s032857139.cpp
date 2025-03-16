

#include <bits/stdc++.h>

using namespace std;

// I/O functions for reading input efficiently.
int ReadInt() {
    int i;
    scanf("%d", &i);
    return i;
}

vector<int> ReadIntVector(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = ReadInt();
    }
    return v;
}

// Utility functions for arithmetic operations.
int Max(int a, int b) {
    return a > b? a : b;
}

int Min(int a, int b) {
    return a < b? a : b;
}

int CeilInt(int a, int b) {
    return (a + b - 1) / b;
}

int FloorInt(int a, int b) {
    return a / b;
}

int PowInt(int a, int e) {
    if (a < 0 || e < 0) {
        throw runtime_error("[argument error]: PowInt does not accept negative integers");
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
    return a < 0? -a : a;
}

int Gcd(int a, int b) {
    if (a <= 0 || b <= 0) {
        throw runtime_error("[argument error]: Gcd only accepts two NATURAL numbers");
    }
    if (a < b) {
        a, b = b, a;
    }

    for (int div = a % b; div!= 0; div = a % b) {
        a, b = b, div;
    }

    return a;
}

int Lcm(int a, int b) {
    if (a <= 0 || b <= 0) {
        throw runtime_error("[argument error]: Gcd only accepts two NATURAL numbers");
    }

    int gcd = Gcd(a, b);
    return (a / gcd) * b;
}

// Utility functions for string manipulation and permutation.
string DeleteElement(const string& s, int i) {
    if (i < 0 || s.length() <= i) {
        throw runtime_error("[index error]");
    }
    string n = s.substr(0, i) + s.substr(i + 1);
    return n;
}

string Concat(const string& s, const string& t) {
    string n = s + t;
    return n;
}

char ToggleChar(char c) {
    if ('a' <= c && c <= 'z') {
        return 'A' + (c - 'a');
    } else if ('A' <= c && c <= 'Z') {
        return 'a' + (c - 'A');
    } else {
        return c;
    }
}

string ToggleString(const string& s) {
    string n = "";
    for (char c : s) {
        n += ToggleChar(c);
    }
    return n;
}

int Strtoi(const string& s) {
    int i;
    if (sscanf(s.c_str(), "%d", &i)!= 1) {
        throw runtime_error("[argument error]: Strtoi only accepts integer string");
    }
    return i;
}

// Functions for generating permutations.
vector<string> CalcFactorialPatterns(const string& s) {
    string copiedResidual = s;
    return factorialRecursion("", copiedResidual);
}

vector<string> factorialRecursion(string interim, string residual) {
    if (residual.empty()) {
        return {interim};
    }

    vector<string> res;
    for (int idx = 0; idx < residual.length(); idx++) {
        string copiedInterim = interim;
        copiedInterim += residual[idx];
        string copiedResidual = DeleteElement(residual, idx);
        res = Concat(res, factorialRecursion(copiedInterim, copiedResidual));
    }

    return res;
}

vector<string> CalcDuplicatePatterns(const string& s, int digit) {
    return duplicateRecursion("", s, digit);
}

vector<string> duplicateRecursion(string interim, const string& s, int digit) {
    if (interim.length() == digit) {
        return {interim};
    }

    vector<string> res;
    for (int i = 0; i < s.length(); i++) {
        string copiedInterim = interim;
        copiedInterim += s[i];
        res = Concat(res, duplicateRecursion(copiedInterim, s, digit));
    }

    return res;
}

// Binary search functions.
int GeneralLowerBound(const vector<int>& s, int key) {
    auto isOK = [&](int index, int key) {
        return s[index] >= key;
    };

    int ng = -1, ok = s.size();
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid, key)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    return ok;
}

int GeneralUpperBound(const vector<int>& s, int key) {
    auto isOK = [&](int index, int key) {
        return s[index] > key;
    };

    int ng = -1, ok = s.size();
    while (ok - ng > 1) {
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
void InitParents(vector<int>& parents, int maxNodeId) {
    for (int i = 0; i <= maxNodeId; i++) {
        parents[i] = i;
    }
}

void unite(int x, int y, vector<int>& parents) {
    int xp = root(x, parents), yp = root(y, parents);
    if (xp == yp) {
        return;
    }

    parents[xp] = yp;
}

bool same(int x, int y, const vector<int>& parents) {
    return root(x, parents) == root(y, parents);
}

int root(int x, const vector<int>& parents) {
    if (parents[x] == x) {
        return x;
    }

    parents[x] = root(parents[x], parents);
    return parents[x];
}

// Prime factorization and checking.
map<int, int> TrialDivision(int n) {
    if (n <= 1) {
        throw runtime_error("[argument error]: TrialDivision only accepts a NATURAL number");
    }

    map<int, int> p;
    for (int i = 2; i * i <= n; i++) {
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

    return a * modpow(a, e-1, m) % m;
}

int CalcModInv(int a, int m) {
    int b = m, u = 1, v = 0;
    for {
        if b == 0 {
            break;
        }
        u, v = 0;
    }

    return u;
}

// Min-heap implementation using the container/heap"

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}
func (h *IntHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[:n-1]
    return x.(int)
}

func main() {
    n, x := ReadInt(), ReadInt()
    A := ReadIntSlice(n)
    sort.Ints(A)

    ans := 0
    for i := 0; i < n; i++ {
        if x >= A[i] {
            ans++
            x -= A[i]
        }
    }
    if ans == n && x > 0 {
        ans--
        x -= A[i]
    }
    fmt.Println(ans)
}

// Main function to read input, sort the array, and calculate the answer.
var n, x int
var A []int

func initParents(parents []int, maxNodeId int) {
    for i := 0; i < maxNodeId; i++ {
        parents[i] = i
    }
}

func unite(x, y int, parents []int) {
    xp, yp := root(x, parents)
    if xp == yp {
        return
    }
    parents[xp] = yp
}

func same(x, y int, parents []int) bool {
    return root(x, parents) == root(y, parents)
}

func root(x int, parents []int) int {
    if parents[x] == x {
        return x
    }
    parents[x] = y
    return parents[x]
}

func TrialDivision(n int) map[int]int {
    if n <= 1 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n < 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number")
    }
    if n <= 0 {
        panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number