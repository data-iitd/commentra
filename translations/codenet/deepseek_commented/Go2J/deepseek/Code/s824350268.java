import java.util.*;
import java.lang.*;
import java.math.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static final int initialBufSize = 10000;
    static final int maxBufSize = 1000000;
    static final long mod = 1_000_000_007L;

    public static void main(String[] args) {
        int N = getInt();
        int sqrtN = (int) Math.sqrt(N);

        int min = N;
        for (int i = 1; i <= sqrtN; i++) {
            if (N % i != 0) {
                continue;
            }

            int num = i + (N / i) - 2;
            if (num < min) {
                min = num;
            }
        }

        System.out.println(min);
    }

    static class Graph {
        int n;
        List<List<Integer>> edges;

        Graph(int n) {
            this.n = n;
            this.edges = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                edges.add(new ArrayList<>());
            }
        }

        void addEdge(int u, int v) {
            edges.get(u).add(v);
            edges.get(v).add(u);
        }
    }

    static void dfs(int c, List<List<Integer>> edges, Set<Integer> visited) {
        visited.add(c);

        for (int v : edges.get(c)) {
            if (visited.contains(v)) {
                continue;
            }
            dfs(v, edges, visited);
        }
    }

    static int getInt() {
        return sc.nextInt();
    }

    static String getString() {
        return sc.next();
    }

    static int abs(int a) {
        return Math.abs(a);
    }

    static int pow(int p, int q) {
        return (int) Math.pow(p, q);
    }

    static int powMod(int n, int p) {
        if (p == 0) {
            return 1;
        } else if (p % 2 == 0) {
            int t = powMod(n, p / 2);
            return (int) ((t * t) % mod);
        } else {
            return (int) ((n * powMod(n, p - 1)) % mod);
        }
    }

    static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function max() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    static boolean strSearch(String[] a, String b) {
        for (String s : a) {
            if (s.equals(b)) {
                return true;
            }
        }
        return false;
    }

    static void printIntArray(int[] array) {
        System.out.println(Arrays.toString(array).replace("[", "").replace("]", ""));
    }

    static long calcMod(long x) {
        return x % mod;
    }

    static String reverse(String s) {
        char[] chars = s.toCharArray();
        int i = 0, j = chars.length - 1;
        while (i < j) {
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;
            i++;
            j--;
        }
        return new String(chars);
    }

    static boolean isPrime(int n) {
        if (n < 2) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n % 2 == 0) {
            return false;
        }

        int sqrtN = (int) Math.sqrt(n);
        for (int i = 3; i <= sqrtN; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

