
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Package main defines the entry point of the application.
int main() {
    // I/O functions for reading input efficiently.
    char buf[1024];
    char *p = buf;
    char *end = buf + 1024;
    char c;
    int i;
    int n, x;
    int *A;

    // Utility functions for dynamic programming.
    int ChMin(int *updatedValue, int target) {
        if (*updatedValue > target) {
            *updatedValue = target;
            return 1;
        }
        return 0;
    }

    int ChMax(int *updatedValue, int target) {
        if (*updatedValue < target) {
            *updatedValue = target;
            return 1;
        }
        return 0;
    }

    int GetNthBit(int num, int nth) {
        return num >> nth & 1;
    }



    // Arithmetic functions for mathematical operations.
    int Max(int *integers, int n) {
        int m = integers[0];
        for (i = 0; i < n; i++) {
            if (m < integers[i]) {
                m = integers[i];
            }
        }
        return m;
    }

    int Min(int *integers, int n) {
        int m = integers[0];
        for (i = 0; i < n; i++) {
            if (m > integers[i]) {
                m = integers[i];
            }
        }
        return m;
    }

    int CeilInt(int a, int b) {
        int res = a / b;
        if (a%b > 0) {
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
            panic(errors.New("[argument error]: PowInt does not accept negative integers"));
        }

        if (e == 0) {
            return 1;
        }

        if (e%2 == 0) {
            int halfE = e / 2;
            int half = PowInt(a, halfE);
            return half * half;
        }

        return a * PowInt(a, e-1);
    }

    int AbsInt(int a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }

    int Gcd(int a, int b) {
        if (a <= 0 || b <= 0) {
            panic(errors.New("[argument error]: Gcd only accepts two NATURAL numbers"));
        }
        if (a < b) {
            a = b;
        }

        for (b > 0; b > 0;) {
            int div = a % b;
            a = b;
            b = div;
        }

        return a;
    }

    int Lcm(int a, int b) {
        if (a <= 0 || b <= 0) {
            panic(errors.New("[argument error]: Gcd only accepts two NATURAL numbers"));
        }

        int gcd = Gcd(a, b);
        return (a / gcd) * b;
    }



    // Utility functions for string manipulation and permutation.
    int DeleteElement(int *s, int i) {
        if (i < 0 || len(s) <= i) {
            panic(errors.New("[index error]"));
        }
        int n = make(int, 0, len(s)-1);
        n = append(n, s[:i]...);
        n = append(n, s[i+1:]...);
        return n;
    }

    int Concat(int *s, int *t) {
        int n = make(int, 0, len(s)+len(t));
        n = append(n, s...);
        n = append(n, t...);
        return n;
    }

    int UpperRune(int r) {
        char str[100];
        sprintf(str, "%c", r);
        return str[0];
    }

    int LowerRune(int r) {
        char str[100];
        sprintf(str, "%c", r);
        return str[0];
    }

    int ToggleRune(int r) {
        char str[100];
        if ('a' <= r && r <= 'z') {
            sprintf(str, "%c", r);
            return str[0];
        } else if ('A' <= r && r <= 'Z') {
            sprintf(str, "%c", r);
            return str[0];
        } else {
            sprintf(str, "%c", r);
            return str[0];
        }
    }

    int ToggleString(int *s) {
        int inputRunes = []rune(s);
        int outputRunes = make(int, 0, len(inputRunes));
        for (i, r := range inputRunes) {
            outputRunes = append(outputRunes, ToggleRune(r));
        }
        return string(outputRunes);
    }

    int Strtoi(int *s) {
        if (i, err := strconv.Atoi(s); err != nil) {
            panic(errors.New("[argument error]: Strtoi only accepts integer string"));
        } else {
            return i;
        }
    }



    // Functions for generating permutations.
    int CalcFactorialPatterns(int *elements) {
        int copiedResidual = make(int, len(elements));
        copy(copiedResidual, elements);
        return factorialRecursion([]int{}, copiedResidual);
    }

    int factorialRecursion(int *interim, int *residual) {
        if (len(residual) == 0) {
            return []int{interim};
        }

        int res = []int{};
        for (i, elem := range residual) {
            int copiedInterim = make(int, len(interim));
            copy(copiedInterim, interim);
            copiedInterim = append(copiedInterim, elem);
            int copiedResidual = genDeletedSlice(i, residual);
            res = append(res, factorialRecursion(copiedInterim, copiedResidual)...);
        }

        return res;
    }

    int genDeletedSlice(int delId, int *S) {
        int res = []int{};
        res = append(res, S[:delId]...);
        res = append(res, S[delId+1:]...);
        return res;
    }

    int CalcDuplicatePatterns(int *elements, int digit) {
        return duplicateRecursion([]int{}, elements, digit);
    }

    int duplicateRecursion(int *interim, int *elements, int digit) {
        if (len(interim) == digit) {
            return []int{interim};
        }

        int res = []int{};
        for (i := 0; i < len(elements); i++) {
            int copiedInterim = make(int, len(interim));
            copy(copiedInterim, interim);
            copiedInterim = append(copiedInterim, elements[i]);
            res = append(res, duplicateRecursion(copiedInterim, elements, digit)...);
        }

        return res;
    }



    // Binary search functions.
    int GeneralLowerBound(int *s, int key) {
        int isOK(int index, int key) {
            if (s[index] >= key) {
                return 1;
            }
            return 0;
        }

        int ng, ok = -1, len(s);
        for (int(math.Abs(float64(ok-ng))) > 1;) {
            int mid = (ok + ng) / 2;
            if (isOK(mid, key)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        return ok;
    }

    int GeneralUpperBound(int *s, int key) {
        int isOK(int index, int key) {
            if (s[index] > key) {
                return 1;
            }
            return 0;
        }

        int ng, ok = -1, len(s);
        for (int(math.Abs(float64(ok-ng))) > 1;) {
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
    int InitParents(int *parents, int maxNodeId) {
        for (i := 0; i <= maxNodeId; i++) {
            parents[i] = i;
        }
    }

    int unite(int x, int y, int *parents) {
        int xp, yp = root(x, parents), root(y, parents);
        if (xp == yp) {
            return;
        }

        parents[xp] = yp;
    }

    int same(int x, int y, int *parents) {
        return root(x, parents) == root(y, parents);
    }

    int root(int x, int *parents) {
        if (parents[x] == x) {
            return x;
        }

        parents[x] = root(parents[x], parents);
        return parents[x];
    }



    // Prime factorization and checking.
    int TrialDivision(int n) {
        if (n <= 1) {
            panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number"));
        }

        int p = map[int]int{};
        for (i := 2; i*i <= n; i++) {
            int exp = 0;
            for (n%i == 0; n%i == 0;) {
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

    int IsPrime(int n) {
        if (n == 1) {
            return 0;
        }

        for (i := 2; i*i <= n; i++) {
            if (n%i == 0) {
                return 0;
            }
        }

        return 1;
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

        if (e%2 == 0) {
            int halfE = e / 2;
            int half = modpow(a, halfE, m);
            return half * half % m;
        }

        return a * modpow(a, e-1, m) % m;
    }

    int CalcModInv(int a, int m) {
        return modpow(a, m-2, m);
    }



    // Min-heap implementation using the heap package.
    int IntHeap []int;

    int IntHeapLen(IntHeap h) {
        return len(h);
    }

    int IntHeapLess(IntHeap h, int i, int j) {
        return h[i] < h[j];
    }

    int IntHeapSwap(IntHeap h, int i, int j) {
        h[i], h[j] = h[j], h[i];
    }

    int IntHeapPush(IntHeap *h, int x) {
        *h = append(*h, x);
    }

    int IntHeapPop(IntHeap *h) {
        old := *h;
        n := len(old);
        x := old[n-1];
        *h = old[0 : n-1];
        return x;
    }



    // Main function to read input, sort the array, and calculate the answer.
    n, x = ReadInt(), ReadInt();
    A = ReadIntSlice(n);

    sort.Sort(sort.IntSlice(A));

    ans := 0;
    for (i := 0; i < n; i++) {
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
    printf("%d\n", ans);

    return 0;
}