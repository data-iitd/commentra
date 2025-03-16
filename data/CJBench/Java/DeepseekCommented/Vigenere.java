import java.util.Scanner; // Importing Scanner for input operations

public class Main {
    // Encrypt method to encrypt the given message using the key
    public String encrypt(final String message, final String key) {
        if (key.isEmpty()) { // Check if the key is empty
            throw new IllegalArgumentException("Key cannot be empty."); // Throw an exception if key is empty
        }
        StringBuilder result = new StringBuilder(); // Initialize StringBuilder to build the encrypted message
        int j = 0; // Initialize key index
        for (int i = 0; i < message.length(); i++) { // Loop through each character in the message
            char c = message.charAt(i); // Get the current character
            if (Character.isLetter(c)) { // Check if the character is a letter
                if (Character.isUpperCase(c)) { // Check if the character is uppercase
                    result.append((char) ((c + key.toUpperCase().charAt(j) - 2 * 'A') % 26 + 'A')); // Encrypt uppercase character
                } else {
                    result.append((char) ((c + key.toLowerCase().charAt(j) - 2 * 'a') % 26 + 'a')); // Encrypt lowercase character
                }
                j = ++j % key.length(); // Update key index
            } else {
                result.append(c); // Append non-letter characters as they are
            }
        }
        return result.toString(); // Return the encrypted message
    }

    // Decrypt method to decrypt the given message using the key
    public String decrypt(final String message, final String key) {
        if (key.isEmpty()) { // Check if the key is empty
            throw new IllegalArgumentException("Key cannot be empty."); // Throw an exception if key is empty
        }
        StringBuilder result = new StringBuilder(); // Initialize StringBuilder to build the decrypted message
        int j = 0; // Initialize key index
        for (int i = 0; i < message.length(); i++) { // Loop through each character in the message
            char c = message.charAt(i); // Get the current character
            if (Character.isLetter(c)) { // Check if the character is a letter
                if (Character.isUpperCase(c)) { // Check if the character is uppercase
                    result.append((char) ('Z' - (25 - (c - key.toUpperCase().charAt(j))) % 26)); // Decrypt uppercase character
                } else {
                    result.append((char) ('z' - (25 - (c - key.toLowerCase().charAt(j))) % 26)); // Decrypt lowercase character
                }
                j = ++j % key.length(); // Update key index
            } else {
                result.append(c); // Append non-letter characters as they are
            }
        }
        return result.toString(); // Return the decrypted message
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize Scanner for input
        String operation = scanner.nextLine().toLowerCase(); // Read operation from user
        String key = scanner.nextLine(); // Read key from user
        if (operation.equals("encrypt")) { // Check if the operation is encrypt
            String plaintext = scanner.nextLine(); // Read plaintext message from user
            Main cipher = new Main(); // Create an instance of Main
            String encrypted = cipher.encrypt(plaintext, key); // Encrypt the plaintext message
            System.out.println("Encrypted Message: " + encrypted); // Print the encrypted message
        } else if (operation.equals("decrypt")) { // Check if the operation is decrypt
            String ciphertext = scanner.nextLine(); // Read ciphertext message from user
            Main cipher = new Main(); // Create an instance of Main
            String decrypted = cipher.decrypt(ciphertext, key); // Decrypt the ciphertext message
            System.out.println("Decrypted Message: " + decrypted); // Print the decrypted message
        } else {
            System.out.println("Invalid operation. Please choose 'encrypt' or 'decrypt'."); // Print error message for invalid operation
        }
        scanner.close(); // Close the Scanner
    }
}
