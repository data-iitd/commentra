import java.util.*;

public class Main {
    // Function to sort in ascending order
    static int upll(Object a, Object b) {
        return ((Long)a).compareTo((Long)b);
    }

    // Function to sort in descending order
    static int downll(Object a, Object b) {
        return ((Long)b).compareTo((Long)a);
    }

    // Function to sort an array of long long values in ascending order using Arrays.sort
    static void sortup(long[] a) {
        Arrays.sort(a, upll);
    }

    // Function to sort an array of long long values in descending order using Arrays.sort
    static void sortdown(long[] a) {
        Arrays.sort(a, downll);
    }

    // Function to perform modular exponentiation
    static long pom(long a, long n, long m) {
        long x = 1;
        a %= m;
        for (; n; n >>= 1) {
            if ((n & 1)!= 0) x = (x * a) % m;
            a = (a * a) % m;
        }
        return x;
    }

    // Function to compute the modular multiplicative inverse
    static long invp(long a, long p) {
        return pom(a, p - 2, p);
    }

    // Function to sort edges based on the string and then by the long long value
    static int esort(Object a, Object b) {
        E p = (E)a, q = (E)b;
        int cmp = p.s.compareTo(q.s);
        if (cmp!= 0) return cmp;
        if (p.p < q.p) return -1;
        return 1;
    }

    // Main function
    public static void main(String[] args) {
        // Read the number of edges
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();

        // Read each edge's string and long long value, and store the index
        E[] data = new E[(int)n];
        for (long i = 0; i < n; i++) {
            data[(int)i] = new E();
            data[(int)i].s = sc.next();
            data[(int)i].p = sc.nextLong();
            data[(int)i].i = (int)i;
        }

        // Sort the edges using Arrays.sort and the custom esort function
        Arrays.sort(data, esort);

        // Print the indices of the edges in the sorted order
        for (long i = 0; i < n; i++) System.out.println(data[(int)i].i + 1);
    }
}
