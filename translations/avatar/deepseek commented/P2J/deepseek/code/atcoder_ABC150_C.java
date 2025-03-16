import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input `n`
        List<List<Integer>> orig = new ArrayList<>();  // Create a list to store all permutations
        List<Integer> nums = new ArrayList<>();  // Create a list to store numbers from 1 to `n`
        for (int i = 1; i <= n; i++) {
            nums.add(i);
        }
        permute(nums, 0, n - 1, orig);  // Generate all permutations of numbers from 1 to `n`
        List<Integer> p = new ArrayList<>();  // Take the first permutation `p` as a list of integers
        List<Integer> q = new ArrayList<>();  // Take the second permutation `q` as a list of integers
        for (int i = 0; i < n; i++) {
            p.add(scanner.nextInt());
        }
        for (int i = 0; i < n; i++) {
            q.add(scanner.nextInt());
        }
        int pn = orig.indexOf(p);  // Find the index of permutation `p` in the list of all permutations
        int qn = orig.indexOf(q);  // Find the index of permutation `q` in the list of all permutations
        System.out.println(Math.abs(pn - qn));  // Calculate the absolute difference between the indices and print the result
    }

    // Utility function to generate all permutations of a list
    public static void permute(List<Integer> nums, int l, int r, List<List<Integer>> orig) {
        if (l == r) {
            orig.add(new ArrayList<>(nums));
        } else {
            for (int i = l; i <= r; i++) {
                Collections.swap(nums, l, i);
                permute(nums, l + 1, r, orig);
                Collections.swap(nums, l, i);  // backtrack
            }
        }
    }
}
