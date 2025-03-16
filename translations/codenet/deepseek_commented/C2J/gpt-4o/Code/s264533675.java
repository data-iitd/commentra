import java.util.Scanner;  // Import the Scanner class for user input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        String str = scanner.nextLine();  // Read input from the user
        char[] charArray = str.toCharArray();  // Convert the string to a character array
        charArray[5] = ' ';  // Modify the array by replacing the character at position 5 with a space
        charArray[13] = ' '; // Modify the array by replacing the character at position 13 with a space
        System.out.println(new String(charArray));  // Print the modified string to the console
        scanner.close();  // Close the scanner
    }  // End of the main method
}  // End of the Main class
// <END-OF-CODE>
