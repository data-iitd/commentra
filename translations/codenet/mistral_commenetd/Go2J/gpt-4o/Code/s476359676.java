import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of test cases
        int n = sc.nextInt();

        // Initialize variables for processing the input
        int ans = 0;
        int aPrev = 0;

        // Process each test case
        for (int i = 0; i < n; i++) {
            // Read the next integer as 'a'
            int a = sc.nextInt();

            // Check if 'a' is valid based on the conditions in the problem statement
            if (a > i || a > aPrev + 1) { // 'a' is not valid, print -1 and exit
                System.out.println(-1);
                return;
            } else if (a == aPrev + 1) { // Increment the answer if 'a' is consecutive with the previous number
                ans++;
            } else { // Add 'a' to the answer if it's not consecutive but greater than the previous number
                ans += a;
            }

            // Update the previous number
            aPrev = a;
        }

        // Print the final answer
        System.out.println(ans);

        // End of code
    }
}
// <END-OF-CODE>
