import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {
    // Constants for buffer sizes and modulo value
    static final int initialBufSize = 10000;
    static final int maxBufSize = 1000000;
    static final double mod = 1e9 + 7;

    // Scanner for reading input
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        // Read an integer input
        int N = getInt();

        // Determine the output based on the last digit of N
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

    // Graph structure to represent edges
    static class Graph {
        int n;
        List<List<Integer>> edges;

        Graph(int n) {
            this.n = n;
            this.edges = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                this.edges.add(new ArrayList<>());
            }
        }

        void addEdge(int u, int v) {
            this.edges.get(v).add(u);
            this.edges.get(u).add(v);
        }
    }

    // Depth-first search (DFS) algorithm implementation
    static void dfs(int c, List<List<Integer>> edges, Set<Integer> visited) {
        visited.add(c);

        // Visit all adjacent nodes recursively
        for (int v : edges.get(c)) {
            if (visited.contains(v)) {
                continue;
            }
            dfs(v, edges, visited);
        }
    }

    // Breadth-first search (BFS) algorithm implementation
    static void bfs(int c, Graph graph) {
        Queue<Integer> next = new LinkedList<>();
        next.add(c);
        Set<Integer> visited = new HashSet<>();

        // Continue until there are no more nodes to visit
        while (!next.isEmpty()) {
            int u = next.poll();
            visited.add(u);

            // Process each adjacent node
            for (int v : graph.edges.get(u)) {
                if (visited.contains(v)) {
                    continue;
                }

                // Placeholder for processing the node (e.g., marking, counting, etc.)

                next.add(v);
            }
        }
    }

    // Function to read an integer from input
    static int getInt() {
        return sc.nextInt();
    }

    // Function to read an array of integers from input
    static int[] getIntArray(int n) {
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = getInt();
        }
        return array;
    }

    // Function to read a string from input
    static String getString() {
        return sc.next();
    }

    // Function to read an array of strings from input
    static String[] getStringArray(int n) {
        String[] array = new String[n];
        for (int i = 0; i < n; i++) {
            array[i] = getString();
        }
        return array;
    }

    // Function to calculate the absolute value of an integer
    static int abs(int a) {
        return (int) Math.abs(a);
    }

    // Function to calculate p raised to the power of q
    static int pow(int p, int q) {
        return (int) Math.pow(p, q);
    }

    // Function to calculate n raised to the power of p modulo mod
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

    // Function to find the minimum value among a list of integers
    static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    // Function to find the maximum value among a list of integers
    static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function max() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    // Function to check if a string exists in an array of strings
    static boolean strSearch(String[] a, String b) {
        for (String s : a) {
            if (s.equals(b)) {
                return true;
            }
        }
        return false;
    }

    // Function to print an array of integers
    static void printIntArray(int[] array) {
        StringBuilder sb = new StringBuilder();
        for (int i : array) {
            sb.append(i).append(" ");
        }
        System.out.println(sb.toString().trim());
    }

    // Function to calculate x modulo mod
    static int calcMod(int x) {
        return x % (int) mod;
    }

    // Function to reverse a string
    static String reverse(String s) {
        char[] chars = s.toCharArray();
        for (int i = 0, j = chars.length - 1; i < j; i++, j--) {
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;
        }
        return new String(chars);
    }

    // Function to check if a number is prime
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

    // Function to check if an integer exists in a slice
    static boolean contains(int[] s, int e) {
        for (int num : s) {
            if (e == num) {
                return true;
            }
        }
        return false;
    }

    // Function to create a range of integers from min to max
    static int[] makeRange(int min, int max) {
        int[] a = new int[max - min + 1];
        for (int i = 0; i < a.length; i++) {
            a[i] = min + i;
        }
        return a;
    }

    // Function to generate the powerset of a given slice of integers
    static List<List<Integer>> powerset(int[] nums) {
        int length = (int) Math.pow(2, nums.length);
        List<List<Integer>> result = new ArrayList<>(length);

        int index = 0;
        result.add(new ArrayList<>());
        index++;

        // Generate all subsets
        for (int n : nums) {
            int max = index;
            for (int i = 0; i < max; i++) {
                List<Integer> subset = new ArrayList<>(result.get(i));
                subset.add(n);
                result.add(subset);
                index++;
            }
        }

        return result;
    }

    // Function to calculate the greatest common divisor (GCD) of two integers
    static int calcGcd(int x, int y) {
        if (y == 0) {
            return x;
        } else if (x >= y) {
            return calcGcd(y, x % y);
        } else {
            return calcGcd(x, y % x);
        }
    }

    // Function to get all divisors of a number
    static List<Integer> getDivisor(int n) {
        Set<Integer> divisor = new HashSet<>();
        divisor.add(1);
        if (n != 1) {
            divisor.add(n);
        }

        int sqrt = (int) Math.sqrt(n);
        for (int i = 2; i <= sqrt; i++) {
            if (n % i == 0) {
                divisor.add(i);
                divisor.add(n / i);
            }
        }

        List<Integer> divisorArray = new ArrayList<>(divisor);
        Collections.sort(divisorArray);
        return divisorArray;
    }

    // Custom heap type for integers
    static class IntHeap {
        private List<Integer> heap;

        IntHeap() {
            this.heap = new ArrayList<>();
        }

        void push(int n) {
            heap.add(n);
            int i = heap.size() - 1;
            while (i > 0) {
                int parent = (i - 1) / 2;
                if (heap.get(parent) <= heap.get(i)) break;
                Collections.swap(heap, parent, i);
                i = parent;
            }
        }

        int pop() {
            if (heap.isEmpty()) throw new NoSuchElementException();
            int ret = heap.get(0);
            int n = heap.size();
            heap.set(0, heap.get(n - 1));
            heap.remove(n - 1);
            int i = 0;
            while (true) {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                if (left >= heap.size()) break;
                int smaller = (right < heap.size() && heap.get(right) < heap.get(left)) ? right : left;
                if (heap.get(i) <= heap.get(smaller)) break;
                Collections.swap(heap, i, smaller);
                i = smaller;
            }
            return ret;
        }

        boolean isEmpty() {
            return heap.isEmpty();
        }
    }

    // Function to calculate factorial modulo mod
    static int factMod(int n) {
        int value = 1;
        for (; n > 1; n--) {
            value = (int) ((value * n) % mod);
        }
        return value;
    }

    // Function to calculate combinations modulo mod
    static int combinationMod(int n, int k) {
        int factN = factMod(n);
        int factK = factMod(k);
        int factNK = factMod(n - k);
        int factKR = powMod(factK, (int) (mod - 2));
        int factNKR = powMod(factNK, (int) (mod - 2));
        return (int) ((factN * ((long) factKR * factNKR % mod)) % mod);
    }

    // Function to find prime factors of a number
    static List<Integer> primeFactors(int n) {
        List<Integer> factors = new ArrayList<>();
        int i = 2;
        while (i * i <= n) {
            int r = n % i;
            if (r != 0) {
                i += 1;
            } else {
                n /= i;
                factors.add(i);
            }
        }
        if (n > 1) {
            factors.add(n);
        }
        return factors;
    }

