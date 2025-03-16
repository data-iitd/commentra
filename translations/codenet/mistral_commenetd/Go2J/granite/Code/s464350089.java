
// Constants and package imports
import java.util.Scanner;

public class s464350089{
    public static void main(String[] args) {
        // Constants and package imports
        final int MOD = 1000000007;
        // 1MB
        final int IO_BUFFER_SIZE = 1 * 1024 * 1024;

        // Helper function to read input
        Scanner sc = new Scanner(System.in);
        sc.useDelimiter("\\A");

        // Helper functions to read input as a word and an integer
        String next() {
            sc.next();
            return sc.next();
        }

        int nextInt() {
            sc.next();
            return Integer.parseInt(sc.next());
        }

        // Reading the first two integers h and n
        int h = nextInt();
        int n = nextInt();

        // Initializing variable a to 0
        int a = 0;

        // Iterating through the array of size n and adding each integer to variable a
        for (int i = 0; i < n; i++) {
            a += nextInt();
        }

        // Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
        if (h > a) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}

