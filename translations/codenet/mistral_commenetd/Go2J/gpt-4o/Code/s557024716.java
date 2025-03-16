import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int a, b, c, k;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input values
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        k = scanner.nextInt();

        // Generate all possible patterns of length k from the given array [0, 1, 2, 3]
        List<List<Integer>> patterns = duplicatePatterns(new int[]{0, 1, 2, 3}, k);

        // Check each generated pattern
        for (List<Integer> P : patterns) {
            // Apply bitwise operation to RGB values of the given input
            int r = a, g = b, b = c;
            for (int i = 0; i < P.size(); i++) {
                if (P.get(i) == 0) {
                    continue;
                } else if (P.get(i) == 1) {
                    r *= 2;
                } else if (P.get(i) == 2) {
                    g *= 2;
                } else if (P.get(i) == 3) {
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

    // DuplicatePatterns returns all patterns of n^k of elems.
    public static List<List<Integer>> duplicatePatterns(int[] elems, int k) {
        return dupliRec(new ArrayList<>(), elems, k);
    }

    // DFS function for DuplicatePatterns.
    public static List<List<Integer>> dupliRec(List<Integer> pattern, int[] elems, int k) {
        List<List<Integer>> res = new ArrayList<>();
        if (pattern.size() == k) {
            // Return the generated pattern as a list
            res.add(new ArrayList<>(pattern));
            return res;
        }

        for (int e : elems) {
            // Create a new pattern by appending the current element to the current pattern
            List<Integer> newPattern = new ArrayList<>(pattern);
            newPattern.add(e);

            // Recursively call the function with the new pattern and the remaining elements
            List<List<Integer>> subPatterns = dupliRec(newPattern, elems, k);

            // Append the sub-patterns to the result
            res.addAll(subPatterns);
        }

        return res;
    }
}

// <END-OF-CODE>
