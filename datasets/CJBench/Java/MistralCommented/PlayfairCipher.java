
import java.util.Scanner;

public class Main {
    // Declare a private 2D character array 'matrix' and a private String 'key'
    private char[][] matrix;
    private String key;

    // Constructor that initializes the 'key' and generates the 'matrix'
    public Main(String key) {
        this.key = key;
        generateMatrix();
    }

    // Encrypts the given plaintext using the Playfair Cipher algorithm
    public String encrypt(String plaintext) {
        // Prepare the plaintext for encryption by converting it to uppercase and removing non-alphabetic characters
        plaintext = prepareText(plaintext.replace("J", "I"));

        // Initialize an empty StringBuilder for storing the encrypted characters
        StringBuilder ciphertext = new StringBuilder();

        // Iterate through the plaintext in pairs of two characters
        for (int i = 0; i < plaintext.length(); i += 2) {
            char char1 = plaintext.charAt(i);
            char char2 = plaintext.charAt(i + 1);

            // Find the positions of 'char1' and 'char2' in the 'matrix'
            int[] pos1 = findPosition(char1);
            int[] pos2 = findPosition(char2);

            // Determine the encryption rule based on the positions of 'char1' and 'char2'
            int row1 = pos1[0];
            int col1 = pos1[1];
            int row2 = pos2[0];
            int col2 = pos2[1];

            if (row1 == row2) {
                // If the characters are in the same row, apply the first rule
                ciphertext.append(matrix[row1][(col1 + 1) % 5]);
                ciphertext.append(matrix[row2][(col2 + 1) % 5]);
                // Add comments for the first rule
                // If both characters are in the same row, swap their columns and get the next character from their respective columns
            } else if (col1 == col2) {
                // If the characters are in the same column, apply the second rule
                ciphertext.append(matrix[(row1 + 1) % 5][col1]);
                ciphertext.append(matrix[(row2 + 1) % 5][col2]);
                // Add comments for the second rule
                // If both characters are in the same column, swap their rows and get the next character from their respective rows
            } else {
                // If the characters are not in the same row or column, apply the third rule
                ciphertext.append(matrix[row1][col2]);
                ciphertext.append(matrix[row2][col1]);
                // Add comments for the third rule
                // If the characters are not in the same row or column, swap their positions and get the next character from their respective positions
            }
        }

        // Return the encrypted message as a String
        return ciphertext.toString();
    }

    // Decrypts the given ciphertext using the Playfair Cipher algorithm
    public String decrypt(String ciphertext) {
        // Initialize an empty StringBuilder for storing the decrypted characters
        StringBuilder plaintext = new StringBuilder();

        // Iterate through the ciphertext in pairs of two characters
        for (int i = 0; i < ciphertext.length(); i += 2) {
            char char1 = ciphertext.charAt(i);
            char char2 = ciphertext.charAt(i + 1);

            // Find the positions of 'char1' and 'char2' in the 'matrix'
            int[] pos1 = findPosition(char1);
            int[] pos2 = findPosition(char2);

            // Determine the decryption rule based on the positions of 'char1' and 'char2'
            int row1 = pos1[0];
            int col1 = pos1[1];
            int row2 = pos2[0];
            int col2 = pos2[1];

            if (row1 == row2) {
                // If the characters are in the same row, apply the first rule
                plaintext.append(matrix[row1][(col1 + 4) % 5]);
                plaintext.append(matrix[row2][(col2 + 4) % 5]);
                // Add comments for the first rule
                // If both characters are in the same row, swap their columns and get the next character from their respective columns, but this time from the opposite sides
            } else if (col1 == col2) {
                // If the characters are in the same column, apply the second rule
                plaintext.append(matrix[(row1 + 4) % 5][col1]);
                plaintext.append(matrix[(row2 + 4) % 5][col2]);
                // Add comments for the second rule
                // If both characters are in the same column, swap their rows and get the next character from their respective rows, but this time from the opposite sides
            } else {
                // If the characters are not in the same row or column, apply the third rule
                plaintext.append(matrix[row1][col2]);
                plaintext.append(matrix[row2][col1]);
                // Add comments for the third rule
                // If the characters are not in the same row or column, swap their positions and get the next character from their respective positions, but this time from the opposite sides
            }
        }

        // Return the decrypted message as a String
        return plaintext.toString();
    }

