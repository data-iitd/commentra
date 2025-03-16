import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) { // Start of the infinite loop
            int n = scanner.nextInt(); // Read the first integer
            int x = scanner.nextInt(); // Read the second integer
            
            if (n == 0 && x == 0) { // Check if both n and x are zero
                break; // Exit the loop if true
            }

            int c = 0; // Initialize a counter to zero
            for (int i = 1; i <= n - 2; i++) { // Loop over the first number
                for (int j = i + 1; j <= n - 1; j++) { // Loop over the second number
                    for (int k = j + 1; k <= n; k++) { // Loop over the third number
                        if (i + j + k == x) { // Check if the sum of the three numbers equals x
                            c++; // Increment the counter if true
                        }
                    }
                }
            }
            System.out.println(c); // Print the count of valid combinations
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
