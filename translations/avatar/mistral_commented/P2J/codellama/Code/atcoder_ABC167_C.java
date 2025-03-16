// Import necessary libraries
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class Solution {
    public static void main(String[] args) {
        // Take input dimensions and threshold from user
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();

        // Initialize array 'c' with dimensions (n, m)
        int[][] c = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i][j] = sc.nextInt();
            }
        }

        // Initialize empty lists 'l' for storing combinations and 'rem' for storing indices
        ArrayList<ArrayList<Integer>> l = new ArrayList<>();
        ArrayList<Integer> rem = new ArrayList<>();

        // Initialize variable 'ans' for storing minimum number of tests
        int ans = 0;

        // Loop through all possible combinations of 'pre' indices
        for (int i = 0; i <= pre.length; i++) {
            // Generate all combinations of 'pre' indices of size 'i'
            for (int j = 0; j < pre.length - i; j++) {
                // Append the combination to list 'l'
                l.add(new ArrayList<>(Arrays.asList(pre[j], pre[j + i])));
            }
        }

        // Loop through each iteration 'i' of test cases
        for (int i = 1; i <= m; i++) {
            // Initialize variable 'ca' to 0 for sum of tests in current combination
            int ca = 0;

            // Loop through each index 'j' in current combination
            for (int j = 0; j < l.get(i).size(); j++) {
                // Add the test result at index 'j' and test case 'i' to 'ca'
                ca += c[l.get(i).get(j)][i];
            }

            // If the sum of tests in current combination is less than threshold 'x',
            // add the index of the current combination to 'rem' list
            if (ca < x) {
                rem.add(i);
            }
            // If the sum of tests in current combination is greater than or equal to threshold 'x',
            // continue to next combination
            else {
                continue;
            }

            // If 'rem' list is not empty, remove the combinations with indices in 'rem' from 'l' list
            if (rem.size() > 0) {
                for (int j = 0; j < rem.size(); j++) {
                    l.remove(rem.get(j));
                }
                rem.clear();
            }

            // If 'l' list is empty, print -1 and break the loop
            if (l.size() == 0) {
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
            for (int i = 0; i < l.size(); i++) {
                ca = 0;
                for (int j = 0; j < l.get(i).size(); j++) {
                    ca += c[l.get(i).get(j)][0];
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
}

