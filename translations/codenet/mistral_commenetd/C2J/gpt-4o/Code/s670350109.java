import java.util.Scanner; // Import the Scanner class for user input

public class StringComparison { // Define the class
    public static void main(String[] args) { // Start of main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        // Declare two strings
        String str1, str2;
        
        // Read the first string from the user
        str1 = scanner.nextLine();
        System.out.println("First string: " + str1); // Print the first string for verification

        // Read the second string from the user
        str2 = scanner.nextLine();
        System.out.println("Second string: " + str2); // Print the second string for verification

        // Check if the lengths of the two strings are equal
        if (str1.length() != str2.length()) {
            System.out.println("NO"); // If the lengths are not equal, print "NO"
        } else {
            // Reverse the first string
            StringBuilder temp = new StringBuilder(str1).reverse(); // Reverse the string using StringBuilder

            // Compare the reversed first string with the second string
            if (temp.toString().equals(str2)) { // Check if the reversed string equals the second string
                System.out.println("YES"); // If they are equal, print "YES"
            } else {
                System.out.println("NO"); // If they are not equal, print "NO"
            }
        }

        scanner.close(); // Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
