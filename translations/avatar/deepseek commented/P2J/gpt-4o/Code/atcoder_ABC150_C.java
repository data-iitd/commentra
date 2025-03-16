import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class PermutationIndexDifference {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();  // Take an integer input `n`
        List<List<Integer>> orig = new ArrayList<>();  // List to hold all permutations
        generatePermutations(new ArrayList<>(), orig, n);  // Generate all permutations
        
        // Read the first permutation `p`
        List<Integer> p = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            p.add(scanner.nextInt());
        }
        
        // Read the second permutation `q`
        List<Integer> q = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            q.add(scanner.nextInt());
        }
        
        int pn = orig.indexOf(p);  // Find the index of permutation `p`
        int qn = orig.indexOf(q);  // Find the index of permutation `q`
        
        System.out.println(Math.abs(pn - qn));  // Calculate the absolute difference and print the result
        
        scanner.close();
    }

    // Method to generate all permutations
    private static void generatePermutations(List<Integer> current, List<List<Integer>> result, int n) {
        if (current.size() == n) {
            result.add(new ArrayList<>(current));
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!current.contains(i)) {
                current.add(i);
                generatePermutations(current, result, n);
                current.remove(current.size() - 1);
            }
        }
    }
}
// <END-OF-CODE>
