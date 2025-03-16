
import java.util.*;
import java.io.*;
import java.math.*;

// Functions to read input more efficiently
static class FastReader {
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

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}

// Main function to execute the program
public static void main(String[] args) {
    FastReader sc = new FastReader();
    String s = sc.nextLine();  // Read the input string
    int k = sc.nextInt();  // Read the integer k
    int l = 0;  // Initialize a counter for leading '1's
    for (int i = 0; i < s.length(); i++) {  // Loop through each character in the string
        if (s.charAt(i) != '1') {  // Check if the character is not '1'
            break;  // Exit the loop if a non-'1' character is found
        }
        l++;  // Increment the counter for each '1' found
    }
    if (l >= k) {  // Check if the number of leading '1's is greater than or equal to k
        System.out.println(1);  // Return 1 if true
    } else {
        System.out.println(s.charAt(l));  // Return the character at the position of the first non-'1' character
    }
}

