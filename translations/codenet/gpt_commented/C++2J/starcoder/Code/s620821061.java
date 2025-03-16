import java.util.*;

public class Main {
    public static void main(String[] args) {
        while (true) {
            int n, m; // Number of elements in two sets
            Scanner sc = new Scanner(System.in);
            n = sc.nextInt();
            m = sc.nextInt();
            if (n == 0) break; // Exit if n is 0 (no more input)

            // Create an instance of BitMatching
            BitMatching<MN> bm = new BitMatching<MN>();
            bm.init(); // Initialize the BitMatching instance
            int[] a = new int[n]; // Arrays to hold the elements of the two sets
            int[] b = new int[m];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt(); // Read elements of the first set
            }
            for (int i = 0; i < m; i++) {
                b[i] = sc.nextInt(); // Read elements of the second set
            }

            // Build the bipartite graph based on the GCD condition
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (gcd(a[i], b[j])!= 1) { // If GCD is not 1, add an edge
                        bm.add(i, j);
                    }
                }
            }
            
            // Execute the matching algorithm and print the result
            System.out.println(bm.exec());
        }
    }

    /// Function to compute the greatest common divisor (GCD) of two numbers
    static int gcd(int a, int b) {
        if (b == 0) return a; // Base case: if b is 0, return a
        return gcd(b, a % b); // Recursive case: GCD of b and a mod b
    }
}

