

#include <bits/stdc++.h>

using namespace std;

const int initialBufSize = 10000;
const int maxBufSize = 10000000;
const int mod = 1e9 + 7;

int getInt() {
    int n;
    scanf("%d", &n);
    return n;
}

vector<int> getIntArray(int n) {
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        array[i] = getInt();
    }
    return array;
}

string getString() {
    char buf[maxBufSize];
    scanf("%s", buf);
    return string(buf);
}

vector<string> getStringArray(int n) {
    vector<string> array(n);
    for (int i = 0; i < n; i++) {
        array[i] = getString();
    }
    return array;
}

int abs(int a) {
    return abs(a);
}

int pow(int p, int q) {
    return pow(p, q);
}

int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return calcMod(t * t);
    } else {
        return calcMod(n * powMod(n, p - 1));
    }
}

int min(int a, int b) {
    return min(a, b);
}

int max(int a, int b) {
    return max(a, b);
}

bool strSearch(vector<string> a, string b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b) {
            return true;
        }
    }
    return false;
}

void printIntArray(vector<int> array) {
    stringstream ss;
    for (int i = 0; i < array.size(); i++) {
        ss << array[i];
        if (i!= array.size() - 1) {
            ss << " ";
        }
    }
    cout << ss.str() << endl;
}

int calcMod(int x) {
    return x % mod;
}

string reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

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

bool contains(vector<int> s, int e) {
    for (int i = 0; i < s.size(); i++) {
        if (e == s[i]) {
            return true;
        }
    }
    return false;
}

vector<int> makeRange(int min, int max) {
    vector<int> a(max - min + 1);
    for (int i = 0; i < a.size(); i++) {
        a[i] = min + i;
    }
    return a;
}

vector<vector<int>> powerset2(vector<int> nums) {
    int length = pow(2, nums.size());
    vector<vector<int>> result(length);

    int index = 0;
    result[index] = vector<int>();
    index++;

    for (int i = 0; i < nums.size(); i++) {
        int max = index;
        for (int j = 0; j < max; j++) {
            result[index] = copyAndAppend(result[j], nums[i]);
            index++;
        }
    }

    return result;
}

vector<int> copyAndAppend(vector<int> nums, int n) {
    vector<int> dst(nums.size() + 1);
    copy(nums.begin(), nums.end(), dst.begin());
    dst[nums.size()] = n;
    return dst;
}

int calcGcd(int x, int y) {
    if (y == 0) {
        return x;
    } else if (x >= y) {
        return calcGcd(y, x % y);
    } else {
        return calcGcd(x, y % x);
    }
}

vector<int> getDivisor(int n) {
    set<int> divisor;
    divisor.insert(1);
    if (n!= 1) {
        divisor.insert(n);
    }

    int sqrt = sqrt(n);
    for (int i = 2; i <= sqrt; i++) {
        if (n % i == 0) {
            divisor.insert(i);
            divisor.insert(n / i);
        }
    }

    vector<int> divisorArray(divisor.begin(), divisor.end());
    return divisorArray;
}

struct IntHeap {
    vector<int> h;

    IntHeap() {}

    int size() {
        return h.size();
    }

    bool empty() {
        return h.empty();
    }

    void push(int x) {
        h.push_back(x);
        push_heap(h.begin(), h.end());
    }

    void pop() {
        pop_heap(h.begin(), h.end());
        h.pop_back();
    }

    int top() {
        return h[0];
    }
};

IntHeap* initIntHeap() {
    IntHeap* ih = new IntHeap();
    return ih;
}

void pushHeap(IntHeap* ih, int n) {
    ih->push(n);
}

int popHeap(IntHeap* ih) {
    int x = ih->top();
    ih->pop();
    return x;
}

int factMod(int n) {
    int value = 1;
    for (int i = 2; i <= n; i++) {
        value = calcMod(value * i);
    }
    return value;
}

int combinationMod(int n, int k) {
    int factN = factMod(n);
    int factK = factMod(k);
    int factNK = factMod(n - k);
    int factKR = powMod(factK, mod - 2);
    int factNKR = powMod(factNK, mod - 2);
    return calcMod(factN * calcMod(factKR * factNKR));
}

