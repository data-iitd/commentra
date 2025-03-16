
// Import necessary libraries
import java.util.Scanner;

// Define aliases for common data types
class Solution {
    public static void main(String[] args) {
        // Initialize variables
        int a, b;

        // Read input values from the user
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();

        // Initialize output string
        String ans;

        // Determine the answer based on the input values
        if (a == 1 && b == 1){
            // Both a and b are equal to 1, so the answer is a draw
            ans = "Draw";
        } else if (a == 1){
            // a is equal to 1, so the answer is Alice
            ans = "Alice";
        } else {
            // Neither a nor b is equal to 1, so the answer is Bob
            ans = "Bob";
        }

        // Print the answer to the console
        System.out.println(ans);
    }
}

