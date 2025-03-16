import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read input values for n (number of items), m (number of categories), and x (threshold value)
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        
        // Read the cost matrix where each row corresponds to an item and each column to a category
        int[][] c = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i][j] = sc.nextInt();
            }
        }
        
        // Create an array of indices for the items
        int[] pre = new int[n];
        for (int i = 0; i < n; i++) {
            pre[i] = i;
        }
        
        // Initialize lists to hold combinations and to track remaining combinations
        List<List<Integer>> l = new ArrayList<>();
        List<Integer> rem = new ArrayList<>();
        
        // Initialize the answer variable to store the minimum cost
        int ans = 0;
        
        // Generate all possible combinations of items of varying lengths
        for (int i = 1; i <= n; i++) {
            for (List<Integer> j : combinations(pre, i)) {
                l.add(j);
            }
        }
        
        // Iterate over each category from 1 to m
        for (int i = 1; i <= m; i++) {
            // Check each combination of items
            for (int j = 0; j < l.size(); j++) {
                int ca = 0;  // Initialize cumulative cost for the current combination
                // Calculate the total cost for the current combination in the current category
                for (int ii : l.get(j)) {
                    ca += c[ii][i];
                }
                
                // If the total cost is less than the threshold x, mark this combination for removal
                if (ca < x) {
                    rem.add(j);
                } else {
                    continue;
                }
            }
            
            // Remove combinations that did not meet the cost requirement
            if (rem.size() > 0) {
                for (int j : rem) {
                    l.remove(j);
                }
                rem.clear();  // Reset the remaining combinations list
            }
            
            // If no valid combinations remain, print -1 and exit
            if (l.size() == 0) {
                System.out.println(-1);
                return;
            }
            
            // If valid combinations remain, calculate the minimum cost for the first category
            for (List<Integer> i : l) {
                int ca = 0;  // Initialize cumulative cost for the current combination
                // Calculate the total cost for the current combination in the first category
                for (int j : i) {
                    ca += c[j][0];
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
    
    // Generate all possible combinations of items of varying lengths
    public static List<List<Integer>> combinations(int[] pre, int i) {
        List<List<Integer>> l = new ArrayList<>();
        for (List<Integer> j : combinations(pre, i - 1)) {
            for (int k = 0; k < pre.length; k++) {
                if (j.contains(k)) {
                    continue;
                } else {
                    List<Integer> k2 = new ArrayList<>(j);
                    k2.add(k);
                    l.add(k2);
                }
            }
        }
        return l;
    }
}

