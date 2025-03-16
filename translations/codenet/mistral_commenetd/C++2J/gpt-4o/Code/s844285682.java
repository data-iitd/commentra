import java.util.Scanner; // Import the Scanner class for user input

public class TimeConverter { // Define a public class named TimeConverter
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        
        System.out.print("Enter the number of seconds: "); // Print a message to ask the user for the number of seconds
        int a = scanner.nextInt(); // Read an integer value from the standard input stream and assign it to the variable a
        
        int hours = a / (60 * 60); // Extract the hours from the number of seconds
        int minutes = (a % (60 * 60)) / 60; // Extract the minutes from the remaining seconds
        int seconds = (a % (60 * 60)) % 60; // Extract the seconds from the remaining seconds
        
        System.out.println(hours + ":" + minutes + ":" + seconds); // Print the time representation of the number of seconds
        
        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of main method
} // End of class TimeConverter
// <END-OF-CODE>
