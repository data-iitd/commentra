import java.util.Scanner;

public class WeatherCondition {
    // Main function where the program execution begins
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        String S = scanner.next(); // Read the weather condition from standard input

        // Determine the next weather condition based on the current one
        if (S.equals("Sunny")) {
            System.out.println("Cloudy"); // If it's sunny, print "Cloudy"
        } else if (S.equals("Cloudy")) {
            System.out.println("Rainy"); // If it's cloudy, print "Rainy"
        } else {
            System.out.println("Sunny"); // If it's neither, it must be rainy, print "Sunny"
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
