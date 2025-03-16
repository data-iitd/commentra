
#include <stdio.h>
#include <stdlib.h>

// Define the union-find structure
typedef struct {
    int *d;
} unionFind;

// Initialize a new union-find structure
unionFind *newUnionFind(int n) {
    unionFind *uf = (unionFind *)malloc(sizeof(unionFind));
    uf->d = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        uf->d[i] = -1; // Initialize each node as its own root
    }
    return uf;
}

// Find the root of the set containing x
int find(unionFind *uf, int x) {
    if (uf->d[x] < 0) {
        return x;
    }
    uf->d[x] = find(uf, uf->d[x]); // Path compression
    return uf->d[x];
}

// Merge the sets containing x and y
bool unite(unionFind *uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);
    if (rootX == rootY) {
        return false; // x and y are already in the same set
    }

    // Union by size
    if (uf->d[rootX] < uf->d[rootY]) {
        uf->d[rootX] += uf->d[rootY];
        uf->d[rootY] = rootX;
    } else {
        uf->d[rootY] += uf->d[rootX];
        uf->d[rootX] = rootY;
    }

    return true;
}

// Check if x and y are in the same set
bool same(unionFind *uf, int x, int y) {
    return find(uf, x) == find(uf, y);
}

// Get the size of the set containing x
int size(unionFind *uf, int x) {
    return -uf->d[find(uf, x)];
}

// Calculate (a^n) % mod using exponentiation by squaring
int modpow(int a, int n, int mod) {
    int res = 1;
    for (int i = 0; i < n; i++) {
        if (n % 2!= 0) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n = n / 2;
    }
    return res;
}

// Calculate the modular inverse of n % mod
int modinv(int n, int mod) {
    return modpow(n, mod - 2, mod);
}

// Calculate n choose a (nCk) % mod
int modcomb(int n, int a, int mod) {
    int x = 1;
    int y = 1;
    for (int i = 0; i < a; i++) {
        x = x * (n - i) % mod;
        y = y * (i + 1) % mod;
    }
    return x * modpow(y, mod - 2, mod) % mod;
}

// Calculate n! % mod
int modfactorial(int n, int mod) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % mod;
    }
    return result;
}

// Combination structure for precomputed factorials and inverses
typedef struct {
    int *facts;
    int *invs;
    int mod;
} Combination;

// Initialize a new Combination structure
Combination *newCombination(int n, int mod) {
    Combination *cmb = (Combination *)malloc(sizeof(Combination));
    cmb->facts = (int *)malloc(sizeof(int) * (n + 1));
    cmb->invs = (int *)malloc(sizeof(int) * (n + 1));
    cmb->mod = mod;
    return cmb;
}

// Calculate n choose k (nCk) using precomputed values
int calc(Combination *<fim_middle>
	for i := 0; i < R; i++ {
		for j := i + 1; j < R; j++ {
			ans = min(ans, costs[rs[i]][rs[j]])
		}
	}
	fmt.Println(ans)
}