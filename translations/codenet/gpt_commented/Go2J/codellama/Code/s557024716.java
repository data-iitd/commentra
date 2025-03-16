
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    // Variables for input
    private static int a, b, c, k;

    public static void main(String[] args) {
        // Read three integers and the number of patterns
        a = readInt();
        b = readInt();
        c = readInt();
        k = readInt();

        // Generate all possible patterns of length k from the set {0, 1, 2, 3}
        List<Integer>[] patterns = generatePatterns(new int[] {0, 1, 2, 3}, k);

        // Iterate through each generated pattern
        for (List<Integer> P : patterns) {
            int r = a, g = b, b_ = c; // Initialize color values for each pattern
            // Apply the pattern to modify the color values
            for (int i = 0; i < P.size(); i++) {
                if (P.get(i) == 0) {
                    continue; // Skip if the pattern element is 0
                } else if (P.get(i) == 1) {
                    r *= 2; // Double the red value
                } else if (P.get(i) == 2) {
                    g *= 2; // Double the green value
                } else if (P.get(i) == 3) {
                    b_ *= 2; // Double the blue value
                }
            }

            // Check if the modified values satisfy the condition
            if (g > r && b_ > g) {
                System.out.println("Yes"); // Print "Yes" if the condition is met
                return;
            }
        }
        System.out.println("No"); // Print "No" if no pattern satisfies the condition
    }

    // Generate all possible patterns of length k from the given elements
    private static List<Integer>[] generatePatterns(int[] elems, int k) {
        return generatePatternsRec(new ArrayList<>(), elems, k); // Start the recursive pattern generation
    }

    // Recursive function to generate patterns
    private static List<Integer>[] generatePatternsRec(List<Integer> pattern, int[] elems, int k) {
        if (pattern.size() == k) {
            return new List[] {pattern}; // Return the completed pattern
        }

        List<Integer>[] res = new ArrayList[0]; // Slice to hold the results
        // Iterate through each element to build patterns
        for (int e : elems) {
            List<Integer> newPattern = new ArrayList<>(pattern); // Copy the existing pattern
            newPattern.add(e); // Append the new element

            // Recursively generate patterns with the new element added
            res = append(res, generatePatternsRec(newPattern, elems, k));
        }

        return res; // Return all generated patterns
    }

    // Append two lists of lists
    private static List<Integer>[] append(List<Integer>[] a, List<Integer>[] b) {
        List<Integer>[] res = new ArrayList[a.length + b.length]; // Slice to hold the results
        for (int i = 0; i < a.length; i++) {
            res[i] = a[i]; // Copy the first list
        }
        for (int i = 0; i < b.length; i++) {
            res[i + a.length] = b[i]; // Copy the second list
        }
        return res; // Return the appended lists
    }

    // Read an integer from input
    private static int readInt() {
        try {
            return Integer.parseInt(br.readLine());
        } catch (IOException e) {
            e.printStackTrace();
            return -1;
        }
    }

    // BufferedReader for reading input
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
}

