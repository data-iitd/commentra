import java.util.*;
import java.io.*;

public class Main {
    // Define a modulo constant for later use
    static final int MOD = 1000000007;

    // Function to read an integer from input
    static int I(BufferedReader br) throws IOException {
        return Integer.parseInt(br.readLine().trim());
    }

    // Function to read a list of integers from input
    static int[] III(BufferedReader br, int N) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        return arr;
    }

    // Function to determine the sign of a number
    static int mySign(int x) {
        return (x > 0) ? 1 : (x < 0) ? -1 : 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Read the number of elements
        int N = I(br);

        // Read the list of integers
        int[] a = III(br, N);

        // Initialize variables to track the maximum absolute value, its sign, and index
        int maxVal = 0;
        int maxSign = 0;
        int maxIndex = -1;

        // Loop through the list to find the maximum absolute value and its properties
        for (int i = 0; i < N; i++) {
            int a0 = a[i];
            if (Math.abs(a0) > maxVal) {
                maxVal = Math.abs(a0);
                maxSign = mySign(a0);
                maxIndex = i;
            }
        }

        // Check the sign of the maximum value and print results accordingly
        if (maxSign == 0) {
            // If the maximum sign is zero, print 0
            System.out.println(0);
        } else {
            // If the maximum sign is not zero, print the number of operations and the operations
            System.out.println(2 * N - 1);
            for (int i = 0; i < N; i++) {
                System.out.println((maxIndex + 1) + " " + (i + 1));
            }
            if (maxSign == 1) {
                for (int i = 0; i < N - 1; i++) {
                    System.out.println((i + 1) + " " + (i + 2));
                }
            } else {
                for (int i = N - 1; i > 0; i--) {
                    System.out.println((i + 1) + " " + i);
                }
            }
        }
    }
}
// <END-OF-CODE>
