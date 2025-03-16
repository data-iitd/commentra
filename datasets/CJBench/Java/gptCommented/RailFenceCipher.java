import java.util.Arrays;
import java.util.Scanner;

public class Main {
    
    // Method to encrypt a given string using the Rail Fence cipher technique
    public String encrypt(String str, int rails) {
        // If only one rail or the number of rails is greater than or equal to the string length, return the original string
        if (rails == 1 || rails >= str.length()) {
            return str;
        }
        
        // Variable to determine the direction of movement (down or up the rails)
        boolean down = true;
        
        // Create a 2D array to represent the rails
        char[][] strRail = new char[rails][str.length()];
        
        // Initialize the rail array with newline characters
        for (int i = 0; i < rails; i++) {
            Arrays.fill(strRail[i], '\n');
        }
        
        // Variables to track the current position in the rail
        int row = 0, col = 0, i = 0;
        
        // Fill the rail array with characters from the input string
        while (col < str.length()) {
            // Change direction at the top and bottom rails
            if (row == 0) {
                down = true;
            } else if (row == rails - 1) {
                down = false;
            }
            
            // Place the character in the current rail position
            strRail[row][col] = str.charAt(i++);
            col++;
            
            // Move up or down the rails based on the current direction
            if (down) {
                row++;
            } else {
                row--;
            }
        }
        
        // Build the encrypted string from the rail array
        StringBuilder encryptedString = new StringBuilder();
        for (char[] chRow : strRail) {
            for (char ch : chRow) {
                // Append only non-newline characters to the result
                if (ch != '\n') {
                    encryptedString.append(ch);
                }
            }
        }
        
        // Return the final encrypted string
        return encryptedString.toString();
    }
    
    // Method to decrypt a given string using the Rail Fence cipher technique
    public String decrypt(String str, int rails) {
        // If only one rail or the number of rails is greater than or equal to the string length, return the original string
        if (rails == 1 || rails >= str.length()) {
            return str;
        }
        
        // Variable to determine the direction of movement (down or up the rails)
        boolean down = true;
        
        // Create a 2D array to represent the rails
        char[][] strRail = new char[rails][str.length()];
        
        // Variables to track the current position in the rail
        int row = 0, col = 0;
        
        // Mark the positions in the rail array where characters will be placed
        while (col < str.length()) {
            // Change direction at the top and bottom rails
            if (row == 0) {
                down = true;
            } else if (row == rails - 1) {
                down = false;
            }
            
            // Mark the current position with a placeholder
            strRail[row][col] = '*';
            col++;
            
            // Move up or down the rails based on the current direction
            if (down) {
                row++;
            } else {
                row--;
            }
        }
        
        // Fill the rail array with characters from the input string based on marked positions
        int index = 0;
        for (int i = 0; i < rails; i++) {
            for (int j = 0; j < str.length(); j++) {
                // Replace placeholders with actual characters from the input string
                if (strRail[i][j] == '*') {
                    strRail[i][j] = str.charAt(index++);
                }
            }
        }
        
        // Build the decrypted string from the rail array
        StringBuilder decryptedString = new StringBuilder();
        row = 0;
        col = 0;
        
        // Read characters from the rail array to form the decrypted string
        while (col < str.length()) {
            // Change direction at the top and bottom rails
            if (row == 0) {
                down = true;
            } else if (row == rails - 1) {
                down = false;
            }
            
            // Append the character at the current rail position to the result
            decryptedString.append(strRail[row][col]);
            col++;
            
            // Move up or down the rails based on the current direction
            if (down) {
                row++;
            } else {
                row--;
            }
        }
        
        // Return the final decrypted string
        return decryptedString.toString();
    }
    
    // Main method to execute the program
    public static void main(String[] args) {
        // Create a scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the operation type (encrypt or decrypt) and the number of rails
        String operation = scanner.next();
        int rails = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Perform encryption or decryption based on user input
        if (operation.equalsIgnoreCase("encrypt")) {
            String plaintext = scanner.nextLine(); // Read the plaintext to encrypt
            Main cipher = new Main(); // Create an instance of the Main class
            String encrypted = cipher.encrypt(plaintext, rails); // Encrypt the plaintext
            System.out.println("Encrypted Message: " + encrypted); // Output the encrypted message
        } else if (operation.equalsIgnoreCase("decrypt")) {
            String ciphertext = scanner.nextLine(); // Read the ciphertext to decrypt
            Main cipher = new Main(); // Create an instance of the Main class
            String decrypted = cipher.decrypt(ciphertext, rails); // Decrypt the ciphertext
            System.out.println("Decrypted Message: " + decrypted); // Output the decrypted message
        } else {
            // Handle invalid operation input
            System.out.println("Invalid operation. Please choose 'encrypt' or 'decrypt'.");
        }
        
        // Close the scanner to free resources
        scanner.close();
    }
}
