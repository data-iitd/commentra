import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the count of numbers to be inputted
        int count = Integer.parseInt(sc.next());
        
        // Initialize an array to hold the numbers
        int[] givingNumbers = new int[count];
        
        // Read Numbers into the array
        for (int i = 0; i < count; i++) {
            // Parse and store each number in the array
            givingNumbers[i] = Integer.parseInt(sc.next());
        }
        
        // Reversing Numbers and printing them
        for (int i = count - 1; 0 <= i; i--) {
            // Print the number at the current index
            System.out.print(givingNumbers[i]);
            
            // Print a space after each number except the last one
            if (i > 0) {
                System.out.print(" ");
            }
        }
        
        // Move to the next line after printing all numbers
        System.out.println();
        
        // Close the scanner to free up resources
        sc.close();
    }
}
