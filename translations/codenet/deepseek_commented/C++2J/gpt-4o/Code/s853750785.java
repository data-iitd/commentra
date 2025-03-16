import java.util.*;

public class AtCoder {
    // Define constants
    static final long MOD = 1000000007;

    // Function to calculate the greatest common divisor (GCD)
    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    // Function to calculate the least common multiple (LCM)
    static long lcd(long a, long b) {
        if (b == 0) return a;
        return (a / gcd(a, b)) * b;
    }

    // Function to convert a string to a list of integers
    static List<Integer> convertString(String s) {
        List<Integer> d = new ArrayList<>();
        for (char c : s.toCharArray()) {
            d.add(c - '0');
        }
        return d;
    }

    // Function to find all divisors of a number
    static List<Long> divisor(long n) {
        List<Long> res = new ArrayList<>();
        for (long i = 1; i * i <= n; i++) {
            if (n % i != 0) continue;
            res.add(i);
            if (i * i != n) res.add(n / i);
        }
        return res;
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read number of nodes (N) and edges (M)
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        // Read heights of each node
        int[] H = new int[N];
        for (int i = 0; i < N; i++) {
            H[i] = scanner.nextInt();
        }

        // Read edges and build the graph
        List<List<Integer>> G = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            G.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            int u = scanner.nextInt() - 1; // Convert to 0-based indexing
            int v = scanner.nextInt() - 1; // Convert to 0-based indexing
            G.get(u).add(v);
            G.get(v).add(u);
        }

        long ans = 0; // Variable to count the number of nodes that are taller than all their neighbors

        // Iterate through each node to check if it is taller than all its neighbors
        for (int u = 0; u < N; u++) {
            boolean flag = true; // Flag to check if the current node is taller
            for (int v : G.get(u)) {
                if (H[u] <= H[v]) flag = false; // If any neighbor is taller or equal, set flag to false
            }
            if (flag) ans++; // If the flag is still true, increment the answer
        }

        // Output the result
        System.out.println(ans);
    }
}
// <END-OF-CODE>
