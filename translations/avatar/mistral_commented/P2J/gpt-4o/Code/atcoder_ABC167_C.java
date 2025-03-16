import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Take input dimensions and threshold from user
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Initialize 2D array 'c' with dimensions (n, m)
        int[][] c = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i][j] = scanner.nextInt();
            }
        }

        // Initialize lists for storing combinations and indices
        List<List<Integer>> l = new ArrayList<>();
        List<Integer> rem = new ArrayList<>();

        // Initialize variable 'ans' for storing minimum number of tests
        int ans = 0;

        // Generate all combinations of indices
        List<Integer> pre = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            pre.add(i);
        }

        // Loop through all possible combinations of 'pre' indices
        for (int i = 0; i <= pre.size(); i++) {
            combinations(pre, i, 0, new ArrayList<>(), l);
        }

        // Loop through each iteration 'i' of test cases
        for (int i = 0; i < m; i++) {
            // Initialize variable 'ca' to 0 for sum of tests in current combination
            int ca = 0;

            // Loop through each index 'j' in current combination
            for (List<Integer> combination : l) {
                ca = 0; // Reset ca for each combination
                for (int j : combination) {
                    ca += c[j][i];
                }

                // If the sum of tests in current combination is less than threshold 'x',
                // add the index of the current combination to 'rem' list
                if (ca < x) {
                    rem.add(i);
                }
            }

            // If 'rem' list is not empty, remove the combinations with indices in 'rem' from 'l' list
            if (!rem.isEmpty()) {
                l.removeIf(combination -> rem.contains(l.indexOf(combination)));
                rem.clear();
            }

            // If 'l' list is empty, print -1 and break the loop
            if (l.isEmpty()) {
                System.out.println(-1);
                return;
            }
        }

        // If the loop completes without finding a valid combination,
        // calculate the minimum number of tests in all valid combinations
        for (List<Integer> combination : l) {
            int ca = 0;
            for (int j : combination) {
                ca += c[j][0];
            }

            // Update 'ans' with minimum number of tests among all valid combinations
            if (ans == 0) {
                ans = ca;
            } else {
                ans = Math.min(ans, ca);
            }
        }

        // Print the minimum number of tests required
        System.out.println(ans);
    }

    // Method to generate combinations
    private static void combinations(List<Integer> pre, int r, int start, List<Integer> current, List<List<Integer>> result) {
        if (current.size() == r) {
            result.add(new ArrayList<>(current));
            return;
        }
        for (int i = start; i < pre.size(); i++) {
            current.add(pre.get(i));
            combinations(pre, r, i + 1, current, result);
            current.remove(current.size() - 1);
        }
    }
}
// <END-OF-CODE>
