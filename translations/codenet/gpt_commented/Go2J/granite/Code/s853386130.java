
import java.util.*;
import java.io.*;

class s853386130 {
    public static void main(String[] args) throws Exception {
        // Initialize a buffered reader to read input
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(r.readLine());
        int m = Integer.parseInt(r.readLine());
        int R = Integer.parseInt(r.readLine());
        int[] rs = new int[R];
        for (int i = 0; i < R; i++) {
            rs[i] = Integer.parseInt(r.readLine());
        }
        int[][] costs = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = 1000000007;
            }
            costs[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int a = Integer.parseInt(r.readLine());
            int b = Integer.parseInt(r.readLine());
            int c = Integer.parseInt(r.readLine());
            costs[a-1][b-1] = c;
            costs[b-1][a-1] = c;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }
        List<List<Integer>> perms = getPermutations(rs);
        int ans = 1000000007;
        for (List<Integer> perm : perms) {
            int tmp = 0;
            for (int j = 1; j < perm.size(); j++) {
                int from = perm.get(j-1);
                int to = perm.get(j);
                tmp += costs[from-1][to-1];
            }
            ans = Math.min(ans, tmp);
        }
        System.out.println(ans);
    }

    public static List<List<Integer>> getPermutations(int[] arr) {
        List<List<Integer>> res = new ArrayList<>();
        if (arr.length == 0) {
            res.add(new ArrayList<>());
            return res;
        }
        List<Integer> prefix = new ArrayList<>();
        prefix.add(arr[0]);
        List<Integer> rest = Arrays.stream(arr).skip(1).boxed().collect(Collectors.toList());
        List<List<Integer>> subPerms = getPermutations(rest.toArray(new Integer[0]));
        for (List<Integer> subPerm : subPerms) {
            for (int i = 0; i <= subPerm.size(); i++) {
                List<Integer> perm = new ArrayList<>(prefix);
                perm.addAll(i, subPerm);
                res.add(perm);
            }
        }
        return res;
    }
}

// Union-Find structure for disjoint set operations
class UnionFind {
    private int[] d;

    public UnionFind(int n) {
        d = new int[n];
        for (int i = 0; i < n; i++) {
            d[i] = -1; // Initialize each node as its own root
        }
    }

    public int find(int x) {
        if (d[x] < 0) {
            return x;
        }
        d[x] = find(d[x]); // Path compression
        return d[x];
    }

    public boolean unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false; // x and y are already in the same set
        }

        // Union by size
        if (d[rootX] < d[rootY]) {
            d[rootX] += d[rootY];
            d[rootY] = rootX;
        } else {
            d[rootY] += d[rootX];
            d[rootX] = rootY;
        }

        return true;
    }

    public boolean same(int x, int y) {
        return find(x) == find(y);
    }

    public int size(int x) {
        return -d[find(x)];
    }
}

// modpow calculates (a^n) % mod using exponentiation by squaring
public static int modpow(int a, int n, int mod) {
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

// modinv calculates the modular inverse of n % mod
public static int modinv(int n, int mod) {
    return modpow(n, mod-2, mod);
}

// modcomb calculates n choose a (nCk) % mod
public static int modcomb(int n, int a, int mod) {
    int x = 1;
    int y = 1;
    for (int i = 0; i < a; i++) {
        x = x * (n - i) % mod;
        y = y * (i + 1) % mod;
    }
    return x * modpow(y, mod-2, mod) % mod;
}

// modfactorial calculates n! % mod
public static int modfactorial(int n, int mod) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % mod;
    }
    return result;
}

// Combination structure for precomputed factorials and inverses
public static class Combination {
    private int[] facts;
    private int[] invs;
    private int mod;

    public Combination(int n, int mod) {
        facts = new int[n+1];
        invs = new int[n+1];
        this.mod = mod;
    }

    public int calc(int n, int k) {
        int res = facts[n] * invs[k] % mod;
        res = res * invs[n-k] % mod;
        return res;
    }

    public void init(int n) {
        facts[0] = 1;
        // Calculate factorials
        for (int i = 1; i <= n; i++) {
            facts[i] = facts[i-1] * i % mod;
        }
        // Calculate inverses using modular inverse
        invs[n] = modinv(facts[n], mod);
        for (int i = n-1; i >= 0; i--) {
            invs[i] = invs[i+1] * (i + 1) % mod;
        }
    }
}

// Utility functions

// min returns the smaller of two integers
public static int min(int x, int y) {
    if (x < y) {
        return x
    }
    return y
}

// max returns the larger of two integers
public static int max(int x, int y) {
    if (x > y) {
        return x
    }
    return y
}

