import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of books (n), the number of skills (m), and the minimum skill level required (x)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Read the cost matrix where each row represents a book and columns represent cost and skill levels
        int[][] c = new int[n][m + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m + 1; j++) {
                c[i][j] = scanner.nextInt();
            }
        }
        
        // Initialize a range array to help generate combinations
        List<Integer> pre = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            pre.add(i);
        }
        
        // Initialize lists to store combinations and removable combinations
        List<List<Integer>> l = new ArrayList<>();
        List<Integer> rem = new ArrayList<>();
        
        // Initialize the answer variable to store the minimum cost
        int ans = Integer.MAX_VALUE;
        
        // Generate all possible combinations of books using itertools.combinations
        for (int i = 1; i <= n; i++) {
            List<List<Integer>> combinations = combine(pre, i);
            l.addAll(combinations);
        }
        
        // Check each combination to see if the total cost meets the requirement and adjust the list accordingly
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < l.size(); j++) {
                int ca = 0;
                for (int ii : l.get(j)) {
                    ca += c[ii][i];
                }
                if (ca < x) {
                    rem.add(j);
                }
            }
            if (!rem.isEmpty()) {
                Collections.sort(rem, Collections.reverseOrder());
                for (int j : rem) {
                    l.remove(j);
                }
                rem.clear();
            }
        }
        
        if (l.isEmpty()) {
            System.out.println(-1);
        } else {
            // Find the minimum cost among the valid combinations
            for (List<Integer> i : l) {
                int ca = 0;
                for (int j : i) {
                    ca += c[j][0];
                }
                ans = Math.min(ans, ca);
            }
            System.out.println(ans);
        }
    }
    
    // Helper method to generate combinations
    public static <T> List<List<T>> combine(List<T> list, int size) {
        List<List<T>> result = new ArrayList<>();
        combineHelper(list, size, 0, new ArrayList<>(), result);
        return result;
    }
    
    private static <T> void combineHelper(List<T> list, int size, int start, List<T> current, List<List<T>> result) {
        if (current.size() == size) {
            result.add(new ArrayList<>(current));
            return;
        }
        for (int i = start; i < list.size(); i++) {
            current.add(list.get(i));
            combineHelper(list, size, i + 1, current, result);
            current.remove(current.size() - 1);
        }
    }
}
