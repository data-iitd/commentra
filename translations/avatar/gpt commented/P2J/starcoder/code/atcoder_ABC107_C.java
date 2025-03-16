import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read two integers N and K from input
        int N = sc.nextInt();
        int K = sc.nextInt();
        
        // Read a list of integers from input
        int[] lst = new int[N];
        for (int i = 0; i < N; i++) {
            lst[i] = sc.nextInt();
        }
        
        // Initialize lists to hold positive and negative numbers
        List<Integer> lst_p = new ArrayList<Integer>();
        List<Integer> lst_m = new ArrayList<Integer>();
        
        // Iterate through the list to categorize numbers
        for (int i = 0; i < N; i++) {
            // Decrease K for each zero encountered
            if (lst[i] == 0) {
                K--;
            }
            // Add positive numbers to lst_p
            if (lst[i] > 0) {
                lst_p.add(lst[i]);
            }
            // Add negative numbers to lst_m
            else if (lst[i] < 0) {
                lst_m.add(lst[i]);
            }
        }
        
        // Initialize variables to track the last indices of positive and negative lists
        int p = 0;
        int m = 0;
        int x = 0;
        int y = lst_m.size() - 1;
        int lastx = lst_p.size();
        int lasty = lst_m.size();
        
        // Define a function to check the minimum value based on K
        int check(int k) {
            int ans = 1000000000;  // Initialize answer with a large number
            // Iterate through possible counts of positive numbers used
            for (int j = 0; j <= k; j++) {
                // Check if the current count of positives and negatives is valid
                if (j > lastx || k - j > lasty) {
                    continue;  // Skip invalid combinations
                }
                // Determine the maximum positive number used
                if (j == 0) {
                    p = 0;  // No positive numbers used
                }
                else {
                    p = lst_p.get(j - 1);  // Get the largest positive number used
                }
                // Determine the maximum negative number used
                if (k - j == 0) {
                    m = 0;  // No negative numbers used
                }
                else {
                    m = lst_m.get(lasty - (k - j));  // Get the largest negative number used
                }
                // Calculate the minimum value based on the current combination
                ans = Math.min(ans, 2 * p + Math.abs(m), p + 2 * Math.abs(m));
            }
            return ans;  // Return the minimum value found
        }
        
        // Print the result of the check function with K
        System.out.println(check(K));
    }
}