vector<int> primeFactors(int n) {
    vector<int> factors;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            n /= i;
            factors.push_back(i);
        } else {
            i++;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    int n = getInt();
    int m = getInt();
    int a = getInt();
    int b = getInt();
    int c = getInt();
    int d = getInt();
    int e = getInt();
    int f = getInt();
    int g = getInt();
    int h = getInt();
    int i = getInt();
    int j = getInt();
    int k = getInt();
    int l = getInt();
    int x = getInt();
    int y = getInt();
    int z = getInt();
    int w = getInt();
    int v = getInt();
    int u = getInt();
    int t = getInt();
    int s = getInt();
    int r = getInt();
    int q = getInt();
    int p = getInt();
    int o = getInt();
    int n = getInt();
    int m = getInt();
    int l = getInt();
    int k = getInt();
    int j = getInt();
    int i = getInt();
    int h = getInt();
    int g = getInt();
    int f = getInt();
    int e = getInt();
    int d = getInt();
    int c = getInt();
    int b = getInt();
    int a = getInt();
    int z = getInt();
    int y = getInt();
    int x = getInt();
    int w = getInt();
    int v = getInt();
    int u = getInt();
    int t = getInt();
    int s = getInt();
    int r = getInt();
    int q = getInt();
    int p = getInt();
    int o = getInt();
    int n = getInt();
    int m = getInt();
    int l = getInt();
    int k = getInt();
    int j = getInt();
    int i = getInt();
    int h = getInt();
    int g = getInt();
    int f = getInt();
    int e = getInt();
    int d = getInt();
    int c = getInt();
    int b = getInt();
    int a = getInt();
    int z = getInt();
    int y = getInt();
    int x = getInt();
    int w = getInt();
    int v = getInt();
    int u = getInt();
    int t = getInt();
    int s = getInt();
    int r = getInt();
    int q = getInt();
    int p = getInt();
    int o = getInt();
    int n = getInt();
    int m = getInt();
    int l = getInt();
    int k = getInt();
    int j = getInt();
    int i = getInt();
    int h = getInt();
    int g = getInt();
    int f = getInt();
    int e = getInt();
    int d = getInt();
    int c = getInt();
    int b = getInt();
    int a = getInt();
    int z = getInt();
    int y = getInt();
    int x = getInt();
    int w = getInt();
    int v = getInt();
    int u = getInt();
    int t = getInt();
    int s = getInt();
    int r = getInt();
    int q = getInt();
    int p = getInt();
    int o = getInt();
    int n = getInt();
    int m = getInt();
    int l = getInt();
    int k = getInt();
    int j = getInt();
    int i = getInt();
    int h = getInt();
    int g = getInt();
    int f = getInt();
    int e = getInt();
    int d = getInt();
    int c = getInt();
    int b = getInt();
    int a = getInt();
    int z = getInt();
    int y = getInt();
    int x = getInt();
    int w = getInt();
    int v = getInt();
    int u = getInt();
    int t = getInt();
    int s = getInt();
    int r = getInt();
    int q = getInt();
    int p = getInt();
    int o = getInt();
    int n = getInt();
    int m = getInt();
    int l = getInt();
    int k = getInt();
    int j = getInt();
    int i = getInt();
    int h = getInt();
    int g = getInt();
    int f = getInt();
    int e = getInt();
    int d = getInt();
    int c = getInt();
    int b = getInt();
    int a = getInt();
    int z = getInt();
    int y = getInt();
    int x = getInt();
    int w = getInt();
    int v = getInt();
    int u = getInt();
    int t = getInt();
    int s = getInt();
    int r = getInt();
    int q = getInt();
    int p = getInt();
    int o = getInt();
    int n = getInt();
    int m = getInt();
    int l = getInt();
    int k = getInt();
    int j = getInt();
    int i = getInt();
    int h = getInt();
    int g = getInt();
    int f = getInt();
    int e = getInt();
    int d = getInt();
    int c = getInt();
    int b = getInt();
    int a = getInt();
    int z = getInt();
    int y = getInt();
    int x = getInt();
    int w = getInt();
    int v = getInt();
    int u = getInt();
    int t = getInt();
    int s = getInt();
    int r = getInt()
    int q = getInt();
    int p = getInt();
    int o = getInt();
    int n = getInt();
    int m = getInt();
    int l = getInt();
    int k = getInt();
    int j = getInt();
    int i = getInt();
    int h = getInt();
    int g = getInt();
    int f = getInt();
    int e = getInt();
    int d = getInt();
    int c = getInt();
    int b = getInt();
    int a = getInt();
    int z = getInt();
    int y = getInt();
    int x = getInt();
    int w = getInt();
    int v = getInt();
    int u = getInt();
    int t = getInt();
    int s = getInt();
    int r = getInt();
    int q = getInt();
    int p = getInt();
    int o = getInt();
    int n = getInt();
    int m = getInt();
    int l = getInt();
    int k = getInt();
    int j = getInt();
    int i = getInt();
    int h = getInt();
    int g = getInt();
    int f = getInt();
    int e = getInt();
    int d = getInt();
    int c = getInt();
    int b = getInt();
    int a = getInt();
    int z = getInt();
    int y = getInt();
    int x = getInt();
    int w = getInt();
    int v = getInt();
    int u = getInt();
    int t = getInt();
    int s = getInt();
    int r = getInt();
    int q = getInt();
    int p = getInt();
    int o = getInt();
    int n = getInt();
    int m = getInt();
    int l = getInt();
    int k = getInt();
    int j = getInt();
    int i = getInt();
    int h = getIn