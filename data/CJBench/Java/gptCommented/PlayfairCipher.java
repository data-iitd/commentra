import java.util.Scanner;

public class Main {
    // 2D array to hold the Playfair cipher matrix
    private char[][] matrix;
    // Key used for generating the cipher matrix
    private String key;

    // Constructor to initialize the key and generate the cipher matrix
    public Main(String key) {
        this.key = key;
        generateMatrix();
    }

    // Method to encrypt the plaintext using the Playfair cipher
    public String encrypt(String plaintext) {
        // Prepare the plaintext by replacing 'J' with 'I' and formatting it
        plaintext = prepareText(plaintext.replace("J", "I"));
        StringBuilder ciphertext = new StringBuilder();

        // Process the plaintext in pairs of characters
        for (int i = 0; i < plaintext.length(); i += 2) {
            char char1 = plaintext.charAt(i);
            char char2 = plaintext.charAt(i + 1);
            // Find positions of the characters in the matrix
            int[] pos1 = findPosition(char1);
            int[] pos2 = findPosition(char2);
            int row1 = pos1[0];
            int col1 = pos1[1];
            int row2 = pos2[0];
            int col2 = pos2[1];

            // Apply Playfair cipher rules based on the positions of the characters
            if (row1 == row2) {
                // Same row: shift right
                ciphertext.append(matrix[row1][(col1 + 1) % 5]);
                ciphertext.append(matrix[row2][(col2 + 1) % 5]);
            } else if (col1 == col2) {
                // Same column: shift down
                ciphertext.append(matrix[(row1 + 1) % 5][col1]);
                ciphertext.append(matrix[(row2 + 1) % 5][col2]);
            } else {
                // Rectangle: swap columns
                ciphertext.append(matrix[row1][col2]);
                ciphertext.append(matrix[row2][col1]);
            }
        }
        return ciphertext.toString(); // Return the final ciphertext
    }

    // Method to decrypt the ciphertext using the Playfair cipher
    public String decrypt(String ciphertext) {
        StringBuilder plaintext = new StringBuilder();

        // Process the ciphertext in pairs of characters
        for (int i = 0; i < ciphertext.length(); i += 2) {
            char char1 = ciphertext.charAt(i);
            char char2 = ciphertext.charAt(i + 1);
            // Find positions of the characters in the matrix
            int[] pos1 = findPosition(char1);
            int[] pos2 = findPosition(char2);
            int row1 = pos1[0];
            int col1 = pos1[1];
            int row2 = pos2[0];
            int col2 = pos2[1];

            // Apply Playfair cipher rules based on the positions of the characters
            if (row1 == row2) {
                // Same row: shift left
                plaintext.append(matrix[row1][(col1 + 4) % 5]);
                plaintext.append(matrix[row2][(col2 + 4) % 5]);
            } else if (col1 == col2) {
                // Same column: shift up
                plaintext.append(matrix[(row1 + 4) % 5][col1]);
                plaintext.append(matrix[(row2 + 4) % 5][col2]);
            } else {
                // Rectangle: swap columns
                plaintext.append(matrix[row1][col2]);
                plaintext.append(matrix[row2][col1]);
            }
        }
        return plaintext.toString(); // Return the final plaintext
    }

    // Method to generate the Playfair cipher matrix based on the key
    private void generateMatrix() {
        // Remove duplicate characters from the key and append the alphabet
        String keyWithoutDuplicates = removeDuplicateChars(key + "ABCDEFGHIKLMNOPQRSTUVWXYZ");
        matrix = new char[5][5]; // Initialize the 5x5 matrix
        int index = 0;

        // Fill the matrix with characters from the key
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = keyWithoutDuplicates.charAt(index);
                index++;
            }
        }
    }

    // Method to remove duplicate characters from a string
    private String removeDuplicateChars(String str) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            // Append character if it is not already in the result
            if (result.indexOf(String.valueOf(str.charAt(i))) == -1) {
                result.append(str.charAt(i));
            }
        }
        return result.toString(); // Return the string without duplicates
    }

    // Method to prepare the text for encryption/decryption
    private String prepareText(String text) {
        // Convert text to uppercase and remove non-alphabetic characters
        text = text.toUpperCase().replaceAll("[^A-Z]", "");
        StringBuilder preparedText = new StringBuilder();
        char prevChar = '\0';

        // Process characters to avoid duplicates and ensure even length
        for (char c : text.toCharArray()) {
            if (c != prevChar) {
                preparedText.append(c);
                prevChar = c;
            } else {
                preparedText.append('X').append(c); // Insert 'X' between duplicates
                prevChar = '\0';
            }
        }
        // Append 'X' if the length is odd
        if (preparedText.length() % 2 != 0) {
            preparedText.append('X');
        }
        return preparedText.toString(); // Return the prepared text
    }

    // Method to find the position of a character in the matrix
    private int[] findPosition(char c) {
        int[] pos = new int[2];
        // Search the matrix for the character
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (matrix[i][j] == c) {
                    pos[0] = i; // Row index
                    pos[1] = j; // Column index
                    return pos; // Return the position
                }
            }
        }
        return pos; // Return default position if not found
    }

    // Main method to run the Playfair cipher program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the key from user input
        String key = scanner.nextLine();
        Main playfairCipher = new Main(key); // Create an instance of Main with the key
        // Read the operation (encrypt/decrypt) from user input
        String operation = scanner.nextLine();
        
        // Perform encryption or decryption based on user input
        if (operation.equalsIgnoreCase("encrypt")) {
            String plaintext = scanner.nextLine(); // Read plaintext
            String encryptedMessage = playfairCipher.encrypt(plaintext); // Encrypt the plaintext
            System.out.println("Encrypted Message: " + encryptedMessage); // Output the encrypted message
        } else if (operation.equalsIgnoreCase("decrypt")) {
            String ciphertext = scanner.nextLine(); // Read ciphertext
            String decryptedMessage = playfairCipher.decrypt(ciphertext); // Decrypt the ciphertext
            System.out.println("Decrypted Message: " + decryptedMessage); // Output the decrypted message
        } else {
            // Handle invalid operation input
            System.out.println("Invalid operation. Please enter 'encrypt' or 'decrypt'.");
        }
        scanner.close(); // Close the scanner
    }
}
