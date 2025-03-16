import java.util.Scanner; // Import Scanner class for user input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String s = scanner.next(); // Read a string from user input

        // Outer loop to iterate over each character in the string s using index j
        for (int j = 0; j < s.length(); j++) {
            // Inner loop to iterate over each character in the string s using index i
            for (int i = 0; i < s.length(); i++) {
                // Check if the characters at positions i and j are the same, but only if i is not equal to j
                if (i != j && s.charAt(i) == s.charAt(j)) {
                    System.out.println("no"); // Print "no" if a duplicate character is found and exit the program
                    return; // Exit the main method
                }
            }
        }

        System.out.println("yes"); // Print "yes" if no duplicates are found after completing the loops
    }
}
// <END-OF-CODE>
