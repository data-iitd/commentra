import java.util.Scanner; // Import the Scanner class for input

public class Main { // Declare the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String str = scanner.next(); // Read the first string
        String p = scanner.next(); // Read the second string

        String tmp = str; // Store the original str in tmp
        str += tmp; // Concatenate str with itself

        int slen = str.length(); // Get the length of str
        int plen = p.length(); // Get the length of p

        boolean flag = false; // Initialize flag to false
        for (int i = 0; i <= slen - plen; i++) { // Iterate through str
            if (str.substring(i, i + plen).equals(p)) { // Compare the substring of str with p
                flag = true; // If they are equal, set flag to true
                break; // Exit the loop as we found a match
            }
        }

        if (flag) System.out.println("Yes"); // If flag is true, print "Yes"
        else System.out.println("No"); // If flag is false, print "No"

        scanner.close(); // Close the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
