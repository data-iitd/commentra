import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int a, b, c, k;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        a = scanner.nextInt(); // Read integer a
        b = scanner.nextInt(); // Read integer b
        c = scanner.nextInt(); // Read integer c
        k = scanner.nextInt(); // Read integer k

        // Generate all possible patterns of length k where each element is one of 0, 1, 2, or 3.
        List<List<Integer>> patterns = duplicatePatterns(new int[]{0, 1, 2, 3}, k);

        // Iterate through each pattern to check the condition.
        for (List<Integer> P : patterns) {
            long r = a, g = b, bValue = c; // Initialize r, g, and b with a, b, and c respectively.
            for (int i = 0; i < P.size(); i++) {
                if (P.get(i) == 0) {
                    continue; // If the operation is 0, do nothing.
                } else if (P.get(i) == 1) {
                    r *= 2; // Double the value of r.
                } else if (P.get(i) == 2) {
                    g *= 2; // Double the value of g.
                } else if (P.get(i) == 3) {
                    bValue *= 2; // Double the value of b.
                }
            }

            // Check if the condition b > a and c > b is met.
            if (g > r && bValue > g) {
                System.out.println("Yes"); // Print "Yes" if the condition is met.
                return;
            }
        }
        System.out.println("No"); // Print "No" if no pattern meets the condition.
    }

    // DuplicatePatterns generates all patterns of n^k of elems.
    static List<List<Integer>> duplicatePatterns(int[] elems, int k) {
        return dupliRec(new ArrayList<>(), elems, k);
    }

    // DFS function for DuplicatePatterns.
    static List<List<Integer>> dupliRec(List<Integer> pattern, int[] elems, int k) {
        List<List<Integer>> res = new ArrayList<>();
        if (pattern.size() == k) {
            res.add(new ArrayList<>(pattern)); // Return the pattern if its length equals k.
            return res;
        }

        for (int e : elems) {
            List<Integer> newPattern = new ArrayList<>(pattern);
            newPattern.add(e); // Add the current element to the pattern.
            res.addAll(dupliRec(newPattern, elems, k)); // Recursively generate patterns.
        }

        return res;
    }
}

/* <END-OF-CODE> */
