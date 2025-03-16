import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int a, b, c; // Variables to hold input values
    static int k; // Variable to hold the number of patterns

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers and the number of patterns
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        k = scanner.nextInt();

        // Generate all possible patterns of length k from the set {0, 1, 2, 3}
        List<List<Integer>> patterns = duplicatePatterns(new int[]{0, 1, 2, 3}, k);

        // Iterate through each generated pattern
        for (List<Integer> P : patterns) {
            int r = a, g = b, bl = c; // Initialize color values for each pattern
            // Apply the pattern to modify the color values
            for (int i = 0; i < P.size(); i++) {
                if (P.get(i) == 0) {
                    continue; // Skip if the pattern element is 0
                } else if (P.get(i) == 1) {
                    r *= 2; // Double the red value
                } else if (P.get(i) == 2) {
                    g *= 2; // Double the green value
                } else if (P.get(i) == 3) {
                    bl *= 2; // Double the blue value
                }
            }

            // Check if the modified values satisfy the condition
            if (g > r && bl > g) {
                System.out.println("Yes"); // Print "Yes" if the condition is met
                return;
            }
        }
        System.out.println("No"); // Print "No" if no pattern satisfies the condition
    }

    // DuplicatePatterns returns all patterns of length k from the given elements.
    static List<List<Integer>> duplicatePatterns(int[] elems, int k) {
        return dupliRec(new ArrayList<>(), elems, k); // Start the recursive pattern generation
    }

    // Recursive function to generate patterns
    static List<List<Integer>> dupliRec(List<Integer> pattern, int[] elems, int k) {
        List<List<Integer>> res = new ArrayList<>(); // List to hold the results
        if (pattern.size() == k) {
            res.add(new ArrayList<>(pattern)); // Return the completed pattern
            return res;
        }

        // Iterate through each element to build patterns
        for (int e : elems) {
            List<Integer> newPattern = new ArrayList<>(pattern); // Copy the existing pattern
            newPattern.add(e); // Append the new element

            // Recursively generate patterns with the new element added
            res.addAll(dupliRec(newPattern, elems, k));
        }

        return res; // Return all generated patterns
    }
}

/* <END-OF-CODE> */
