import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the main class
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String s = scanner.next(); // Read a string from the standard input

        boolean hasDuplicates = false; // Flag to check for duplicates

        for (int j = 0; j < s.length(); j++) { // Iterate through each character in the string 's' using index 'j'
            for (int i = 0; i < s.length(); i++) { // Nested loop to compare each character with all other characters in the string
                if (i != j && s.charAt(i) == s.charAt(j)) { // Check if the current characters at indices 'i' and 'j' are the same and not the same index
                    hasDuplicates = true; // Set the flag to true if duplicates are found
                    break; // Exit the inner loop
                }
            }
            if (hasDuplicates) break; // Exit the outer loop if duplicates are found
        }

        if (hasDuplicates) {
            System.out.println("no"); // If duplicate characters are found, print 'no'
        } else {
            System.out.println("yes"); // If no duplicate characters are found, print 'yes'
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
