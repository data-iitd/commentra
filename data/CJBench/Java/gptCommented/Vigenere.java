import java.util.Scanner;

public class Main {
    // Method to encrypt a given message using a specified key
    public String encrypt(final String message, final String key) {
        // Check if the key is empty and throw an exception if it is
        if (key.isEmpty()) {
            throw new IllegalArgumentException("Key cannot be empty.");
        }
        
        // StringBuilder to hold the encrypted result
        StringBuilder result = new StringBuilder();
        int j = 0; // Index for the key
        
        // Iterate through each character of the message
        for (int i = 0; i < message.length(); i++) {
            char c = message.charAt(i);
            // Check if the character is a letter
            if (Character.isLetter(c)) {
                // Encrypt uppercase letters
                if (Character.isUpperCase(c)) {
                    result.append((char) ((c + key.toUpperCase().charAt(j) - 2 * 'A') % 26 + 'A'));
                } else { // Encrypt lowercase letters
                    result.append((char) ((c + key.toLowerCase().charAt(j) - 2 * 'a') % 26 + 'a'));
                }
                // Move to the next character in the key, wrapping around if necessary
                j = ++j % key.length();
            } else {
                // If not a letter, append the character as is
                result.append(c);
            }
        }
        // Return the encrypted message as a string
        return result.toString();
    }

    // Method to decrypt a given message using a specified key
    public String decrypt(final String message, final String key) {
        // Check if the key is empty and throw an exception if it is
        if (key.isEmpty()) {
            throw new IllegalArgumentException("Key cannot be empty.");
        }
        
        // StringBuilder to hold the decrypted result
        StringBuilder result = new StringBuilder();
        int j = 0; // Index for the key
        
        // Iterate through each character of the message
        for (int i = 0; i < message.length(); i++) {
            char c = message.charAt(i);
            // Check if the character is a letter
            if (Character.isLetter(c)) {
                // Decrypt uppercase letters
                if (Character.isUpperCase(c)) {
                    result.append((char) ('Z' - (25 - (c - key.toUpperCase().charAt(j))) % 26));
                } else { // Decrypt lowercase letters
                    result.append((char) ('z' - (25 - (c - key.toLowerCase().charAt(j))) % 26));
                }
                // Move to the next character in the key, wrapping around if necessary
                j = ++j % key.length();
            } else {
                // If not a letter, append the character as is
                result.append(c);
            }
        }
        // Return the decrypted message as a string
        return result.toString();
    }

    // Main method to execute the program
    public static void main(String[] args) {
        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);
        
        // Read the operation type (encrypt or decrypt)
        String operation = scanner.nextLine().toLowerCase();
        
        // Read the key for encryption/decryption
        String key = scanner.nextLine();
        
        // Perform encryption if the operation is "encrypt"
        if (operation.equals("encrypt")) {
            String plaintext = scanner.nextLine(); // Read the plaintext message
            Main cipher = new Main(); // Create an instance of Main
            String encrypted = cipher.encrypt(plaintext, key); // Encrypt the message
            System.out.println("Encrypted Message: " + encrypted); // Output the encrypted message
        } 
        // Perform decryption if the operation is "decrypt"
        else if (operation.equals("decrypt")) {
            String ciphertext = scanner.nextLine(); // Read the ciphertext message
            Main cipher = new Main(); // Create an instance of Main
            String decrypted = cipher.decrypt(ciphertext, key); // Decrypt the message
            System.out.println("Decrypted Message: " + decrypted); // Output the decrypted message
        } 
        // Handle invalid operation input
        else {
            System.out.println("Invalid operation. Please choose 'encrypt' or 'decrypt'.");
        }
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
