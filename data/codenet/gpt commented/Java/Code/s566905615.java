import java.util.*;

class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read three integers from the user
        int a = sc.nextInt(); // First integer
        int b = sc.nextInt(); // Second integer
        int c = sc.nextInt(); // Third integer
        
        // Initialize the answer variable with "No"
        String answer = "No";
        
        // Check if the sum of a and b is greater than or equal to c
        if (a + b >= c) {
            // If the condition is true, set answer to "Yes"
            answer = "Yes";
        }
        
        // Print the result
        System.out.println(answer);
    }
}
