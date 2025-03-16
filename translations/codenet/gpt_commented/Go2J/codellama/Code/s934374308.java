
package com.company;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Declare variables for input values
        int N, K, R, S, P;
        String T;

        // Read input values: N (length of string), K (window size), R, S, P (points for each move)
        N = scanner.nextInt();
        K = scanner.nextInt();
        R = scanner.nextInt();
        S = scanner.nextInt();
        P = scanner.nextInt();
        T = scanner.next();

        // Initialize a dictionary to count occurrences of each move
        Map<String, Integer> dict = new HashMap<>();
        dict.put("r", 0);
        dict.put("s", 0);
        dict.put("p", 0);

        // Initialize a boolean array to track the state of each move within the last K moves
        boolean[] s = new boolean[N];
        boolean[] r = new boolean[N];
        boolean[] p = new boolean[N];

        // Initialize all moves as available (true)
        for (int i = 0; i < N; i++) {
            s[i] = true;
        }
        r = s.clone(); // Copy the initial state to r
        p = s.clone(); // Copy the initial state to p

        // Iterate through each character in the input string T
        for (int i = 0; i < T.length(); i++) {
            char char = T.charAt(i);

            // Check if we are within the bounds of K
            if (i >= K) {
                // If the current character is the same as the character K positions back
                if (char == T.charAt(i - K)) {
                    // Toggle the availability of the move based on the current character
                    switch (char) {
                        case 's':
                            if (s[i % K]) {
                                s[i % K] = false; // Mark 's' as used
                                continue;
                            } else {
                                s[i % K] = true; // Mark 's' as available again
                            }

                        case 'r':
                            if (r[i % K]) {
                                r[i % K] = false; // Mark 'r' as used
                                continue;
                            } else {
                                r[i % K] = true; // Mark 'r' as available again
                            }

                        case 'p':
                            if (p[i % K]) {
                                p[i % K] = false; // Mark 'p' as used
                                continue;
                            } else {
                                p[i % K] = true; // Mark 'p' as available again
                            }
                    }
                } else {
                    // If the current character is different from the character K positions back
                    switch (char) {
                        case 's':
                            s[i % K] = true; // Mark 's' as available
                        case 'r':
                            r[i % K] = true; // Mark 'r' as available
                        case 'p':
                            p[i % K] = true; // Mark 'p' as available
                    }
                }
            }

            // Count the occurrences of each move
            switch (char) {
                case 's':
                    dict.put("s", dict.get("s") + 1); // Increment count for 's'
                case 'r':
                    dict.put("r", dict.get("r") + 1); // Increment count for 'r'
                case 'p':
                    dict.put("p", dict.get("p") + 1); // Increment count for 'p'
            }
        }

        // Calculate the total score based on the counts and respective points
        int res = P * dict.get("r") + S * dict.get("p") + R * dict.get("s");

        // Print the final result
        System.out.println(res);
    }
}

