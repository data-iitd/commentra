import java.util.Scanner;

public class Weather {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String S = scanner.next(); // Get input for the string variable S

        if (S.equals("Sunny")) { // Check if the string is equal to "Sunny"
            System.out.println("Cloudy"); // If true, print "Cloudy"
        } else if (S.equals("Cloudy")) { // Check if the string is equal to "Cloudy"
            System.out.println("Rainy"); // If true, print "Rainy"
        } else { // If neither of the conditions are true
            System.out.println("Sunny"); // Print "Sunny"
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
