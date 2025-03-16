
import java.util.*;
import java.io.*;

public class atcoder_ABC174_C{
    public static void main(String[] args) throws IOException {
        // Initialize the input and output streams
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        // Read the integer k from input
        int k = Integer.parseInt(br.readLine());

        // Initialize a variable to hold the current value of t
        int t = 0;

        // Loop through numbers from 1 to k
        for (int i = 1; i <= k; i++) {
            // Update t by appending a '7' at the end and taking modulo k
            t = (t % k) * 10 + 7;

            // Check if the current value of t is divisible by k
            if (t % k == 0) {
                // Print the current index if divisible
                pw.println(i);
                break;
            }
        }

        // If no index was found, print -1
        if (t % k!= 0) {
            pw.println(-1);
        }

        // Close the input and output streams
        pw.close();
    }
}

Translate the above Java code to C++ and end with comment "