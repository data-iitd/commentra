import java.io.*;
import java.util.*;

public class Main {
    // Global variables to store counts and the result
    static int[] a; // Array to hold counts of specific characters
    static int ans = 0; // Variable to hold the final answer

    // Depth-first search function to calculate combinations
    static void dfs(int left, int i, int res) {
        // If no more characters left to choose, add the result to ans
        if (left == 0) {
            ans += res;
            return;
        }
        // Iterate through the array starting from index i
        for (int j = i; j < a.length; j++) {
            // Recursive call to dfs with one less character to choose
            dfs(left - 1, j + 1, res * a[j]);
        }
    }

    public static void main(String[] args) throws IOException {
        // Initialize input reader
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken()); // Read the number of characters

        // Map to count occurrences of specific characters
        Map<Character, Integer> dic = new HashMap<>();

        // Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
        for (int i = 0; i < n; i++) {
            String line = reader.readLine();
            char c = line.charAt(0); // Read the first character of the string
            if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
                dic.put(c, dic.getOrDefault(c, 0) + 1); // Increment count for the character if it's one of the specified
            }
        }

        // Populate the array a with the counts from the dictionary
        a = new int[dic.size()];
        int index = 0;
        for (int value : dic.values()) {
            a[index++] = value;
        }

        // Start the DFS to calculate the product of combinations of 3 characters
        dfs(3, 0, 1);
        // Print the final result
        System.out.println(ans);
    }
}
