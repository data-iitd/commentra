import java.util.Scanner;  // Import Scanner class for user input

public class CoinCombinations {  // Define the main class
    public static void main(String[] args) {  // Main method where execution begins
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input

        // Declare variables to store the number of each coin type and the target sum
        int A, B, C, X;  
        int kosu = 0;  // Declare and initialize a counter for the number of combinations

        // Read the number of each coin type and the target sum from the user
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();
        X = scanner.nextInt();

        // Normalize the target sum X by dividing it by 50
        X = X / 50;

        // Nested loops to iterate over all possible combinations of the coins
        for (int i = 0; i <= A; i++) {  // Loop over the number of 500 yen coins
            for (int j = 0; j <= B; j++) {  // Loop over the number of 100 yen coins
                for (int k = 0; k <= C; k++) {  // Loop over the number of 50 yen coins
                    if (X == (10 * i) + (2 * j) + k) {  // Check if the sum of the coin values equals the normalized target sum
                        kosu++;  // Increment the counter if the condition is met
                    }
                }
            }
        }

        // Print the final count of combinations
        System.out.println(kosu);

        scanner.close();  // Close the scanner to prevent resource leaks
    }
}  // End of the CoinCombinations class
// <END-OF-CODE>
