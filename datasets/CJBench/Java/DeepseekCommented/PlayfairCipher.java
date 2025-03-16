import java.util.Scanner;
public class Main {
    private char[][] matrix; // 2D array to store the Playfair cipher matrix
    private String key; // String to store the key for the cipher

    // Constructor to initialize the cipher with a key
    public Main(String key) {
        this.key = key;
        generateMatrix(); // Generate the 5x5 matrix using the key
    }

    // Method to encrypt the plaintext using the Playfair cipher algorithm
    public String encrypt(String plaintext) {
        plaintext = prepareText(plaintext.replace("J", "I")); // Prepare the plaintext
        StringBuilder ciphertext = new StringBuilder(); // StringBuilder to build the encrypted message
        for (int i = 0; i < plaintext.length(); i += 2) { // Process the plaintext in pairs
            char char1 = plaintext.charAt(i);
            char char2 = plaintext.charAt(i + 1);
            int[] pos1 = findPosition(char1); // Find the position of char1 in the matrix
            int[] pos2 = findPosition(char2); // Find the position of char2 in the matrix
            int row1 = pos1[0];
            int col1 = pos1[1];
            int row2 = pos2[0];
            int col2 = pos2[1];
            if (row1 == row2) { // If characters are in the same row
                ciphertext.append(matrix[row1][(col1 + 1) % 5]); // Shift right within the row
                ciphertext.append(matrix[row2][(col2 + 1) % 5]); // Shift right within the row
            } else if (col1 == col2) { // If characters are in the same column
                ciphertext.append(matrix[(row1 + 1) % 5][col1]); // Shift down within the column
                ciphertext.append(matrix[(row2 + 1) % 5][col2]); // Shift down within the column
            } else { // If characters form a rectangle in the matrix
                ciphertext.append(matrix[row1][col2]); // Swap columns
                ciphertext.append(matrix[row2][col1]); // Swap columns
            }
        }
        return ciphertext.toString(); // Return the encrypted message
    }

    // Method to decrypt the ciphertext using the Playfair cipher algorithm
    public String decrypt(String ciphertext) {
        StringBuilder plaintext = new StringBuilder(); // StringBuilder to build the decrypted message
        for (int i = 0; i < ciphertext.length(); i += 2) { // Process the ciphertext in pairs
            char char1 = ciphertext.charAt(i);
            char char2 = ciphertext.charAt(i + 1);
            int[] pos1 = findPosition(char1); // Find the position of char1 in the matrix
            int[] pos2 = findPosition(char2); // Find the position of char2 in the matrix
            int row1 = pos1[0];
            int col1 = pos1[1];
            int row2 = pos2[0];
            int col2 = pos2[1];
            if (row1 == row2) { // If characters are in the same row
                plaintext.append(matrix[row1][(col1 + 4) % 5]); // Shift left within the row
                plaintext.append(matrix[row2][(col2 + 4) % 5]); // Shift left within the row
            } else if (col1 == col2) { // If characters are in the same column
                plaintext.append(matrix[(row1 + 4) % 5][col1]); // Shift up within the column
                plaintext.append(matrix[(row2 + 4) % 5][col2]); // Shift up within the column
            } else { // If characters form a rectangle in the matrix
                plaintext.append(matrix[row1][col2]); // Swap columns
                plaintext.append(matrix[row2][col1]); // Swap columns
            }
        }
        return plaintext.toString(); // Return the decrypted message
    }

    // Private method to generate the 5x5 matrix using the key
    private void generateMatrix() {
        String keyWithoutDuplicates = removeDuplicateChars(key + "ABCDEFGHIKLMNOPQRSTUVWXYZ"); // Remove duplicates from the key
        matrix = new char[5][5]; // Initialize the matrix
        int index = 0;
        for (int i = 0; i < 5; i++) { // Fill the matrix row by row
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = keyWithoutDuplicates.charAt(index);
                index++;
            }
        }
    }

    // Private method to remove duplicate characters from a string
    private String removeDuplicateChars(String str) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            if (result.indexOf(String.valueOf(str.charAt(i))) == -1) { // Check if the character is already in the result
                result.append(str.charAt(i));
            }
        }
        return result.toString(); // Return the string without duplicates
    }

    // Private method to prepare the plaintext for encryption
    private String prepareText(String text) {
        text = text.toUpperCase().replaceAll("[^A-Z]", ""); // Convert to uppercase and remove non-alphabetic characters
        StringBuilder preparedText = new StringBuilder();
        char prevChar = '\0';
        for (char c : text.toCharArray()) { // Process each character
            if (c != prevChar) { // If the character is not a repeat
                preparedText.append(c);
                prevChar = c;
            } else { // If the character is a repeat
                preparedText.append('X').append(c);
                prevChar = '\0';
            }
        }
        if (preparedText.length() % 2 != 0) { // If the length of the prepared text is odd
            preparedText.append('X'); // Append an 'X' to make it even
        }
        return preparedText.toString(); // Return the prepared text
    }

    // Private method to find the position of a character in the matrix
    private int[] findPosition(char c) {
        int[] pos = new int[2];
        for (int i = 0; i < 5; i++) { // Iterate through the matrix rows
            for (int j = 0; j < 5; j++) { // Iterate through the matrix columns
                if (matrix[i][j] == c) { // If the character is found in the matrix
                    pos[0] = i; // Set the row position
                    pos[1] = j; // Set the column position
                    return pos; // Return the position
                }
            }
        }
        return pos; // Return the position (should never reach here)
    }

    // Main method to run the Playfair cipher application
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner to read user input
        String key = scanner.nextLine(); // Read the key from the user
        Main playfairCipher = new Main(key); // Create an instance of the Playfair cipher with the key
        String operation = scanner.nextLine(); // Read the operation (encrypt/decrypt) from the user
        if (operation.equalsIgnoreCase("encrypt")) { // If the operation is encrypt
            String plaintext = scanner.nextLine(); // Read the plaintext from the user
            String encryptedMessage = playfairCipher.encrypt(plaintext); // Encrypt the plaintext
            System.out.println("Encrypted Message: " + encryptedMessage); // Print the encrypted message
        } else if (operation.equalsIgnoreCase("decrypt")) { // If the operation is decrypt
            String ciphertext = scanner.nextLine(); // Read the ciphertext from the user
            String decryptedMessage = playfairCipher.decrypt(ciphertext); // Decrypt the ciphertext
            System.out.println("Decrypted Message: " + decryptedMessage); // Print the decrypted message
        } else { // If the operation is invalid
            System.out.println("Invalid operation. Please enter 'encrypt' or 'decrypt'."); // Print an error message
        }
        scanner.close(); // Close the scanner
    }
}
