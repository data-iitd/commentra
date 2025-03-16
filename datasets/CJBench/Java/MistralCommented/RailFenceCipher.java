import java.util.Arrays;
import java.util.Scanner;

/**
 * Main class for encrypting and decrypting a string using a rail fence cipher.
 */
public class Main {

    /**
     * Encrypts a given string using rail fence cipher with the specified number of rails.
     *
     * @param str the string to be encrypted
     * @param rails the number of rails to be used in the encryption process
     * @return the encrypted string
     */
    public String encrypt(String str, int rails) {
        if (rails == 1 || rails >= str.length()) {
            // If the number of rails is 1 or equal to the length of the string, return the original string
            return str;
        }

        boolean down = true; // Flag to determine the direction of traversing the rail fence
        char[][] strRail = new char[rails][str.length()]; // 2D array to store the encrypted string

        // Initialize the 2D array with newline character
        for (int i = 0; i < rails; i++) {
            Arrays.fill(strRail[i], '\n');
        }

        int row = 0, col = 0, i = 0; // Initialize the row, column and string index

        // Fill the 2D array with the given string
        while (col < str.length()) {
            if (row == 0) {
                down = true; // Reset the direction flag if we start a new row
            } else if (row == rails - 1) {
                down = false; // Change the direction flag if we reach the last row
            }
            strRail[row][col] = str.charAt(i++); // Store the character from the string into the 2D array
            col++; // Increment the column index
            if (down) {
                row++; // Increment the row index if moving down
            } else {
                row--; // Decrement the row index if moving up
            }
        }

        // Build the encrypted string from the 2D array
        StringBuilder encryptedString = new StringBuilder();
        for (char[] chRow : strRail) {
            for (char ch : chRow) {
                if (ch != '\n') { // Skip newline character while building the encrypted string
                    encryptedString.append(ch);
                }
            }
        }

        // Return the encrypted string
        return encryptedString.toString();
    }

    /**
     * Decrypts a given string using rail fence cipher with the specified number of rails.
     *
     * @param str the string to be decrypted
     * @param rails the number of rails to be used in the decryption process
     * @return the decrypted string
     */
    public String decrypt(String str, int rails) {
        if (rails == 1 || rails >= str.length()) {
            // If the number of rails is 1 or equal to the length of the string, return the original string
            return str;
        }

        boolean down = true; // Flag to determine the direction of traversing the rail fence
        char[][] strRail = new char[rails][str.length()]; // 2D array to store the decrypted string

        // Initialize the 2D array with asterisks
        for (int i = 0; i < rails; i++) {
            Arrays.fill(strRail[i], '*');
        }

        int index = 0; // Index to fill the characters from the given string into the 2D array

        // Fill the 2D array with the given string
        for (int i = 0; i < rails; i++) {
            for (int j = 0; j < str.length(); j++) {
                if (strRail[i][j] == '*') {
                    strRail[i][j] = str.charAt(index++); // Replace the asterisk with the character from the string
                }
            }
        }

        // Build the decrypted string from the 2D array
        StringBuilder decryptedString = new StringBuilder();
        row = 0;
        col = 0;

        // Fill the StringBuilder with the characters from the 2D array
        while (col < str.length()) {
            if (row == 0) {
                down = true; // Reset the direction flag if we start a new row
            } else if (row == rails - 1) {
                down = false; // Change the direction flag if we reach the last row
            }
            decryptedString.append(strRail[row][col]); // Append the character from the 2D array to the StringBuilder
            col++; // Increment the column index
            if (down) {
                row++; // Increment the row index if moving down
            } else {
                row--; // Decrement the row index if moving up
            }
        }

        // Return the decrypted string
        return decryptedString.toString();
    }

    /**
     * Main method to take user input and call the encryption or decryption method based on the user's choice.
     *
     * @param args command line arguments
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize the Scanner to read user input

        String operation = scanner.next(); // Read the operation ('encrypt' or 'decrypt') from the user
        int rails = scanner.nextInt(); // Read the number of rails from the user
        scanner.nextLine(); // Consume the newline character left after reading the integer

        Main cipher = new Main(); // Create an instance of the Main class

        if (operation.equalsIgnoreCase("encrypt")) { // If the user chooses to encrypt
            String plaintext = scanner.nextLine(); // Read the plaintext from the user
            String encrypted = cipher.encrypt(plaintext, rails); // Encrypt the plaintext using the rail fence cipher
            System.out.println("Encrypted Message: " + encrypted); // Print the encrypted message
        } else if (operation.equalsIgnoreCase("decrypt")) { // If the user chooses to decrypt
            String ciphertext = scanner.nextLine(); // Read the ciphertext from the user
            String decrypted = cipher.decrypt(ciphertext, rails); // Decrypt the ciphertext using the rail fence cipher
            System.out.println("Decrypted Message: " + decrypted); // Print the decrypted message
        } else { // If the user enters an invalid operation
            System.out.println("Invalid operation. Please choose 'encrypt' or 'decrypt'."); // Print an error message
        }

        scanner.close(); // Close the Scanner to avoid resource leaks
    }
}
