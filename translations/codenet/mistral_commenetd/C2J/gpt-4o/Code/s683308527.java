import java.util.Scanner; // Import the Scanner class for input

public class Main { // Start of the Main class
    public static void main(String[] args) { // Start of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read an integer 'n' from the standard input
        scanner.nextLine(); // Consume the newline character after the integer input

        while (n-- > 0) { // Start of the while loop that processes each string
            String s = scanner.nextLine(); // Read a string from the standard input

            // Replace occurrences of "Hoshino" with "aana"
            while (s.contains("Hoshino")) { // Check if the string contains "Hoshino"
                s = s.replaceFirst("Hoshino", "aana"); // Replace the first occurrence of "Hoshino" with "aana"
            }

            System.out.println(s); // Print the modified string to the standard output
        }

        scanner.close(); // Close the scanner
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
