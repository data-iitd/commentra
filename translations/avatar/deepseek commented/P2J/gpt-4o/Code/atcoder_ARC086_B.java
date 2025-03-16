import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int N = I();  // Read the number of elements
        int[] a = III(N);  // Read the list of elements

        int maxVal = 0;  // Initialize the maximum value to 0
        int maxSign = 0;  // Initialize the sign of the maximum value to 0
        int maxIndex = -1;  // Initialize the index of the maximum value to -1

        // Find the element with the maximum absolute value
        for (int i = 0; i < N; i++) {
            int a0 = a[i];
            if (Math.abs(a0) > maxVal) {
                maxVal = Math.abs(a0);
                maxSign = mySign(a0);
                maxIndex = i;
            }
        }

        // If the maximum value is zero, print 0
        if (maxSign == 0) {
            System.out.println(0);
        }
        // If the maximum value is positive, print the sequence of operations
        else if (maxSign == 1) {
            System.out.println(2 * N - 1);
            for (int i = 0; i < N; i++) {
                System.out.println((maxIndex + 1) + " " + (i + 1));  // Print the swap operations
            }
            for (int i = 0; i < N - 1; i++) {
                System.out.println((i + 1) + " " + (i + 2));  // Print the increment operations
            }
        }
        // If the maximum value is negative, print the sequence of operations in reverse
        else {
            System.out.println(2 * N - 1);
            for (int i = 0; i < N; i++) {
                System.out.println((maxIndex + 1) + " " + (i + 1));  // Print the swap operations
            }
            for (int i = N - 2; i >= 0; i--) {
                System.out.println((i + 2) + " " + (i + 1));  // Print the decrement operations in reverse
            }
        }
    }

    static int I() throws IOException {
        return Integer.parseInt(br.readLine());  // Function to read an integer input
    }

    static int[] III(int N) throws IOException {
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());  // Read N integers
        }
        return arr;
    }

    static int mySign(int x) {
        return (x > 0) ? 1 : (x < 0) ? -1 : 0;  // Function to determine the sign of a number
    }
}
// <END-OF-CODE>
