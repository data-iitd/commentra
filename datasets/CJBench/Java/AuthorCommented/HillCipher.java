
import java.util.Scanner;

/**
 * This class implements the Hill Cipher for encryption.
 * The Hill Cipher uses a square matrix (key matrix) to encrypt a message.
 */
public class HillCipher {

    /**
     * Encrypts the message using the key matrix.
     * 
     * @param message   The plaintext message to be encrypted.
     * @param keyMatrix The key matrix used for encryption.
     * @return The encrypted message (ciphertext).
     */
    public String encrypt(String message, int[][] keyMatrix) {
        // Convert the message to uppercase and remove all non-alphabetic characters
        message = message.toUpperCase().replaceAll("[^A-Z]", "");
        int matrixSize = keyMatrix.length;

        // Validate that the key matrix has a valid determinant for Hill Cipher
        validateDeterminant(keyMatrix, matrixSize);

        StringBuilder cipherText = new StringBuilder();
        int[] messageVector = new int[matrixSize];
        int[] cipherVector = new int[matrixSize];
        int index = 0;

        // Process the message in blocks of size equal to the key matrix size
        while (index < message.length()) {
            for (int i = 0; i < matrixSize; i++) {
                if (index < message.length()) {
                    messageVector[i] = message.charAt(index++) - 'A';
                } else {
                    messageVector[i] = 'X' - 'A'; // Padding with 'X' if needed
                }
            }

            // Encrypt the message vector using the key matrix
            for (int i = 0; i < matrixSize; i++) {
                cipherVector[i] = 0;
                for (int j = 0; j < matrixSize; j++) {
                    cipherVector[i] += keyMatrix[i][j] * messageVector[j];
                }
                cipherVector[i] = cipherVector[i] % 26;
                cipherText.append((char) (cipherVector[i] + 'A'));
            }
        }

        return cipherText.toString();
    }

    /**
     * Validates that the determinant of the key matrix is valid for Hill Cipher encryption.
     * 
     * @param keyMatrix The key matrix.
     * @param n         The size of the matrix.
     */
    private void validateDeterminant(int[][] keyMatrix, int n) {
        int det = determinant(keyMatrix, n) % 26;
        if (det == 0 || gcd(det, 26) != 1) {
            throw new IllegalArgumentException("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.");
        }
    }

    /**
     * Recursively computes the determinant of a matrix.
     * 
     * @param matrix The matrix whose determinant is to be calculated.
     * @param n      The size of the matrix.
     * @return The determinant of the matrix.
     */
    private int determinant(int[][] matrix, int n) {
        int det = 0;
        if (n == 1) {
            return matrix[0][0];
        }
        int sign = 1;
        int[][] subMatrix = new int[n - 1][n - 1];
        for (int x = 0; x < n; x++) {
            int subI = 0;
            for (int i = 1; i < n; i++) {
                int subJ = 0;
                for (int j = 0; j < n; j++) {
                    if (j != x) {
                        subMatrix[subI][subJ++] = matrix[i][j];
                    }
                }
                subI++;
            }
            det += sign * matrix[0][x] * determinant(subMatrix, n - 1);
            sign = -sign;
        }
        return det;
    }

    /**
     * Computes the GCD (Greatest Common Divisor) of two integers using the Euclidean algorithm.
     * 
     * @param a The first integer.
     * @param b The second integer.
     * @return The GCD of a and b.
     */
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HillCipher hillCipher = new HillCipher();

        String operation = scanner.nextLine().toLowerCase();

        int matrixSize = scanner.nextInt();
        int[][] keyMatrix = new int[matrixSize][matrixSize];

        boolean validMatrix = false;
        while (!validMatrix) {
            try {
                for (int i = 0; i < matrixSize; i++) {
                    for (int j = 0; j < matrixSize; j++) {
                        keyMatrix[i][j] = scanner.nextInt();
                    }
                }
                hillCipher.validateDeterminant(keyMatrix, matrixSize);
                validMatrix = true;
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
                System.out.println("Please enter a valid matrix.");
            }
        }

        if ("encrypt".equals(operation)) {
            scanner.nextLine(); // Consume leftover newline
            String message = scanner.nextLine();
            String encryptedMessage = hillCipher.encrypt(message, keyMatrix);
            System.out.println("Encrypted Message: " + encryptedMessage);
        } else {
            System.out.println("Decryption functionality not implemented in this example.");
        }

        scanner.close();
    }
}
