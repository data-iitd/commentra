
import java.io.*;
import java.util.*;

public class atcoder_ARC086_B{
    public static void main(String[] args) throws IOException {
        // Set the recursion limit to a higher value to handle deep recursions
        int recursionLimit = 1000000;
        while (Thread.activeCount() > recursionLimit) {
            Thread.yield();
        }

        // Define a modulo constant for later use
        int mod = 100000007;

        // Function to read a line of input and strip the newline character
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        // Function to read an integer from input
        int I() throws IOException {
            return Integer.parseInt(br.readLine());
        }

        // Function to read a list of integers from input
        int[] II() throws IOException {
            st = new StringTokenizer(br.readLine());
            int[] arr = new int[st.countTokens()];
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            return arr;
        }

        // Function to read a specific format of input based on the number of elements
        int[][] Line(int N, int num) throws IOException {
            // If N is less than or equal to 0, return an empty list
            if (N <= 0) {
                return new int[num][0];
            }
            // If num is 1, read N integers and return them as a list
            else if (num == 1) {
                int[] arr = new int[N];
                st = new StringTokenizer(br.readLine());
                for (int i = 0; i < N; i++) {
                    arr[i] = Integer.parseInt(st.nextToken());
                }
                return new int[][]{arr};
            }
            // Otherwise, read N tuples of integers and return them as a transposed list
            else {
                int[][] arr = new int[num][N];
                for (int i = 0; i < N; i++) {
                    st = new StringTokenizer(br.readLine());
                    for (int j = 0; j < num; j++) {
                        arr[j][i] = Integer.parseInt(st.nextToken());
                    }
                }
                return arr;
            }
        }

        // Function to determine the sign of a number
        int my_sign(int x) {
            return (x > 0)? 1 : (x < 0)? -1 : 0;
        }

        // Read the number of elements
        int N = I();

        // Read the list of integers
        int[] a = II();

        // Initialize variables to track the maximum absolute value, its sign, and index
        int max_val = 0, max_sign = 0, max_index = -1;

        // Loop through the list to find the maximum absolute value and its properties
        for (int i = 0; i < N; i++) {
            int a0 = a[i];
            if (Math.abs(a0) > max_val) {
                max_val = Math.abs(a0);
                max_sign = my_sign(a0);
                max_index = i;
            }
        }

        // Check the sign of the maximum value and print results accordingly
        if (max_sign == 0) {
            // If the maximum sign is zero, print 0
            System.out.println(0);
        } else if (max_sign == 1) {
            // If the maximum sign is positive, print the number of operations and the operations
            System.out.println(2 * N - 1);
            for (int i = 0; i < N; i++) {
                System.out.println((max_index + 1) + " " + (i + 1));
            }
            for (int i = 0; i < N - 1; i++) {
                System.out.println((i + 1) + " " + (i + 2));
            }
        } else {
            // If the maximum sign is negative, print the number of operations and the operations
            System.out.println(2 * N - 1);
            for (int i = 0; i < N; i++) {
                System.out.println((max_index + 1) + " " + (i + 1));
            }
            for (int i = N - 1; i > 0; i--) {
                System.out.println((i + 1) + " " + i);
            }
        }
    }
}

Translate the above Java code to C++ and end with comment "