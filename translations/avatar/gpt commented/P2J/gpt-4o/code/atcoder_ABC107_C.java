import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read two integers N and K from input
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        // Read a list of integers from input
        List<Integer> lst = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            lst.add(scanner.nextInt());
        }

        // Initialize lists to hold positive and negative numbers
        List<Integer> lst_p = new ArrayList<>();
        List<Integer> lst_m = new ArrayList<>();

        // Iterate through the list to categorize numbers
        for (int i = 0; i < N; i++) {
            // Decrease K for each zero encountered
            if (lst.get(i) == 0) {
                K--;
            }
            // Add positive numbers to lst_p
            if (lst.get(i) > 0) {
                lst_p.add(lst.get(i));
            }
            // Add negative numbers to lst_m
            else if (lst.get(i) < 0) {
                lst_m.add(lst.get(i));
            }
        }

        // Initialize variables to track the last indices of positive and negative lists
        int p = 0;
        int m = 0;
        int lastx = lst_p.size();
        int lasty = lst_m.size();

        // Print the result of the check function with K
        System.out.println(check(lst_p, lst_m, K, lastx, lasty));
    }

    // Define a function to check the minimum value based on K
    public static int check(List<Integer> lst_p, List<Integer> lst_m, int K, int lastx, int lasty) {
        int ans = Integer.MAX_VALUE;  // Initialize answer with a large number

        // Iterate through possible counts of positive numbers used
        for (int j = 0; j <= K; j++) {
            // Check if the current count of positives and negatives is valid
            if (j > lastx || K - j > lasty) {
                continue;  // Skip invalid combinations
            } else {
                // Determine the maximum positive number used
                int p = (j == 0) ? 0 : lst_p.get(j - 1);  // Get the largest positive number used

                // Determine the maximum negative number used
                int m = (K - j == 0) ? 0 : lst_m.get(lasty - (K - j));  // Get the largest negative number used

                // Calculate the minimum value based on the current combination
                ans = Math.min(ans, 2 * p + Math.abs(m));
                ans = Math.min(ans, p + 2 * Math.abs(m));
            }
        }

        return ans;  // Return the minimum value found
    }
}

// <END-OF-CODE>
