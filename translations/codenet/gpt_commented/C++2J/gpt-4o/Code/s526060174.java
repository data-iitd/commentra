import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of groups (n) and the maximum number (m)
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Declare variables for the number of elements in each group (k) and the individual element (a)
        int k, a;
        // Array to count occurrences of each number from 1 to m
        int[] x = new int[31]; // Assuming m <= 30 as per the original code
        
        // Loop through each group
        for (int i = 0; i < n; i++) {
            // Read the number of elements in the current group
            k = scanner.nextInt();
            // Loop through each element in the current group
            for (int j = 0; j < k; j++) {
                // Read the element and increment its count in the array
                a = scanner.nextInt();
                x[a]++;
            }
        }

        // Initialize the answer variable to count how many numbers appear in all groups
        int ans = 0;
        
        // Check each number from 1 to m
        for (int i = 1; i <= m; i++) {
            // If the number appears in all n groups, increment the answer
            if (x[i] == n) {
                ans++;
            }
        }

        // Output the final count of numbers that appeared in all groups
        System.out.println(ans);
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
