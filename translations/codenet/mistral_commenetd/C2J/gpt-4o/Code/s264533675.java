import java.util.Scanner; // Import the Scanner class for user input

public class Main { // Declare the Main class
    public static void main(String[] args) { // Declare the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String str = scanner.nextLine(); // Get a string input from the user

        // Convert the string to a character array to modify specific indices
        char[] charArray = str.toCharArray();

        // Assign a space character to the 6th index (index starts from 0) and 14th index of the charArray
        if (charArray.length > 5) charArray[5] = ' ';
        if (charArray.length > 13) charArray[13] = ' ';

        // Convert the modified character array back to a string
        String modifiedStr = new String(charArray);

        // Print the modified string
        System.out.println(modifiedStr);

        // Close the scanner
        scanner.close();
    } // End of main method
} // End of Main class
// <END-OF-CODE>
