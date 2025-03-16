import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for red, green, blue colors and number of balls
        int r = scanner.nextInt();
        int g = scanner.nextInt();
        int b = scanner.nextInt();
        int n = scanner.nextInt();
        
        int ans = 0; // Initialize answer variable to zero

        // Check all possible combinations of red, green and blue balls to find the answer
        for (int i = 0; i <= n / r; ++i) { // Iterate through all possible combinations of red balls
            for (int j = 0; j <= n / g; ++j) { // Iterate through all possible combinations of green balls
                int num = n - r * i - g * j; // Calculate the number of blue balls needed to make up the total number of balls

                // Check if the number of blue balls is valid (non-negative and divisible by b)
                if (num >= 0 && num % b == 0) {
                    ++ans; // Increment the answer if the current combination is valid
                }
            }
        }

        // Print the answer to the standard output
        System.out.println(ans);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
