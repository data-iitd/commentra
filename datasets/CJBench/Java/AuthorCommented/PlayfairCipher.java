
import java.util.Scanner;

/**
 * This program implements the Playfair Cipher encryption and decryption algorithm.
 * The Playfair Cipher is a digraph substitution cipher that encrypts pairs of letters
 * based on their positions in a 5x5 matrix generated from a given key.
 */
public class PlayfairCipher {

    private char[][] matrix;
    private String key;

    // Constructor to initialize the cipher with a key and generate the matrix
    public PlayfairCipher(String key) {
        this.key = key;
        generateMatrix();
    }

    /**
     * Encrypts the given plaintext using the Playfair Cipher.
     *
     * @param plaintext The text to encrypt.
     * @return The encrypted ciphertext.
     */
    public String encrypt(String plaintext) {
        plaintext = prepareText(plaintext.replace("J", "I"));
        StringBuilder ciphertext = new StringBuilder();

        // Process pairs of characters
        for (int i = 0; i < plaintext.length(); i += 2) {
            char char1 = plaintext.charAt(i);
            char char2 = plaintext.charAt(i + 1);
            int[] pos1 = findPosition(char1);
            int[] pos2 = findPosition(char2);
            int row1 = pos1[0];
            int col1 = pos1[1];
            int row2 = pos2[0];
            int col2 = pos2[1];
            if (row1 == row2) {
                ciphertext.append(matrix[row1][(col1 + 1) % 5]);
                ciphertext.append(matrix[row2][(col2 + 1) % 5]);
            } else if (col1 == col2) {
                ciphertext.append(matrix[(row1 + 1) % 5][col1]);
                ciphertext.append(matrix[(row2 + 1) % 5][col2]);
            } else {
                ciphertext.append(matrix[row1][col2]);
                ciphertext.append(matrix[row2][col1]);
            }
        }
        return ciphertext.toString();
    }

    /**
     * Decrypts the given ciphertext using the Playfair Cipher.
     *
     * @param ciphertext The text to decrypt.
     * @return The decrypted plaintext.
     */
    public String decrypt(String ciphertext) {
        StringBuilder plaintext = new StringBuilder();

        // Process pairs of characters
        for (int i = 0; i < ciphertext.length(); i += 2) {
            char char1 = ciphertext.charAt(i);
            char char2 = ciphertext.charAt(i + 1);
            int[] pos1 = findPosition(char1);
            int[] pos2 = findPosition(char2);
            int row1 = pos1[0];
            int col1 = pos1[1];
            int row2 = pos2[0];
            int col2 = pos2[1];
            if (row1 == row2) {
                plaintext.append(matrix[row1][(col1 + 4) % 5]);
                plaintext.append(matrix[row2][(col2 + 4) % 5]);
            } else if (col1 == col2) {
                plaintext.append(matrix[(row1 + 4) % 5][col1]);
                plaintext.append(matrix[(row2 + 4) % 5][col2]);
            } else {
                plaintext.append(matrix[row1][col2]);
                plaintext.append(matrix[row2][col1]);
            }
        }
        return plaintext.toString();
    }

    /**
     * Generates the 5x5 matrix using the key.
     */
    private void generateMatrix() {
        String keyWithoutDuplicates = removeDuplicateChars(key + "ABCDEFGHIKLMNOPQRSTUVWXYZ");
        matrix = new char[5][5];
        int index = 0;

        // Fill the matrix row by row
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = keyWithoutDuplicates.charAt(index);
                index++;
            }
        }
    }

    /**
     * Removes duplicate characters from the input string.
     *
     * @param str The input string.
     * @return A string with duplicates removed.
     */
    private String removeDuplicateChars(String str) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            if (result.indexOf(String.valueOf(str.charAt(i))) == -1) {
                result.append(str.charAt(i));
            }
        }
        return result.toString();
    }

    /**
     * Prepares the input text by converting to uppercase, removing non-alphabetic characters,
     * and handling repeated letters.
     *
     * @param text The input text.
     * @return The prepared text.
     */
    private String prepareText(String text) {
        text = text.toUpperCase().replaceAll("[^A-Z]", "");
        StringBuilder preparedText = new StringBuilder();
        char prevChar = '\0';
        for (char c : text.toCharArray()) {
            if (c != prevChar) {
                preparedText.append(c);
                prevChar = c;
            } else {
                preparedText.append('X').append(c);
                prevChar = '\0';
            }
        }
        if (preparedText.length() % 2 != 0) {
            preparedText.append('X');
        }
        return preparedText.toString();
    }

    /**
     * Finds the position of a character in the 5x5 matrix.
     *
     * @param c The character to find.
     * @return An array with row and column indices.
     */
    private int[] findPosition(char c) {
        int[] pos = new int[2];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (matrix[i][j] == c) {
                    pos[0] = i;
                    pos[1] = j;
                    return pos;
                }
            }
        }
        return pos;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String key = scanner.nextLine();

        PlayfairCipher playfairCipher = new PlayfairCipher(key);

        String operation = scanner.nextLine();

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

        scanner.close();
    }
}
