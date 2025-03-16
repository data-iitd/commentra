import java.util.*;

public class Main {
    // Function to read an integer from input
    static int read() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    // Function to write an integer to output
    static void write(int x) {
        System.out.print(x);
    }

    // Function to write an integer followed by a newline
    static void writeln(int x) {
        System.out.println(x);
    }

    public static void main(String[] args) {
        int n = read(); // Read the number of elements
        int[] a = new int[200010]; // Declare the array
        for (int i = 1; i <= n; i++) {
            a[i] = read(); // Read the elements into the array a
        }
        Arrays.sort(a, 1, n + 1); // Sort the array in non-decreasing order

        int[] q = new int[200010]; // Declare the array for duplicates
        int tot = 0; // Initialize the total number of duplicates

        // Identify duplicates and store them in array q
        for (int i = 1; i <= n; i++) {
            if (a[i] == a[i + 1]) {
                q[++tot] = a[i];
                i++; // Skip the next element
            }
        }

        // Output the product of the last two duplicates found
        writeln(q[tot] * q[tot - 1]);
    }
}
