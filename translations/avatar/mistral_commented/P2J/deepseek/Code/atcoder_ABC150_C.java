import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PermutationIndex {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask the user for the size of the permutation list
        int n = scanner.nextInt();

        // Create a list of all possible permutations of numbers from 1 to n
        List<List<Integer>> orig = new ArrayList<>();
        List<Integer> nums = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            nums.add(i);
        }
        permute(nums, 0, n - 1, orig);

        // Ask the user for two permutations as lists
        List<Integer> p = new ArrayList<>();
        List<Integer> q = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            p.add(scanner.nextInt());
        }
        for (int i = 0; i < n; i++) {
            q.add(scanner.nextInt());
        }

        // Find the indices of p and q in the orig list
        int pn = findIndex(orig, p);
        int qn = findIndex(orig, q);

        // Print the absolute difference between the indices of p and q
        System.out.println(Math.abs(pn - qn));
    }

    // Utility method to generate all permutations of a list
    private static void permute(List<Integer> nums, int l, int r, List<List<Integer>> orig) {
        if (l == r) {
            orig.add(new ArrayList<>(nums));
        } else {
            for (int i = l; i <= r; i++) {
                Collections.swap(nums, l, i);
                permute(nums, l + 1, r, orig);
                Collections.swap(nums, l, i); // backtrack
            }
        }
    }

    // Utility method to find the index of a list in a list of lists
    private static int findIndex(List<List<Integer>> orig, List<Integer> target) {
        for (int i = 0; i < orig.size(); i++) {
            if (orig.get(i).equals(target)) {
                return i;
            }
        }
        return -1;
    }
}
