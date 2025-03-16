import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // a stores the counts of characters 'M', 'A', 'R', 'C', 'H'
    static int[] a;
    // ans accumulates the result of the calculations performed by the dfs function
    static int ans = 0;

    // dfs is a recursive function that calculates the product of 3 elements from array a
    static void dfs(int left, int i, int res) {
        if (left == 0) {
            ans += res; // When no elements are left to multiply, add the result to ans
            return;
        }
        for (int j = i; j < a.length; j++) {
            dfs(left - 1, j + 1, res * a[j]); // Recursively call dfs with updated parameters
        }
    }

    // main function to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of characters
        Map<Character, Integer> dic = new HashMap<>();

        // Count occurrences of 'M', 'A', 'R', 'C', 'H'
        for (int i = 0; i < n; i++) {
            char c = scanner.next().charAt(0);
            if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
                dic.put(c, dic.getOrDefault(c, 0) + 1);
            }
        }

        // Initialize the array a with the size of the number of unique characters
        a = new int[dic.size()];
        int index = 0;
        for (int v : dic.values()) {
            a[index++] = v;
        }

        // Call dfs with parameters 3, 0, and 1
        dfs(3, 0, 1);
        System.out.println(ans); // Print the final result
        scanner.close();
    }
}
// <END-OF-CODE>
