
import java.util.*;

public class s853386130{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int R = sc.nextInt();
        int[] rs = new int[R];
        for (int i = 0; i < R; i++) {
            rs[i] = sc.nextInt() - 1;
        }
        int[][] costs = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = 1000000007;
            }
            costs[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            int c = sc.nextInt();
            costs[a][b] = c;
            costs[b][a] = c;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }
        List<List<Integer>> perms = permutations(rs);
        int ans = 1000000007;
        for (List<Integer> perm : perms) {
            int tmp = 0;
            for (int j = 1; j < perm.size(); j++) {
                int from = perm.get(j - 1);
                int to = perm.get(j);
                tmp += costs[from][to];
            }
            ans = Math.min(ans, tmp);
        }
        System.out.println(ans);
    }

    public static List<List<Integer>> permutations(int[] arr) {
        List<List<Integer>> res = new ArrayList<>();
        helper(arr, 0, res);
        return res;
    }

    public static void helper(int[] arr, int n, List<List<Integer>> res) {
        if (n == 1) {
            List<Integer> tmp = new ArrayList<>();
            for (int i : arr) {
                tmp.add(i);
            }
            res.add(tmp);
        } else {
            for (int i = 0; i < n; i++) {
                helper(arr, n - 1, res);
                if (n % 2 == 1) {
                    int tmp = arr[i];
                    arr[i] = arr[n - 1];
                    arr[n - 1] = tmp;
                } else {
                    int tmp = arr[0];
                    arr[0] = arr[n - 1];
                    arr[n - 1] = tmp;
                }
            }
        }
    }

    public static class UnionFind {
        private int[] d;

        public UnionFind(int n) {
            d = new int[n];
            for (int i = 0; i < n; i++) {
                d[i] = -1;
            }
        }

        public int find(int x) {
            if (d[x] < 0) {
                return x;
            }
            d[x] = find(d[x]);
            return d[x];
        }

        public boolean unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) {
                return false;
            }

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

    public static int modinv(int n, int mod) {
        return modpow(n, mod - 2, mod);
    }

    public static int modcomb(int n, int a, int mod) {
        int x = 1;
        int y = 1;
        for (int i = 0; i < a; i++) {
            x = x * (n - i) % mod;
            y = y * (i + 1) % mod;
        }
        return x * modpow(y, mod - 2, mod) % mod;
    }

    public static int modfactorial(int n, int mod) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result = (result * i) % mod;
        }
        return result;
    }

    public static class Combination {
        private int[] facts;
        private int[] invs;
        private int mod;

        public Combination(int n, int mod) {
            facts = new int[n + 1];
            invs = new int[n + 1];
            this.mod = mod;
        }

        public void init(int n) {
            facts[0] = 1;
            for (int i = 1; i <= n; i++) {
                facts[i] = facts[i - 1] * i % mod;
            }
            invs[n] = modinv(facts[n], mod);
            for (int i = n - 1; i >= 0; i--) {
                invs[i] = invs[i + 1] * (i + 1) % mod;
            }
        }

        public int calc(int n, int k) {
            int res = facts[n] * invs[k] % mod;
            res = res * invs[n - k] % mod;
            return res;
        }
    }

    public static int min(int x, int y) {
        return x < y? x : y;
    }

    public static int max(int x, int y) {
        return x > y? x : y;
    }

    public static int abs(int x) {
        return x < 0? -x : x;
    }

    public static Map<Integer, Integer> primeFactor(int x) {
        Map<Integer, Integer> res = new HashMap<>();
        for (int i = 2; i * i <= x; i++) {
            while (x % i == 0) {
                res.put(i, res.getOrDefault(i, 0) + 1);
                x = x / i;
            }
        }
        if (x!= 1) {
            res.put(x, res.getOrDefault(x, 0) + 1);
        }
        return res;
    }

    public static List<Integer> divisor(int x) {
        List<Integer> res = new ArrayList<>();
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                res.add(i);
                if (i!= x / i) {
                    res.add(x / i);
                }
            }
        }
        return res;
    }

    public static int gcd(int x, int y) {
        if (y == 0) {
            return x;
        }
        return gcd(y, x % y);
    }

    public static int lcm(int x, int y) {
        return x / gcd(x, y) * y;
    }

    public static String reverseString(String s) {
        StringBuilder sb = new StringBuilder(s);
        return sb.reverse().toString();
    }

    public static int pow(int a, int n) {
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res *= a;
        }
        return res;
    }

    public static class Queue {
        private List<Integer> que;

        public Queue() {
            que = new ArrayList<>();
        }

        public boolean empty() {
            return que.size() == 0;
        }

        public void push(int i) {
            que.add(i);
        }

        public int pop() {
            int res = que.get(0);
            que.remove(0);
            return res;
        }
    }

    public static class Stack {
        private List<Integer> st;

        public Stack() {
            st = new ArrayList<>();
        }

        public boolean empty() {
            return st.size() == 0;
        }

        public void push(int i) {
            st.add(0, i);
        }

        public int pop() {
            int res = st.get(st.size()-1);
            st.remove(st.size()-1);
            return res;
        }
    }

    public static int gcd(int x, int y) {
        if (y == 0) {
            return x;
        }
        return gcd(y, x%y);
    }

    public static int lcm(int x, int y) {
        return x / gcd(x, y) * y;
    }

    public static String reverseString(String s) {
        StringBuilder sb = new StringBuilder(s);
        return sb.reverse().toString();
    }

    public static int modpow(int a, int n, int mod) {
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res = res * i % mod
        }
        return res;
    }

    public static int modcomb(int n, int a, int mod) {
        int x = 1;
        for (int i = 1; i <= n; i++) {
            x = x * i % mod
        }
        return x;
    }

    public static int modfactorial(int n, int mod) {
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res = res * i % mod
        }
        return res;
    }

    public static class UnionFind {
        private int[] d;

        public UnionFind(int n) {
            for (int i = 0; i < n; i++) {
                d[i] = -1;
            if d[i] == -1 {
                d[i] = i
            }
            return d;
        }

        public static bool unite(int x, int y) {
            x = x || y
        }

        public static int abs(int x) {
            return x % y
        }

        public static int pow(int a, int n) {
            int res = 1;
            for (int i = 1; i <= n; i++) {
                res = res * i % mod
        }
        return res;
    }

    public static int min(int x, int y) {
            return min(x, y)
        }

        public static int max(int x, int y) {
            return max(x, y)
        }

        public static int gcd(int x, int y) {
            return gcd(x, y)
        }

        public static int lcm(int x, int y) {
            return x / gcd(x, y)
        }

        public static int reverseString(String s) {
            StringBuilder sb = new StringBuilder(s)
            return sb.reverse().toString();
        }

        public static int modpow(int a, int n, int mod) {
            int res = 1;
            for (int i = 0; i < n; i++) {
                res = res * i % mod
        }
        return res;
    }

    public static int modfactorial(int n, int mod) {
            int res = 1;
            for (int i = 0; i < n; i++) {
                res = res * i % mod
        }
        return res;
    }

    public static int permutations(int n, int mod) {
            int res = 1;
            for (int i = 0; i < n; i++) {
                res = res * i % mod
        }
        return res;
    }

    public static int min(int x, int y) {
            return min(x, y)
        }

        public static i