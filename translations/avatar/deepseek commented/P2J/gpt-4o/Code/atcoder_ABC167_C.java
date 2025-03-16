import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class BookCombination {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of books (n), the number of skills (m), and the minimum skill level required (x)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Read the cost matrix where each row represents a book and columns represent cost and skill levels
        int[][] c = new int[n][m + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                c[i][j] = scanner.nextInt();
            }
        }
        
        // Initialize a list to store combinations
        List<List<Integer>> l = new ArrayList<>();
        
        // Generate all possible combinations of books
        for (int i = 1; i <= n; i++) {
            generateCombinations(l, new ArrayList<>(), 0, i, n);
        }
        
        // Initialize the answer variable to store the minimum cost
        int ans = Integer.MAX_VALUE;
        
        // Check each combination to see if the total skill levels meet the requirement
        for (List<Integer> combination : l) {
            int totalCost = 0;
            int[] skillLevels = new int[m];
            
            for (int bookIndex : combination) {
                totalCost += c[bookIndex][0]; // Cost of the book
                for (int skillIndex = 1; skillIndex <= m; skillIndex++) {
                    skillLevels[skillIndex - 1] += c[bookIndex][skillIndex]; // Skill levels
                }
            }
            
            boolean meetsRequirement = true;
            for (int skillLevel : skillLevels) {
                if (skillLevel < x) {
                    meetsRequirement = false;
                    break;
                }
            }
            
            if (meetsRequirement) {
                ans = Math.min(ans, totalCost);
            }
        }
        
        // Output the result
        if (ans == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
        
        scanner.close();
    }
    
    // Helper method to generate combinations
    private static void generateCombinations(List<List<Integer>> combinations, List<Integer> current, int start, int k, int n) {
        if (current.size() == k) {
            combinations.add(new ArrayList<>(current));
            return;
        }
        for (int i = start; i < n; i++) {
            current.add(i);
            generateCombinations(combinations, current, i + 1, k, n);
            current.remove(current.size() - 1);
        }
    }
}
// <END-OF-CODE>
