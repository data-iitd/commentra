import java.util.*;
import java.io.*;

public class Main {
    // Define the modulus value
    static final int MOD = 1000000007;

    // Function to read an integer input
    static int I() throws IOException {
        return Integer.parseInt(input());
    }

    // Function to read a list of integers as input
    static int[] III() throws IOException {
        String[] parts = input().split(" ");
        int[] arr = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            arr[i] = Integer.parseInt(parts[i]);
        }
        return arr;
    }

    // Function to read input from standard input
    static String input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return br.readLine();
    }

    // Function to determine the sign of a number
    static int mySign(int x) {
        return Integer.compare(x, 0);
    }

    public static void main(String[] args) throws IOException {
        // Initialize variables
        int N = I();
        int[] a = III();
        int maxVal = 0;
        int maxSign = 0;
        int maxIndex = -1;

        // Iterate through the list 'a' to find the maximum absolute value and its sign
        for (int i = 0; i < N; i++) {
            int a0 = a[i];
            // Update the maximum value and its sign if the current value is greater
            if (Math.abs(a0) > maxVal) {
                maxVal = Math.abs(a0);
                maxSign = mySign(a0);
                maxIndex = i;
            }
        }

        // Determine the output based on the sign of the maximum value
        if (maxSign == 0) {
            // If the maximum value is zero, print zero
            System.out.println(0);
        } else {
            // If the maximum value is positive or negative, print the required output
            System.out.println(2 * N - 1);
            // Print the indices of the maximum value and the first element
            System.out.println((maxIndex + 1) + " " + 1);
            // Print the indices of the other elements in pairs
            if (maxSign == 1) {
                for (int i = 1; i < N; i++) {
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
