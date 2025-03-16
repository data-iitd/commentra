import java.util.Scanner;

// Include the Scanner class for input

public class TimeConverter {
    public static void main(String[] args) {
        int S; // Declare an integer variable named S

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Initialize an integer variable named S with a value read from the standard input
        S = scanner.nextInt();

        // Print the hours, minutes, and seconds of the given number of seconds
        System.out.printf("%d:%d:%d\n", S / 3600, (S % 3600) / 60, S % 60);

        // Close the scanner
        scanner.close();
    }
}

// Return 0 to indicate successful execution of the program
