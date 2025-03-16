import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st;

    // Function to read an integer from standard input
    static int ii1() throws IOException {
        return Integer.parseInt(br.readLine().trim());
    }

    // Function to read a string from standard input
    static String is1() throws IOException {
        return br.readLine().trim();
    }

    // Function to read a list of integers from standard input
    static int[] iia() throws IOException {
        String[] s = br.readLine().trim().split(" ");
        int[] arr = new int[s.length];
        for (int i = 0; i < s.length; i++) {
            arr[i] = Integer.parseInt(s[i]);
        }
        return arr;
    }

    // Function to read a list of strings from standard input
    static String[] isa() throws IOException {
        return br.readLine().trim().split(" ");
    }

    public static void main(String[] args) throws IOException {
        // Read the value of k from standard input
        int k = ii1();

        // Initialize a variable t to 0
        int t = 0;

        // Loop from 1 to k
        for (int i = 1; i <= k; i++) {
            // Calculate the value of t using the current value of i and k
            t = ( (t % k) * 10 + 7 ) % k;
            
            // Check if t is a multiple of k
            if (t == 0) {
                // Print the value of i and break out of the loop
                System.out.println(i);
                break;
            }
        }

        // If the loop completes without finding a multiple of k, print -1
        if (t != 0) {
            System.out.println(-1);
        }
    }
}
