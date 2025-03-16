import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    // Define constants for the program.
    private static final int ALPHABET_NUM = 26;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder input = new StringBuilder();
        String line;

        // Read input until EOF.
        while ((line = reader.readLine()) != null) {
            input.append(line);
        }

        // Count occurrences of each letter.
        int[] memo = new int[ALPHABET_NUM];
        String str = input.toString();
        for (char c : str.toCharArray()) {
            if ('a' <= c && c <= 'z') {
                // Increment count for lowercase letters.
                memo[c - 'a']++;
            } else if ('A' <= c && c <= 'Z') {
                // Increment count for uppercase letters.
                memo[c - 'A']++;
            } else {
                // Ignore non-alphabet characters.
                continue;
            }
        }

        // Print the count of each letter.
        for (int i = 0; i < ALPHABET_NUM; i++) {
            System.out.printf("%c : %d\n", (char) (i + 'a'), memo[i]);
        }
    }
}

// <END-OF-CODE>
