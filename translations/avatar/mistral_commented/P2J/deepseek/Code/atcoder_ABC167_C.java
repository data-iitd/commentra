import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Take input dimensions and threshold from user
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

        // Initialize empty lists 'l' for storing combinations and 'rem' for storing indices
        List<List<Integer>> l = new ArrayList<>();
        List<Integer> rem = new ArrayList<>();

        // Initialize variable 'ans' for storing minimum number of tests
        int ans = 0;

        // Loop through all possible combinations of 'pre' indices
        for (int i = 0; i <= pre.size(); i++) {
            // Generate all combinations of 'pre' indices of size 'i'
            for (List<Integer> j : combinations(pre, i)) {
                // Append the combination to list 'l'
                l.add(new ArrayList<>(j));
            }
        }

        // Loop through each iteration 'i' of test cases
        for (int i = 1; i <= m; i++) {
            // Initialize variable 'ca' to 0 for sum of tests in current combination
            int ca = 0;

            // Loop through each index 'j' in current combination
            for (int j : l.get(i)) {
                // Add the test result at index 'j' and test case 'i' to 'ca'
                ca += c[j][i];
            }

            // If the sum of tests in current combination is less than threshold 'x',
            // add the index of the current combination to 'rem' list
            if (ca < x) {
                rem.add(0, i);
            }
            // If the sum of tests in current combination is greater than or equal to threshold 'x',
            // continue to next combination
            else {
                // Do nothing
            }

            // If 'rem' list is not empty, remove the combinations with indices in 'rem' from 'l' list
            if (!rem.isEmpty()) {
                for (int j : rem) {
                    l.remove(j);
                }
                rem.clear();
            }

            // If 'l' list is empty, print -1 and break the loop
            if (l.isEmpty()) {
                System.out.println(-1);
                break;
            }
        }

        // If the loop completes without finding a valid combination,
        // calculate the minimum number of tests in all valid combinations
        if (!l.isEmpty()) {
            // Initialize variable 'ca' to 0 for sum of tests in current combination
            int ca = 0;

            // Loop through each valid combination and calculate the sum of tests
            for (List<Integer> i : l) {
                ca = 0;
                for (int j : i) {
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
    }

    // Helper method to generate combinations
    public static <T> List<List<T>> combinations(List<T> list, int size) {
        if (size == 0) {
            List<List<T>> result = new ArrayList<>();
            result.add(new ArrayList<>());
            return result;
        }
        if (list.isEmpty()) {
            return new ArrayList<>();
        }
        List<List<T>> result = new ArrayList<>();
        T head = list.get(0);
        List<T> rest = list.subList(1, list.size());
        for (List<T> comb : combinations(rest, size - 1)) {
            List<T> newComb = new ArrayList<>();
            newComb.add(head);
            newComb.addAll(comb);
            result.add(newComb);
        }
        result.addAll(combinations(rest, size));
        return result;
    }
}
