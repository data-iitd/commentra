import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input values for n (number of items), m (number of categories), and x (threshold value)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();

        // Read the cost matrix where each row corresponds to an item and each column to a category
        int[][] c = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i][j] = scanner.nextInt();
            }
        }

        // Create a list to hold combinations
        List<List<Integer>> combinations = new ArrayList<>();
        List<Integer> remaining = new ArrayList<>();

        // Initialize the answer variable to store the minimum cost
        int ans = 0;

        // Generate all possible combinations of items of varying lengths
        for (int i = 1; i <= n; i++) {
            generateCombinations(combinations, new ArrayList<>(), 0, i, n);
        }

        // Iterate over each category from 0 to m-1 (Java uses 0-based indexing)
        for (int i = 0; i < m; i++) {
            // Check each combination of items
            for (int j = 0; j < combinations.size(); j++) {
                List<Integer> combo = combinations.get(j);
                int ca = 0;  // Initialize cumulative cost for the current combination
                // Calculate the total cost for the current combination in the current category
                for (int index : combo) {
                    ca += c[index][i];
                }

                // If the total cost is less than the threshold x, mark this combination for removal
                if (ca < x) {
                    remaining.add(j);
                }
            }

            // Remove combinations that did not meet the cost requirement
            for (int j = remaining.size() - 1; j >= 0; j--) {
                combinations.remove((int) remaining.get(j));
            }
            remaining.clear();  // Reset the remaining combinations list

            // If no valid combinations remain, print -1 and exit
            if (combinations.isEmpty()) {
                System.out.println(-1);
                return;
            }
        }

        // If valid combinations remain, calculate the minimum cost for the first category
        for (List<Integer> combo : combinations) {
            int ca = 0;  // Initialize cumulative cost for the current combination
            // Calculate the total cost for the current combination in the first category
            for (int index : combo) {
                ca += c[index][0];
            }

            // Update the answer with the minimum cost found
            if (ans == 0) {
                ans = ca;
            } else {
                ans = Math.min(ans, ca);
            }
        }

        // Print the minimum cost found
        System.out.println(ans);
    }

    // Helper method to generate combinations
    private static void generateCombinations(List<List<Integer>> combinations, List<Integer> current, int start, int length, int n) {
        if (current.size() == length) {
            combinations.add(new ArrayList<>(current));
            return;
        }
        for (int i = start; i < n; i++) {
            current.add(i);
            generateCombinations(combinations, current, i + 1, length, n);
            current.remove(current.size() - 1);
        }
    }
}
//<END-OF-CODE>
