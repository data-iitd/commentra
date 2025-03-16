import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final int N = 200010;
    static long[] a = new long[N];
    static long[] q = new long[N];
    static long tot = 0;

    // Function to read input
    static long read() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLong();
    }

    // Function to write output
    static void writeln(long x) {
        System.out.println(x);
    }

    public static void main(String[] args) {
        // Reading input
        long n = read();

        // Reading array 'a'
        for (long i = 1; i <= n; i++) {
            a[(int) i] = read();
        }

        // Sorting array 'a' in ascending order
        Arrays.sort(a, 1, (int) (n + 1));

        // Finding duplicate elements and storing them in 'q'
        for (long i = 1; i <= n; i++) {
            if (a[(int) i] == a[(int) (i + 1)]) {
                q[(int) ++tot] = a[(int) i];
                i++; // Incrementing index 'i'
            }
        }

        // Outputting the result
        writeln(q[(int) tot] * q[(int) (tot - 1)]);
    }
}
// <END-OF-CODE>
