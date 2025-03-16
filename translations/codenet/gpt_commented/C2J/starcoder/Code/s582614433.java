
import java.util.*;

public class Main {
    // Define long long type for convenience
    static long long ll;

    // Macro for iterating from l to r
    #define rep(i,l,r) for(ll i=(l);i<(r);i++)

    // Macro for iterating from l to r with step k
    #define repp(i,l,r,k) for(ll i=(l);i<(r);i+=(k))

    // Define a large constant for infinity
    static final long long INF = (1LL<<62)-(1LL<<31);

    // Macro to get the maximum of two values
    #define max(p,q) ((p)>(q)?(p):(q))

    // Macro to get the minimum of two values
    #define min(p,q) ((p)<(q)?(p):(q))

    // Macro to check the bit at position m in n
    #define bit(n,m) (((n)>>(m))&1)

    // Comparison function for sorting in ascending order
    static int upll(Object a, Object b) {
        return ((Long)a).compareTo((Long)b);
    }

    // Comparison function for sorting in descending order
    static int downll(Object a, Object b) {
        return ((Long)b).compareTo((Long)a);
    }

    // Function to sort an array in ascending order
    static void sortup(long long[]a, int n) {
        Arrays.sort(a, 0, n, upll);
    }

    // Function to sort an array in descending order
    static void sortdown(long long[]a, int n) {
        Arrays.sort(a, 0, n, downll);
    }

    // Function to compute (a^n) % m using modular exponentiation
    static long long pom(long long a, long long n, int m) {
        long long x = 1; // Initialize result
        for (a %= m; n; n /= 2) { // Loop until n is zero
            n & 1? x = x * a % m : 0; // If n is odd, multiply x by a
            a = a * a % m; // Square a
        }
        return x; // Return the result
    }

    // Define a large prime number for modulo operations
    static final int MOD = 1000000007;

    // Macro to compute modular inverse using Fermat's little theorem
    #define invp(a,p) pom(a,p-2,p)

    // Structure to hold edge information
    static class E {
        long long p; // Weight or value associated with the edge
        long long i; // Index of the edge
        String s; // Name or identifier of the edge
    }

    // Comparison function for sorting edges
    static int esort(Object a, Object b) {
        E p = (E)a, q = (E)b;
        // First compare by string identifier
        if (p.s.compareTo(q.s)!= 0) return p.s.compareTo(q.s);
        // If identifiers are the same, compare by weight in descending order
        if (p.p < q.p) return 1;
        return -1; // Otherwise, return -1 for sorting
    }

    // Array to hold edge data
    static E[] data = new E[100];
    static long long n, m; // Variables to hold the number of edges and other data

    public static void main(String[] args) {
        // Read the number of edges
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();
        
        // Read edge data from input
        rep(i, 0, n) {
            data[i] = new E();
            data[i].s = sc.next(); // Read string
            data[i].p = sc.nextLong(); // Read weight
            data[i].i = i; // Store the original index
        }
        
        // Sort the edges based on the defined sorting criteria
        Arrays.sort(data, 0, (int)n, esort);
        
        // Output the original indices of the sorted edges
        rep(i, 0, n) System.out.println(data[i].i + 1);
    }
}

