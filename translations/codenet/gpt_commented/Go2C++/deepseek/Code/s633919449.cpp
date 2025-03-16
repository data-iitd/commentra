#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <cstring>
#include <iomanip>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;
const int MOD = 1e9 + 7;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rrep1(i, n) for (int i = (n); i > 0; --i)
#define all(v) (v).begin(), (v).end()
#define debug(x) cout << #x << ": " << x << endl
#define print(x) cout << x << endl
#define print2(x, y) cout << x << " " << y << endl
#define print3(x, y, z) cout << x << " " << y << " " << z << endl
#define print4(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl

// Function to read an integer from input
int getInt() {
    int i;
    cin >> i;
    return i;
}

// Function to read an array of integers from input
vector<int> getIntArray(int n) {
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    return array;
}

// Function to read a string from input
string getString() {
    string s;
    cin >> s;
    return s;
}

// Function to read an array of strings from input
vector<string> getStringArray(int n) {
    vector<string> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    return array;
}

// Function to calculate the absolute value of an integer
int abs(int a) {
    return abs(a);
}

// Function to calculate p raised to the power of q
int pow(int p, int q) {
    return pow(p, q);
}

// Function to calculate n raised to the power of p modulo mod
int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return (t * t) % MOD;
    } else {
        return (n * powMod(n, p - 1)) % MOD;
    }
}

// Function to find the minimum value among a list of integers
int min(vector<int>& nums) {
    if (nums.empty()) {
        throw invalid_argument("vector is empty");
    }
    int res = nums[0];
    for (int num : nums) {
        res = min(res, num);
    }
    return res;
}

// Function to find the maximum value among a list of integers
int max(vector<int>& nums) {
    if (nums.empty()) {
        throw invalid_argument("vector is empty");
    }
    int res = nums[0];
    for (int num : nums) {
        res = max(res, num);
    }
    return res;
}

// Function to check if a string exists in an array of strings
bool strSearch(vector<string>& a, string b) {
    for (string s : a) {
        if (s == b) {
            return true;
        }
    }
    return false;
}

// Function to print an array of integers
void printIntArray(vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        if (i > 0) cout << " ";
        cout << array[i];
    }
    cout << endl;
}

// Function to calculate x modulo mod
int calcMod(int x) {
    return x % MOD;
}

// Function to reverse a string
string reverse(string s) {
    reverse(all(s));
    return s;
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    int sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to check if an integer exists in a slice
bool contains(vector<int>& s, int e) {
    return find(all(s), e) != s.end();
}

// Function to create a range of integers from min to max
vector<int> makeRange(int min, int max) {
    vector<int> a(max - min + 1);
    iota(all(a), min);
    return a;
}

// Function to generate the powerset of a given slice of integers
vector<vector<int>> powerset2(vector<int>& nums) {
    int length = pow(2, nums.size());
    vector<vector<int>> result(length);

    int index = 0;
    result[index] = {};
    index++;

    // Generate all subsets
    for (int n : nums) {
        int max = index;
        for (int i = 0; i < max; i++) {
            result[index] = result[i];
            result[index].push_back(n);
            index++;
        }
    }

    return result;
}

// Function to calculate the greatest common divisor (GCD) of two integers
int calcGcd(int x, int y) {
    if (y == 0) {
        return x;
    } else if (x >= y) {
        return calcGcd(y, x % y);
    } else {
        return calcGcd(x, y % x);
    }
}

// Function to get all divisors of a number
vector<int> getDivisor(int n) {
    set<int> divisor;
    divisor.insert(1);
    if (n != 1) {
        divisor.insert(n);
    }

    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            divisor.insert(i);
            divisor.insert(n / i);
        }
    }

    vector<int> divisorArray(all(divisor));
    return divisorArray;
}

// Custom heap type for integers
class intHeap {
public:
    vector<int> h;
    intHeap() {}

    void push(int x) {
        h.push_back(x);
        push_heap(all(h), greater<int>());
    }

    void pop() {
        pop_heap(all(h), greater<int>());
        h.pop_back();
    }

    int top() {
        return h.front();
    }

    bool empty() {
        return h.empty();
    }
};

// Function to calculate factorial modulo mod
int factMod(int n) {
    int value = 1;
    for (; n > 1; n--) {
        value = (value * n) % MOD;
    }
    return value;
}

// Function to calculate combinations modulo mod
int combinationMod(int n, int k) {
    int factN = factMod(n);
    int factK = factMod(k);
    int factNK = factMod(n - k);
    int factKR = powMod(factK, MOD - 2);
    int factNKR = powMod(factNK, MOD - 2);
    return (factN * ((factKR * factNKR) % MOD)) % MOD;
}

// Function to find prime factors of a number
vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

