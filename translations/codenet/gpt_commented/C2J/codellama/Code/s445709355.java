
// ABC 152-D
// 2020.1.19 bal4u

import java.io.*;
import java.util.*;

// Fast input function to read a character from standard input
class FastReader {
    BufferedReader br;
    StringTokenizer st;

    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }
}

// Function to calculate frequency counts based on the input number
void calc(int n) {
    int k = n % 10; // Extract the last digit of n
    // Reduce n to its first digit by continuously dividing by 10
    while (n >= 10) n /= 10;
    // Update frequency counts for combinations of first and last digits
    ++f1[10*k + n], ++f2[n*10 + k];
}

// Arrays to store frequency counts for two different calculations
int f1[] = new int[100], f2[] = new int[100];

public class Main {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int i, N, ans; // Declare variables for iteration, input number, and answer
        
        // Read the total number of inputs
        N = sc.nextInt();
        // Process each number from N down to 1
        while (N > 0) calc(N--);

        ans = 0; // Initialize answer to 0
        // Calculate the final answer by summing the products of corresponding frequencies
        for (i = 0; i < 100; ++i) ans += f1[i] * f2[i];
        // Output the final answer
        System.out.println(ans);
    }
}