// abs returns the absolute value of an integer
public static int abs(int x) {
    if (x < 0) {
        return -x
    }
    return x
}

// primeFactor returns the prime factorization of x
public static Map<Integer, Integer> primeFactor(int x) {
    Map<Integer, Integer> res = new HashMap<>();
    for (int i = 2; i*i <= x; i++) {
        for (x = x / i; x %= i
		}
		res[i] = x
	}
	}
	}

// divisor returns all divisors of x
public static List<Integer> divisor(int x) {
    List<Integer> divisors = new ArrayList<>();
    for (int i = 1; i*i <= x; i++) {
        for (x = x / i; x %= i
		}
		divisors = append(divisors, i)
	}
	}

// gcd returns the greatest common divisor of x and y
public static int gcd(int x, int y) {
    if (y == 0) {
        return x
    }
    return y
}

// lcm returns the least common multiple of x and y
public static int lcm(int x, int y) {
    if (y == 0) {
        return x
    }
    return y
}

// reverseString returns the reversed version of a string
public static int reverseString(string s) {
    return s
}

// init precomputes factorials and their inverses
public static void init(int n) {
    for (int i = 0; i < n; i++) {
        facts[i] = facts[i-1] * (i + 1) % mod
		}
		invs[n] = modinv(facts[n], mod)
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < n; l++) {
						for (int m = 0; m < n; m++) {
			for (int n = 0; n < n; n++) {
				for (int o = 0; o < n; o++) {
					for (int p = 0; p < n; p++) {
						for (int q = 0; q < n; q++) {
							for (int r = 0; r < n; r++) {
				for (int s = 0; s < n; s++) {
					for (int t = 0; t < n; t++) {
						for (int u = 0; u < n; u++) {
							for (int v = 0; v < n; v++) {
				for (int w = 0; w < n; w++) {
					for (int x = 0; x < n; x++) {
						for (int y = 0; y < n; y++) {
							for (int z = 0; z < n; z++) {
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < n; b++) {
						for (int c = 0; c < n; c++) {
							for (int d = 0; d < n; d++) {
				for (int e = 0; e < n; e++) {
					for (int f = 0; f < n; f++) {
						for (int g = 0; g < n; g++) {
							for (int h = 0; h < n; h++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						for (int k = 0; k < n; k++) {
							for (int l = 0; l < n; l++) {
				for (int m = 0; m < n; m++) {
					for (int n = 0; n < n; n++) {
						for (int o = 0; o < n; o++) {
							for (int p = 0; p < n; p++) {
				for (int q = 0; q < n; q++) {
					for (int r = 0; r < n; r++) {
						for (int s = 0; s < n; s++) {
			for (int t = 0; t < n; t++) {
				for (int u = 0; u < n; u++) {
					for (int v = 0; v < n; v++) {
						for (int w = 0; w < n; w++) {
							for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					for (int z = 0; z < n; z++) {
						for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				for (int c = 0; c < n; c++) {
					for (int d = 0; d < n; d++) {
						for (int e = 0; e < n; e++) {
			for (int f = 0; f < n; f++) {
				for (int g = 0; g < n; g++) {
					for (int h = 0; h < n; h++) {
						for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < n; l++) {
						for (int m = 0; m < n; m++) {
			for (int n = 0; n < n; n++) {
				for (int o = 0; o < n; o++) {
					for (int p = 0; p < n; p++) {
						for (int q = 0; q < n; q++) {
			for (int r = 0; r < n; r++) {
				for (int s = 0; s < n; s++) {
					for (int t = 0; t < n; t++) {
						for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				for (int w = 0; w < n; w++) {
					for (int x = 0; x < n; x++) {
						for (int y = 0; y < n; y++) {
			for (int z = 0; z < n; z++) {
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < n; b++) {
						for (int c = 0; c < n; c++) {
			for (int d = 0; d < n; d++) {
				for (int e = 0; e < n; e++) {
					for (int f = 0; f < n; f++) {
						for (int g = 0; g < n; g++) {
			for (int h = 0; h < n; h++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						for (int k = 0; k < n; k++) {
			for (int l = 0; l < n; l++) {
			for (int m = 0; m < n; m++) {
				for (int n = 0; n < n; n++) {
					for (int o = 0; o < n; o++) {
					for (int p = 0; p < n; p++) {
		for (int q = 0; q < n; q++) {
			for (int r = 0; r < n; r++) {
				for (int s = 0; s < n; s++) {
					for (int t = 0; t < n; t++) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				for (int w = 0; w < n; w++) 