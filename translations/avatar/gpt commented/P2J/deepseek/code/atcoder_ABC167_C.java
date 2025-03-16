import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for n (number of items), m (number of categories), and x (threshold value)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Read the cost matrix where each row corresponds to an item and each column to a category
        int[][] c = new int[n][m + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m + 1; j++) {
                c[i][j] = scanner.nextInt();
            }
        }
        
        // Initialize the answer variable to store the minimum cost
        int ans = -1;
        
        // Generate all possible combinations of items of varying lengths
        for (int i = 1; i <= n; i++) {
            List<List<Integer>> combinations = new ArrayList<>();
            generateCombinations(combinations, new ArrayList<>(), 0, n, i);
            
            // Iterate over each category from 1 to m
            for (int category = 1; category <= m; category++) {
                // Check each combination of items
                List<Integer> toRemove = new ArrayList<>();
                for (int j = 0; j < combinations.size(); j++) {
                    List<Integer> combination = combinations.get(j);
                    int totalCost = 0;
                    // Calculate the total cost for the current combination in the current category
                    for (int item : combination) {
                        totalCost += c[item][category];
                    }
                    
                    // If the total cost is less than the threshold x, mark this combination for removal
                    if (totalCost < x) {
                        toRemove.add(j);
                    }
                }
                
                // Remove combinations that did not meet the cost requirement
                Collections.reverse(toRemove);
                for (int index : toRemove) {
                    combinations.remove(index);
                }
                
                // If no valid combinations remain, print -1 and exit
                if (combinations.isEmpty()) {
                    System.out.println(-1);
                    return;
                }
            }
            
            // If valid combinations remain, calculate the minimum cost for the first category
            for (List<Integer> combination : combinations) {
                int totalCost = 0;
                // Calculate the total cost for the current combination in the first category
                for (int item : combination) {
                    totalCost += c[item][0];
                }
                
                // Update the answer with the minimum cost found
                if (ans == -1) {
                    ans = totalCost;
                } else {
                    ans = Math.min(ans, totalCost);
                }
            }
        }
        
        // Print the minimum cost found
        System.out.println(ans);
    }
    
    // Helper method to generate all combinations of items of a given length
    private static void generateCombinations(List<List<Integer>> combinations, List<Integer> current, int start, int n, int length) {
        if (length == 0) {
            combinations.add(new ArrayList<>(current));
            return;
        }
        for (int i = start; i < n; i++) {
            current.add(i);
            generateCombinations(combinations, current, i + 1, n, length - 1);
            current.remove(current.size() - 1);
        }
    }
}
