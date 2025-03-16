import java.util.Scanner;

public class Main {
    
    // Function to solve the problem based on the given parameters a, b, and c
    public static int solve(int a, int b, int c) {
        int temp_;
        
        // Check if c is equal to the sum of a and b
        if (c == a + b) {
            // If true, calculate the result as b + c
            temp_ = b + c;
        } else if (c - 1 > a + b) {
            // If c-1 is greater than the sum of a and b, calculate the difference
            int temp = (c - 1) - (a + b);
            // Adjust the result based on the calculated difference
            temp_ = b + c - temp;
        } else {
            // If neither condition is met, simply return b + c
            temp_ = b + c;
        }
        
        // Return the calculated result
        return temp_;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers from standard input
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        
        // Call the solve function with the input values and store the result
        int ans = solve(a, b, c);
        
        // Print the result to standard output
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
