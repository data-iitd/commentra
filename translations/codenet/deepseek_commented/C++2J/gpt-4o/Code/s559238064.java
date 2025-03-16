import java.util.Scanner; // Import Scanner for input operations

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String z = scanner.next(); // Read input string from standard input
        int a = z.length(); // Calculate the length of the string and store it in a

        for (int i = 0; i < a - 1; i++) { // Iterate through the string
            if (z.charAt(i) == z.charAt(i + 1)) { // Check if any two consecutive characters are the same
                System.out.println("Bad"); // Print "Bad" if a pair is found and exit
                return; // Exit the main method
            }
        }
        System.out.println("Good"); // Print "Good" if no pair is found
    }
}

// <END-OF-CODE>
