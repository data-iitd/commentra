import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    // Initialize scanner for input and print stream for output
    static final Scanner sc = new Scanner(System.in);
    static final PrintStream so = System.out;

    public static void main(String[] args) {
        // Read the number of items (N) and the maximum weight (W)
        int N = nint();
        int W = nint();
        
        // Arrays to hold the values and weights of the items
        int[] v = new int[N+1]; // Value array
        int[] w = new int[N+1]; // Weight array
        
        // Read the values and weights for each item
        for (int i = 1; i <= N; i++) {
            v[i] = nint(); // Read value for item i
            w[i] = nint(); // Read weight for item i
        }
        
        // Create a 2D array to store the maximum value for each item and weight combination
        int[][] sumV = new int[N+1][W+1];
        
        // Dynamic programming to fill the sumV array
        for (int i = 1; i <= N; i++) {
            // Copy the values for weights less than the current item's weight
            for (int i_sum = 0; i_sum < w[i]; i_sum++) {
                sumV[i][i_sum] = sumV[i-1][i_sum];
            }
            
            // Calculate the maximum value for weights from the current item's weight to W
            for (int i_sum = w[i]; i_sum <= W; i_sum++) {
                sumV[i][i_sum] = Math.max(sumV[i-1][i_sum], sumV[i-1][i_sum-w[i]] + v[i]);
            }
        }
        
        // Output the maximum value that can be obtained with the given weight limit
        so.println(sumV[N][W]);
    }

    // Method to read a long integer from input
    private static long nlong() {
        return sc.nextLong();
    }

    // Method to read an integer from input
    private static int nint() {
        return sc.nextInt();
    }

    // Method to read a string from input
    private static String nstr() {
        return sc.next();
    }

    // Method to convert a string to a character array
    private static char[] nsToChars() {
        return sc.next().toCharArray();
    }

    // Method to read an array of long integers from input
    private static long[] nlongs(int n) {
        return nlongs(n, 0, 0);
    }

    // Method to read an array of integers from input
    private static int[] nints(int n) {
        return nints(n, 0, 0);
    }

    // Method to read an array of integers with optional padding
    private static int[] nints(int n, int padL, int padR) {
        int[] a = new int[padL + n + padR];
        for (int i = 0; i < n; i++)
            a[padL + i] = nint(); // Read each integer into the array
        return a;
    }

    // Method to read an array of long integers with optional padding
    private static long[] nlongs(int n, int padL, int padR) {
        long[] a = new long[padL + n + padR];
        for (int i = 0; i < n; i++)
            a[padL + i] = nlong(); // Read each long integer into the array
        return a;
    }

    // Method to read an array of strings from input
    private static String[] nstrs(int n) {
        String[] a = new String[n];
        for (int i = 0; i < n; i++)
            a[i] = nstr(); // Read each string into the array
        return a;
    }

    // Method to create a 2D character array from input
    private static char[][] nsToChars2D(int h, int w) {
        return nsToChars2D(h, w, 0);
    }

    // Method to create a 2D character array with optional padding
    private static char[][] nsToChars2D(int h, int w, int pad) {
        char[][] a2 = new char[h + pad * 2][w + pad * 2];
        for (int i = 0; i < h; i++)
            System.arraycopy(nsToChars(), 0, a2[pad + i], pad, w); // Fill the 2D array with characters
        return a2;
    }
}
