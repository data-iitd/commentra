import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from input and assign them to variables a and b
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Initialize the variable 'hole' to represent the current hole position
        int hole = 1;
        
        // Initialize a counter 'i' to track the number of iterations
        int i = 0;
        
        // Set a flag 'check' to control the while loop
        boolean check = true;
        
        // Continue looping until the condition is met
        while (check) {
            // Check if the current hole position is greater than or equal to b
            if (hole >= b) {
                // If so, exit the loop
                check = false;
            } else {
                // Calculate the new hole position based on the formula
                hole = a * (i + 1) - i;
                
                // Increment the iteration counter
                i++;
            }
        }
        
        // Print the total number of iterations (i) when the loop ends
        System.out.println(i);
    }
}
