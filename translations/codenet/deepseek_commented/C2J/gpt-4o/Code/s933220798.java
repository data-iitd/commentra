import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        double a; // Declare a variable to store the input value
        double ave = 0; // Initialize a variable to store the sum of values
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input
        
        // Loop to read 5 values from the user
        for (int i = 0; i < 5; i++) {
            a = scanner.nextDouble(); // Read a double value from the user and store it in 'a'
            if (a <= 40) { // Check if the value of 'a' is less than or equal to 40
                ave += 40; // Add 40 to 'ave' if the condition is true
            } else {
                ave += a; // Add the value of 'a' to 'ave' if the condition is false
            }
        }
        
        ave /= 5.0; // Calculate the average of the values added to 'ave' and divide by 5.0
        
        System.out.printf("%.0f\n", ave); // Print the average value rounded to the nearest integer
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
