import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // Arrays to store input values
    static int[] a = null;
    static int[] b = null;
    static int[] c = null;
    static int[] d = null;
    
    // Variables to store input values
    static int n = 0;
    static int m = 0;
    static int q = 0;
    
    // Variable to store the maximum score
    static long ans = -100L;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read values of n, m, and q
        n = sc.nextInt();
        m = sc.nextInt();
        q = sc.nextInt();
        
        // Initialize arrays to store the conditions
        a = new int[q];
        b = new int[q];
        c = new int[q];
        d = new int[q];
        
        // Read the conditions into the arrays
        for (int i = 0; i < q; ++i) {
            a[i] = sc.nextInt() - 1; // Adjusting for 0-based index
            b[i] = sc.nextInt() - 1; // Adjusting for 0-based index
            c[i] = sc.nextInt();
            d[i] = sc.nextInt();
        }
        
        // Start the DFS with an empty list
        dfs(new ArrayList<Integer>());
        
        // Print the maximum score found
        System.out.println(ans);
    }

    // Depth-First Search (DFS) function to generate combinations
    public static void dfs(ArrayList<Integer> list) {
        // If the list size equals n, calculate the score and update ans
        if (list.size() == n) {
            long score = 0L;
            for (int i = 0; i < q; ++i) {
                if (list.get(b[i]) - list.get(a[i]) == c[i]) {
                    score += d[i];
                }
            }
            ans = Math.max(ans, score);
            return;
        }
        
        // If the list is not empty, continue adding numbers from the last number in the list
        if (!list.isEmpty()) {
            for (int num = list.get(list.size() - 1); num <= m; ++num) {
                list.add(num);
                dfs(list);
                list.remove(list.size() - 1);
            }
        } else {
            // If the list is empty, start with numbers from 1 to m
            for (int num = 1; num <= m; ++num) {
                list.add(num);
                dfs(list);
                list.remove(list.size() - 1);
            }
        }
    }
}
