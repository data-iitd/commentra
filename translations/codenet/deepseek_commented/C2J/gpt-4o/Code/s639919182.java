import java.util.Scanner; // Step 1: Import necessary classes

public class Main { // Step 1: Define the main class
    public static void main(String[] args) { // Step 1: Define the main method
        int[] v = new int[10]; // Step 2: Declare an array of 10 integers
        int sum = 0; // Step 2: Declare and initialize a variable to store the sum
        Scanner scanner = new Scanner(System.in); // Step 2: Create a Scanner object for input
        
        for (int i = 0; i < 10; i++) { // Step 3: Initialize a loop to read 10 integers from the user
            v[i] = scanner.nextInt(); // Step 3: Read an integer and store it in the array
        }
        
        for (int i = 0; i < 10; i++) { // Step 4: Initialize a loop to calculate the sum of the integers
            sum += v[i]; // Step 4: Add the current element to the sum
        }
        
        System.out.println(sum); // Step 5: Print the sum of the integers
        
        scanner.close(); // Close the scanner to prevent resource leaks
    } // Step 6: End of main method
} // End of class
// <END-OF-CODE>
