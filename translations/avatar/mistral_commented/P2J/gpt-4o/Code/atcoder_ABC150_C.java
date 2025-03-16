import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class PermutationDifference {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask the user for the size of the permutation list
        int n = scanner.nextInt();

        // Create a list of all possible permutations of numbers from 1 to n
        List<List<Integer>> orig = new ArrayList<>();
        generatePermutations(new ArrayList<>(), orig, n);

        // Ask the user for two permutations as tuples
        List<Integer> p = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            p.add(scanner.nextInt());
        }
        List<Integer> q = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            q.add(scanner.nextInt());
        }

        // Find the indices of p and q in the orig list
        int pn = orig.indexOf(p);
        int qn = orig.indexOf(q);

        // Print the absolute difference between the indices of p and q
        System.out.println(Math.abs(pn - qn));

        scanner.close();
    }

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
