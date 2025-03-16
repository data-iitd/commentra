
package main

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        // Initialize input reader
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        // Initialize memoization array
        int[] memo = new int[26];

        // Read input
        String str;
        while (true) {
            try {
                str = reader.readLine();
            } catch (Exception e) {
                throw new RuntimeException(e);
            }

            if (str.length() == 0) {
                break;
            }

            // Process input
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);

                if (c >= 'a' && c <= 'z') {
                    // toUpper
                    // c-('a'-'A')
                    memo[c - 'a']++;
                } else if (c >= 'A' && c <= 'Z') {
                    // toLower
                    // c+('a'-'A')
                    memo[c - 'A']++;
                } else {
                    // stay
                    // c
                    continue;
                }
            }
        }

        // Print results
        for (int i = 0; i < 26; i++) {
            System.out.println((char) (i + 'a') + " : " + memo[i]);
        }
    }
}

// Initialize input reader
// The code initializes an input reader to read input from the standard input.
// This is a common setup for competitive programming in Java.

// Initialize memoization array
// The code initializes a memoization array to store counts of each letter.
// This is a common technique in competitive programming to optimize repeated calculations.

// Read input
// The code reads input from the input reader and stores it in a string variable.
// This is a common structure for programs that need to handle multiple inputs.

// Process input
// The code processes the input string by iterating over each character and updating the memoization array.
// This is a common technique in competitive programming to optimize repeated calculations.

// Print results
// The code prints the results by iterating over the memoization array and printing the counts of each letter.
// This is a common technique in competitive programming to output the results.

// 