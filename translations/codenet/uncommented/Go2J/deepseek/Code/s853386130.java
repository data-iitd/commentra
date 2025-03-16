import java.util.*;

public class Main {
    static final int MOD = 1000000007;
    static final int INF = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int R = scanner.nextInt();

        int[] rs = new int[R];
        for (int i = 0; i < R; i++) {
            rs[i] = scanner.nextInt() - 1;
        }

        int[][] costs = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(costs[i], INF);
            costs[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            int c = scanner.nextInt();
            costs[a][b] = c;
            costs[b][a] = c;
        }

        // ワーシャルフロイド法で最短経路を算出
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    costs[i][j] = Math.min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }

        // 順列で訪問先の順序をすべて試す
        // これでは重複して訪問する町がでてしまうか。。
        List<List<Integer>> perms = permutations(rs);
        int ans = INF;
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

    // permutations
    public static List<List<Integer>> permutations(int[] arr) {
        List<List<Integer>> res = new ArrayList<>();
        permute(arr, 0, res);
        return res;
    }

    private static void permute(int[] arr, int n, List<List<Integer>> res) {
        if (n == arr.length - 1) {
            List<Integer> tmp = new ArrayList<>();
            for (int num : arr) {
                tmp.add(num);
            }
            res.add(tmp);
        } else {
            for (int i = n; i < arr.length; i++) {
                swap(arr, n, i);
                permute(arr, n + 1, res);
                swap(arr, n, i); // backtrack
            }
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Union-Find
    static class UnionFind {
        int[] parent;

        public UnionFind(int size) {
            parent = new int[size];
            Arrays.fill(parent, -1);
        }

        public int find(int x) {
            if (parent[x] < 0) {
                return x;
            }
            parent[x] = find(parent[x]);
            return parent[x];
        }

        public boolean union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) {
                return false;
            }

            if (parent[rootX] < parent[rootY]) {
                parent[rootX] += parent[rootY];
                parent[rootY] = rootX;
            } else {
                parent[rootY] += parent[rootX];
                parent[rootX] = rootY;
            }
            return true;
        }

        public boolean isConnected(int x, int y) {
            return find(x) == find(y);
        }

        public int size(int x) {
            return -parent[find(x)];
        }
    }

    // mod
    public static int modPow(int a, int n, int mod) {
        int res = 1;
        while (n > 0) {
            if (n % 2 != 0) {
                res = res * a % mod;
            }
            a = a * a % mod;
            n = n / 2;
        }
        return res;
    }

    public static int modInv(int n, int mod) {
        return modPow(n, mod - 2, mod);
    }

    public static int modComb(int n, int a, int mod) {
        int x = 1;
        int y = 1;
        for (int i = 0; i < a; i++) {
            x = x * (n - i) % mod;
            y = y * (i + 1) % mod;
        }
        return x * modPow(y, mod - 2, mod) % mod;
    }

    public static int modFactorial(int n, int mod) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result = (result * i) % mod;
        }
        return result;
    }

    // Combination ...
    static class Combination {
        int[] facts;
        int[] invs;
        int mod;

        public Combination(int size, int mod) {
            this.facts = new int[size + 1];
            this.invs = new int[size + 1];
            this.mod = mod;
            init(size);
        }

        public int calc(int n, int k) {
            int ret = facts[n] * invs[k];
            ret %= mod;
            ret = ret * invs[n - k] % mod;
            return ret;
        }

        private void init(int n) {
            facts[0] = 1;
            // 階乗を算出
            for (int i = 1; i <= n; i++) {
                facts[i] = facts[i - 1] * i % mod;
            }
            // 逆元を算出
            invs[n] = modInv(facts[n], mod);
            for (int i = n - 1; i >= 0; i--) {
                invs[i] = invs[i + 1] * (i + 1) % mod;
            }
        }
    }

    // Utility
    public static int min(int x, int y) {
        if (x < y) {
            return x;
        }
        return y;
    }

    public static int max(int x, int y) {
        if (x > y) {
            return x;
        }
        return y;
    }

    public static int abs(int x) {
        if (x < 0) {
            return -x;
        }
        return x;
    }

    public static Map<Integer, Integer> primeFactor(int x) {
        Map<Integer, Integer> res = new HashMap<>();
        for (int i = 2; i * i <= x; i++) {
            while (x % i == 0) {
                res.put(i, res.getOrDefault(i, 0) + 1);
                x = x / i;
            }
        }
        if (x != 1) {
            res.put(x, 1);
        }
        return res;
    }

    public static List<Integer> divisor(int x) {
        List<Integer> res = new ArrayList<>();
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                res.add(i);
                if (i != x / i) {
                    res.add(x / i);
                }
            }
        }
        Collections.sort(res);
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
        char[] arr = s.toCharArray();
        for (int i = 0, j = arr.length - 1; i < j; i++, j--) {
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        return new String(arr);
    }

    public static int pow(int a, int n) {
        int ret = 1;
        for (int i = 1; i <= n; i++) {
            ret *= a;
        }
        return ret;
    }

    // Queue ...
    static class Queue {
        private List<Integer> elements;

        public Queue() {
            elements = new ArrayList<>();
        }

        public boolean empty() {
            return elements.isEmpty();
        }

        public void push(int i) {
            elements.add(i);
        }

        public int pop() {
            if (empty()) {
                throw new NoSuchElementException();
            }
            int res = elements.get(0);
            elements.remove(0);
            return res;
        }
    }

    // Stack ...
    static class Stack {
        private List<Integer> elements;

        public Stack() {
            elements = new ArrayList<>();
        }

        public boolean empty() {
            return elements.isEmpty();
        }

        public void push(int i) {
            elements.add(i);
        }

        public int pop() {
            if (empty()) {
                throw new NoSuchElementException();
            }
            int index = elements.size() - 1;
            int res = elements.get(index);
            elements.remove(index);
            return res;
        }
    }

    // priority_queue
    static class IntHeap {
        private List<Integer> heap;

        public IntHeap() {
            heap = new ArrayList<>();
        }

        public int size() {
            return heap.size();
        }

        public boolean isEmpty() {
            return heap.isEmpty();
        }

        public void push(int x) {
            heap.add(x);
            int i = heap.size() - 1;
            while (i > 0) {
                int p = (i - 1) / 2;
                if (heap.get(p) >= x) break;
                heap.set(i, heap.get(p));
                i = p;
            }
            heap.set(i, x);
        }

        public int pop() {
            if (isEmpty()) throw new NoSuchElementException();
            int res = heap.get(0);
            int x = heap.remove(heap.size() - 1);
            if (isEmpty()) return res;
            heap.set(0, x);
            int i = 0;
            while (true) {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                if (left >= heap.size()) break;
                int maxChild = (right < heap.size() && heap.get(right) > heap.get(left)) ? right : left;
                if (heap.get(maxChild) <= x) break;
                heap.set(i, heap.get(maxChild));
                i = maxChild;
            }
            heap.set(i, x);
            return res;
        }
    }

    // sortable points
    static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Points extends ArrayList<Point> {
        @Override
        public int compareTo(Point other) {
            return Integer.compare(this.x, other.x);
        }
    }
