
import java.util.*;

public class s633919449{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        switch (N % 10) {
            case 2:
            case 4:
            case 5:
            case 7:
            case 9:
                System.out.println("hon");
                break;
            case 0:
            case 1:
            case 6:
            case 8:
                System.out.println("pon");
                break;
            case 3:
                System.out.println("bon");
                break;
        }
    }
}

// The Graph class and its methods are defined in Java.
// The dfs and bfs functions are implemented in Java.
// These functions are useful for graph traversal and can be used for various graph-related problems.
class Graph {
    private int n;
    private List<List<Integer>> edges;

    public Graph(int n) {
        this.n = n;
        this.edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            this.edges.add(new ArrayList<>());
        }
    }

    public void addEdge(int u, int v) {
        edges.get(u).add(v);
        edges.get(v).add(u);
    }

    public void dfs(int c, boolean[] visited) {
        visited[c] = true;

        for (int v : edges.get(c)) {
            if (!visited[v]) {
                dfs(v, visited);
            }
        }
    }

    public void bfs(int c) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(c);
        boolean[] visited = new boolean[n];
        visited[c] = true;

        while (!queue.isEmpty()) {
            int u = queue.poll();

            for (int v : edges.get(u)) {
                if (!visited[v]) {
                    visited[v] = true;
                    queue.add(v);
                }
            }
        }
    }
}

// Utility functions are defined for converting strings to integers, calculating absolute values, finding powers,
// and checking primality. These functions enhance code reusability and readability.
public class s633919449{
    public static int getInt() {
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }

    public static int[] getIntArray(int n) {
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = getInt();
        }
        return array;
    }

    public static String getString() {
        Scanner sc = new Scanner(System.in);
        return sc.next();
    }

    public static String[] getStringArray(int n) {
        String[] array = new String[n];
        for (int i = 0; i < n; i++) {
            array[i] = getString();
        }
        return array;
    }

    public static int abs(int a) {
        return Math.abs(a);
    }

    public static int pow(int p, int q) {
        return (int) Math.pow(p, q);
    }

    public static int powMod(int n, int p) {
        if (p == 0) {
            return 1;
        } else if (p % 2 == 0) {
            int t = powMod(n, p / 2);
            return calcMod(t * t);
        } else {
            return calcMod(n * powMod(n, p - 1));
        }
    }

    public static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int i = 0; i < nums.length; i++) {
            res = Math.min(res, nums[i]);
        }
        return res;
    }

    public static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function max() requires at least one argument.");
        }
        int res = nums[0];
        for (int i = 0; i < nums.length; i++) {
            res = Math.max(res, nums[i]);
        }
        return res;
    }

    public static boolean strSearch(String[] a, String b) {
        for (String s : a) {
            if (s.equals(b)) {
                return true;
            }
        }
        return false;
    }

    public static void printIntArray(int[] array) {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < array.length; i++) {
            sb.append(array[i]);
            if (i < array.length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        System.out.println(sb.toString());
    }

    public static int calcMod(int x) {
        return x % 100000007;
    }

    public static String reverse(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    public static boolean isPrime(int n) {
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

    public static boolean contains(int[] s, int e) {
        for (int v : s) {
            if (e == v) {
                return true;
            }
        }
        return false;
    }

    public static int[] makeRange(int min, int max) {
        int[] a = new int[max - min + 1];
        for (int i = 0; i < a.length; i++) {
            a[i] = min + i;
        }
        return a;
    }

    public static List<List<Integer>> powerset2(int[] nums) {
        int length = (int) Math.pow(2, nums.length);
        List<List<Integer>> result = new ArrayList<>();

        int index = 0;
        result.add(new ArrayList<>());
        index++;

        for (int n : nums) {
            int max = index;
            for (int i = 0; i < max; i++) {
                List<Integer> newList = copyAndAppend(result.get(i), n);
                result.add(newList);
                index++;
            }
        }

        return result;
    }

    public static List<Integer> copyAndAppend(List<Integer> nums, int n) {
        List<Integer> dst = new ArrayList<>();
        dst.addAll(nums);
        dst.add(n);
        return dst;
    }

    public static int calcGcd(int x, int y) {
        if (y == 0) {
            return x;
        } else if (x >= y) {
            return calcGcd(y, x % y);
        } else {
            return calcGcd(x, y % x);
        }
    }

    public static int[] getDivisor(int n) {
        Set<Integer> divisor = new HashSet<>();
        divisor.add(1);
        if (n!= 1) {
            divisor.add(n);
        }

        int sqrt = (int) Math.sqrt(n);
        for (int i = 2; i <= sqrt; i++) {
            if (n % i == 0) {
                divisor.add(i);
                divisor.add(n / i);
            }
        }

        int[] divisorArray = new int[divisor.size()];
        int index = 0;
        for (int d : divisor) {
            divisorArray[index] = d;
            index++;
        }
        return divisorArray;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        switch (N % 10) {
            case 2:
            case 4:
            case 5:
            case 7:
            case 9:
                System.out.println("hon");
                break;
            case 0:
            case 1:
            case 6:
            case 8:
                System.out.println("pon");
                break;
            case 3:
                System.out.println("bon");
                break;
        }
    }
}