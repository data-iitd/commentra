
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take input dimensions and threshold from user
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();

        // Initialize numpy array 'c' with dimensions (n, m)
        int[][] c = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i][j] = sc.nextInt();
            }
        }

        // Initialize empty lists 'l' for storing combinations and'rem' for storing indices
        List<List<Integer>> l = new ArrayList<>();
        List<Integer> rem = new ArrayList<>();

        // Initialize variable 'ans' for storing minimum number of tests
        int ans = 0;

        // Loop through all possible combinations of 'pre' indices
        for (int i = 0; i <= n; i++) {
            // Generate all combinations of 'pre' indices of size 'i'
            for (List<Integer> j : combinations(n, i)) {
                // Append the combination to list 'l'
                l.add(j);
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
            // add the index of the current combination to'rem' list
            if (ca < x) {
                rem.add(i);
            }
            // If the sum of tests in current combination is greater than or equal to threshold 'x',
            // continue to next combination
            else {
                continue;
            }

            // If'rem' list is not empty, remove the combinations with indices in'rem' from 'l' list
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
        else {
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

    // Function to generate all combinations of 'pre' indices of size 'i'
    public static List<List<Integer>> combinations(int n, int i) {
        List<List<Integer>> l = new ArrayList<>();
        if (i == 0) {
            l.add(new ArrayList<>());
        } else {
            for (int j = 0; j < n; j++) {
                for (List<Integer> k : combinations(n, i - 1)) {
                    k.add(j);
                    l.add(k);
                }
            }
        }
        return l;
    }
}

