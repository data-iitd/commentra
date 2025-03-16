
// Package main is the entry point of the program
package main

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize two empty strings S and T
        String S = ReadString();
        String T = ReadString();

        // Initialize max as 0
        int max = 0;

        // Loop through all possible substrings of S with length equal to T
        for (int i = 0; i <= S.length() - T.length(); i++) {
            // Initialize a counter c for the number of matching characters between S[i:i+len(T)] and T
            int c = 0;

            // Check character by character for matching characters
            for (int j = 0; j < T.length(); j++) {
                // If current characters match, increment counter c
                if (S.charAt(i + j) == T.charAt(j)) {
                    c++;
                }
            }

            // If current substring has more matching characters than the current max, update max
            if (max < c) {
                max = c;
            }
        }

        // Print the length of the shortest substring of S that matches T with all characters
        System.out.println(T.length() - max);
    }

    // Helper functions to read input from stdin
    private static Scanner reader = new Scanner(System.in);

    public static String ReadString() {
        // Function to read input and store it in the provided interface
        String s = reader.nextLine();
        return s;
    }

    public static int ReadInt() {
        // Function to read input and store it in the provided interface
        int i = reader.nextInt();
        return i;
    }

    public static int[] ReadInts(int n) {
        // Function to read n integers and return a slice
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            v[i] = reader.nextInt();
        }
        return v;
    }
}

