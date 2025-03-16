import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Include necessary libraries for input/output operations

        Scanner scanner = new Scanner(System.in);
        
        int n, m;

        // Read two integers n and m from the standard input
        n = scanner.nextInt();
        m = scanner.nextInt();

        // n represents the number of items, m represents the number of items

        int ans = 0;
        // Initialize a variable to store the result, which will be the sum of combinations

        // Calculate the number of ways to choose 2 items from n items (n choose 2)
        ans += n * (n - 1) / 2;

        // The formula for n choose 2 is n * (n - 1) / 2
        // Add this value to the answer

        // Calculate the number of ways to choose 2 items from m items (m choose 2)
        ans += m * (m - 1) / 2;

        // The formula for m choose 2 is m * (m - 1) / 2
        // Add this value to the answer

        // Output the final answer, which is the sum of combinations from n and m
        System.out.println(ans);
        
        scanner.close();
    }
}
//<END-OF-CODE>
