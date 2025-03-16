import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class PermutationDifference {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input n, which defines the range of numbers to permute
        int n = scanner.nextInt();
        
        // Generate all possible permutations of the numbers from 1 to n
        List<List<Integer>> orig = new ArrayList<>();
        permute(orig, new ArrayList<>(), n, new boolean[n + 1]);
        
        // Read the first permutation input as an array of integers
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt();
        }
        
        // Read the second permutation input as an array of integers
        int[] q = new int[n];
        for (int i = 0; i < n; i++) {
            q[i] = scanner.nextInt();
        }
        
        // Find the index of the first permutation in the list of all permutations
        int pn = indexOf(orig, p);
        
        // Find the index of the second permutation in the list of all permutations
        int qn = indexOf(orig, q);
        
        // Calculate and print the absolute difference between the two indices
        System.out.println(Math.abs(pn - qn));
        
        scanner.close();
    }
    
    // Method to generate permutations
    private static void permute(List<List<Integer>> orig, List<Integer> current, int n, boolean[] used) {
        if (current.size() == n) {
            orig.add(new ArrayList<>(current));
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                used[i] = true;
                current.add(i);
                permute(orig, current, n, used);
                current.remove(current.size() - 1);
                used[i] = false;
            }
        }
    }
    
    // Method to find the index of a permutation
    private static int indexOf(List<List<Integer>> orig, int[] perm) {
        for (int i = 0; i < orig.size(); i++) {
            List<Integer> list = orig.get(i);
            if (list.size() == perm.length) {
                boolean match = true;
                for (int j = 0; j < perm.length; j++) {
                    if (!list.get(j).equals(perm[j])) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return i;
                }
            }
        }
        return -1; // Should not reach here if input is valid
    }
}
// <END-OF-CODE>
