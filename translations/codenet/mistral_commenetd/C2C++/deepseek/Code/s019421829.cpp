#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

#define MAX 707106
#define PRIME_SIZE 57100

using namespace std;

bool tbl[MAX+1];
int sz;
int prime[PRIME_SIZE] = {
  2, 3,  5,  7, 11, 13, 17, 19, 23, 29, 
 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
 73, 79, 83, 89, 97,101,103,107,109,113, 
127,131,137,139,149,151,157,163,167,173,
179,181,191,193,197,199,211,223,227,229, 
233,239,241,251,257,263,269,271,277,281, 
283,293,307,311,313,317,331,337,347,349, 
353,359,367,373,379,383,389,397,401,409, 
419,421,431,433,439,443,449,457,461,463, 
467,479,487,491,499,503,509,521,523,541, 
547,557,563,569,571,577,587,593,599,601, 
607,613,617,619,631,641,643,647,653,659, 
661,673,677,683,691,701,709,719,727,733, 
739,743,751,757,761,769,773,787,797,809, 
811,821,823,827,829,839,853 };

void sieve() {
    int i, j, k;
    for (i = 1; i < 147; i++) {
        k = prime[i];
        for (j = prime[i] * prime[i]; j < MAX; j += k) tbl[j] = true;
    }
    for (sz = 146, i = 853; i <= MAX; i += 2)
        if (!tbl[i]) prime[sz++] = i;
}

int bsch(int x) {
    int m, l = 0, r = sz;
    while (l < r) {
        m = (l + r) >> 1;
        if (prime[m] == x) return m;
        if (prime[m] < x) l = m + 1;
        else r = m;
    }
    return l - 1;
}

int main() {
    long long A, B, a, b;
    cin >> A >> B;
    a = A - B, b = A + B;
    if (b <= 1) { cout << "0\n"; return 0; }
    if (a <= 1) a = 2;
    sz = bsch((int)sqrt((double)(b >> 1)));
    vector<int> idx(b - a + 1, 1);
    vector<int> base(b - a + 1, 0);
    for (int i = 0; i <= sz; i++) {
        int p = prime[i];
        vector<long long> pp(1, p);
        for (long long j = p * p; j <= b; j *= p) pp.push_back(j);
        for (int k = pp.size() - 1; k >= 0; k--) {
            long long ll = pp[k] * ((a - 1) / pp[k] + 1);
            long long rr = pp[k] * (b / pp[k]);
            for (; ll <= rr; ll += pp[k]) {
                int x = ll - a;
                if (idx[x] && base[x] != p) {
                    base[x] = p;
                    idx[x] = k;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < idx.size(); i++) {
        if (idx[i]) ans++;
    }
    cout << ans << '\n';
    return 0;
}

