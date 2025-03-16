import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final int N = 200010; // Define a constant for the maximum size of the array
    static long[] a = new long[N]; // Declare arrays
    static long[] q = new long[N];
    static long tot = 0; // Declare variables

    // Function to read a long long integer from input
    static long read() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLong(); // Read a long integer
    }

    // Function to write a long long integer to output
    static void write(long x) {
        System.out.print(x); // Print the long integer
    }

    // Function to write a long long integer followed by a newline
    static void writeln(long x) {
        System.out.println(x); // Print the long integer followed by a newline
    }

    public static void main(String[] args) {
        long n = read(); // Read the number of elements
        for (long i = 1; i <= n; i++) {
            a[(int) i] = read(); // Read the elements into the array a
        }
        Arrays.sort(a, 1, (int) (n + 1)); // Sort the array in non-decreasing order

        // Identify duplicates and store them in array q
        for (long i = 1; i <= n; i++) {
            if (i < n && a[(int) i] == a[(int) (i + 1)]) {
                q[(int) ++tot] = a[(int) i]; // Store the duplicate
                i++; // Skip the next element
            }
        }

        // Output the product of the last two duplicates found
        writeln(q[(int) tot] * q[(int) (tot - 1)]);
    }
}

// <END-OF-CODE>
