import java.util.Scanner;

public class Main {
    // Function to find a number X raised to the power n such that A * X^n equals B
    public static Integer task4(int A, int B, int n) {
        // Iterate through all possible values of X from -1000 to 1000
        for (int X = -1000; X <= 1000; X++) {
            // Check if the condition A * X^n equals B is satisfied
            if (A * Math.pow(X, n) == B) {
                // If the condition is satisfied, return the value of X
                return X;
            }
        }
        // If no solution is found, return null
        return null;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Get input values of A, B, and n from the user
        String[] input = scanner.nextLine().split(" ");
        
        // Convert input strings to integers
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        int n = Integer.parseInt(input[2]);
        
        // Call the function and print the result
        Integer result = task4(A, B, n);
        if (result != null) {
            System.out.println(result);
        } else {
            System.out.println("No solution");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
