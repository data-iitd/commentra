
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    // Scanner instance for reading input
    private static final BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));
    // List of patterns
    private static final List<int[]> PATTERNS = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        // Read input values
        int a = Integer.parseInt(READER.readLine());
        int b = Integer.parseInt(READER.readLine());
        int c = Integer.parseInt(READER.readLine());
        int k = Integer.parseInt(READER.readLine());

        // Generate all possible patterns of length k from the given array [0, 1, 2, 3]
        generatePatterns(new int[k], 0);

        // Check each generated pattern
        for (int[] P : PATTERNS) {
            // Apply bitwise operation to RGB values of the given input
            int r = a, g = b, b = c;
            for (int i = 0; i < P.length; i++) {
                if (P[i] == 0) {
                    continue;
                } else if (P[i] == 1) {
                    r *= 2;
                } else if (P[i] == 2) {
                    g *= 2;
                } else if (P[i] == 3) {
                    b *= 2;
                }
            }

            // Check if the result satisfies the condition g > r and b > g
            if (g > r && b > g) {
                System.out.println("Yes");
                return;
            }
        }

        // If all patterns are checked and no satisfying pattern is found, print "No"
        System.out.println("No");
    }

    // Generate all possible patterns of n^k of elems(int[]).
    private static void generatePatterns(int[] pattern, int index) {
        if (index == pattern.length) {
            // Add the generated pattern to the list
            PATTERNS.add(pattern);
            return;
        }

        for (int i = 0; i < 4; i++) {
            // Create a new pattern by appending the current element to the current pattern
            int[] newPattern = new int[pattern.length + 1];
            System.arraycopy(pattern, 0, newPattern, 0, pattern.length);
            newPattern[pattern.length] = i;

            // Recursively call the function with the new pattern and the remaining elements
            generatePatterns(newPattern, index + 1);
        }
    }
}