    // Generates the 'matrix' based on the given 'key'
    private void generateMatrix() {
        // Remove duplicate characters from the 'key' and 'matrix'
        String keyWithoutDuplicates = removeDuplicateChars(key + "ABCDEFGHIKLMNOPQRSTUVWXYZ");

        // Initialize the 'matrix' with the given size
        matrix = new char[5][5];

        // Populate the 'matrix' with the unique characters from the 'key'
        int index = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = keyWithoutDuplicates.charAt(index);
                index++;
            }
        }
    }

    // Removes duplicate characters from the given String
    private String removeDuplicateChars(String str) {
        // Initialize an empty StringBuilder for storing the unique characters
        StringBuilder result = new StringBuilder();

        // Iterate through the characters in the given String
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);

            // If the character is not already in the StringBuilder, add it
            if (result.indexOf(String.valueOf(c)) == -1) {
                result.append(c);
            }
        }

        // Return the StringBuilder as a String
        return result.toString();
    }

    // Prepares the given text for encryption by converting it to uppercase and removing non-alphabetic characters
    private String prepareText(String text) {
        // Convert the text to uppercase
        text = text.toUpperCase();

        // Remove non-alphabetic characters and replace 'J' with 'I'
        text = text.replaceAll("[^A-Z]", "");
        text = text.replace("J", "I");

        // Initialize an empty StringBuilder for storing the prepared text
        StringBuilder preparedText = new StringBuilder();

        // Iterate through the characters in the prepared text
        char prevChar = '\0';
        for (char c : text.toCharArray()) {
            // If the character is different from the previous character, add it to the StringBuilder
            if (c != prevChar) {
                preparedText.append(c);
                prevChar = c;
            } else {
                // If the character is the same as the previous character, add 'X' and the character to the StringBuilder
                preparedText.append('X').append(c);
                prevChar = '\0';
            }
        }

        // If the length of the prepared text is odd, add an extra 'X' at the end
        if (preparedText.length() % 2 != 0) {
            preparedText.append('X');
        }

        // Return the prepared text as a String
        return preparedText.toString();
    }

    // Finds the positions of the given character in the 'matrix'
    private int[] findPosition(char c) {
        // Initialize an empty integer array for storing the positions
        int[] pos = new int[2];

        // Iterate through the rows and columns of the 'matrix'
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                // If the character is found, store its position in the integer array and return it
                if (matrix[i][j] == c) {
                    pos[0] = i;
                    pos[1] = j;
                    return pos;
                }
            }
        }

        // If the character is not found, return an empty integer array
        return pos;
    }

    // Main method for running the program
    public static void main(String[] args) {
        // Initialize a Scanner for reading user input
        Scanner scanner = new Scanner(System.in);

        // Read the 'key' from the user
        String key = scanner.nextLine();

        // Create an instance of the 'Main' class with the given 'key'
        Main playfairCipher = new Main(key);

        // Read the operation ('encrypt' or 'decrypt') from the user
        String operation = scanner.nextLine();

        // Read the plaintext or ciphertext from the user based on the operation
        if (operation.equalsIgnoreCase("encrypt")) {
            String plaintext = scanner.nextLine();
            String encryptedMessage = playfairCipher.encrypt(plaintext);
            System.out.println("Encrypted Message: " + encryptedMessage);
        } else if (operation.equalsIgnoreCase("decrypt")) {
            String ciphertext = scanner.nextLine();
            String decryptedMessage = playfairCipher.decrypt(ciphertext);
            System.out.println("Decrypted Message: " + decryptedMessage);
        } else {
            System.out.println("Invalid operation. Please enter 'encrypt' or 'decrypt'.");
        }

        // Close the Scanner
        scanner.close();
    }
}