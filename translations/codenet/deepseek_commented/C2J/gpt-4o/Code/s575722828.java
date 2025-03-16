import java.util.Scanner; // Step 1: Import necessary classes

public class TimeConverter { // Step 2: Define the class
    public static void main(String[] args) { // Step 3: Define the main method
        Scanner scanner = new Scanner(System.in); // Step 4: Create a Scanner object to read input
        int S = scanner.nextInt(); // Step 5: Read an integer value from the user and store it in S

        // Step 6: Calculate hours, minutes, and seconds from the total seconds S
        int hours = S / 3600;
        int minutes = (S % 3600) / 60;
        int seconds = S % 60;

        // Step 7: Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"
        System.out.printf("%d:%d:%d\n", hours, minutes, seconds);

        scanner.close(); // Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
