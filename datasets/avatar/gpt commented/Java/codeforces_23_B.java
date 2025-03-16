import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scan = new Scanner(System.in);
        
        // Read the number of test cases
        int t = scan.nextInt();
        
        // Loop through each test case
        for (int i = 0; i < t; i++) {
            // Read the integer n for the current test case
            int n = scan.nextInt();
            
            // Call the maxLeft function and print the result
            System.out.println(maxLeft(n));
        }
        
        // Close the scanner to prevent resource leaks
        scan.close();
    }

    // Function to calculate the maximum value based on the input n
    public static int maxLeft(int n) {
        // Return n - 2 if n is greater than 2, otherwise return 0
        return n > 2 ? n - 2 : 0;
    }
}
