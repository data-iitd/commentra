package main;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Initialize input reader
        Io io = new Io();
        // Read the number of characters
        int n = io.nextInt();
        // Map to count occurrences of specific characters
        Map<Character, Integer> dic = new HashMap<>();

        // Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
        for (int i = 0; i < n; i++) {
            char c = io.nextString().charAt(0); // Read the first character of the string
            switch (c) {
                case 'M':
                    dic.put(c, dic.getOrDefault(c, 0) + 1);
                    break;
                case 'A':
                    dic.put(c, dic.getOrDefault(c, 0) + 1);
                    break;
                case 'R':
                    dic.put(c, dic.getOrDefault(c, 0) + 1);
                    break;
                case 'C':
                    dic.put(c, dic.getOrDefault(c, 0) + 1);
                    break;
                case 'H':
                    dic.put(c, dic.getOrDefault(c, 0) + 1);
                    break;
            }
        }

        // Start the DFS to calculate the product of combinations of 3 characters
        dfs(3, 0, 1, dic);
        // Print the final result
        System.out.println(ans);
    }

    // Struct to handle input operations
    static class Io {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public Io() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
        }

        // Method to read the next line of input
        public String nextLine() throws IOException {
            return reader.readLine();
        }

        // Method to read the next string token from input
        public String nextString() throws IOException {
            while (tokenizer == null ||!tokenizer.hasMoreTokens()) {
                String line = reader.readLine();
                if (line == null) {
                    throw new IOException();
                }
                tokenizer = new StringTokenizer(line);
            }
            return tokenizer.nextToken();
        }

        // Method to read the next integer from input
        public int nextInt() throws IOException {
            return Integer.parseInt(nextString());
        }
    }

    // Depth-first search function to calculate combinations
    static void dfs(int left, int i, int res, Map<Character, Integer> dic) {
        // If no more characters left to choose, add the result to ans
        if (left == 0) {
            ans += res;
            return;
        }
        // Iterate through the map starting from index i
        for (int j = i; j < dic.size(); j++) {
            // Recursive call to dfs with one less character to choose
            dfs(left - 1, j + 1, res * dic.get(j), dic);
        }
    }

    // Global variables to store counts and the result
    static int ans = 0;
    static List<Integer> a = new ArrayList<>();
}

