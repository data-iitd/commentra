import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of test cases
        int N = scanner.nextInt();
        
        // Initialize the answer to 0
        long ans = 0;
        
        // Iterate through all numbers from 1 to N
        for (int i = 1; i <= N; i++) {
            // Calculate the contribution of i to the answer
            // The formula is given by the problem statement
            ans += i * (N / i) * (N / i + 1) / 2;
        }
        
        // Print the answer
        System.out.println(ans);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
