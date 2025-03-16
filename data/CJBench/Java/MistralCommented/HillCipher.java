import java.util.Scanner;

// Class definition for Main
public class Main {

    // Method definition for encrypting a message using Hill Cipher algorithm
    public String encrypt(String message, int[][] keyMatrix) {

        // Convert message to uppercase and remove non-alphabetic characters
        message = message.toUpperCase().replaceAll("[^A-Z]", "");

        // Validate the size of the keyMatrix
        int matrixSize = keyMatrix.length;

        // Validate determinant of the keyMatrix
        validateDeterminant(keyMatrix, matrixSize);

        // Initialize StringBuilder for storing cipherText
        StringBuilder cipherText = new StringBuilder();

        // Initialize messageVector and cipherVector of size matrixSize
        int[] messageVector = new int[matrixSize];
        int[] cipherVector = new int[matrixSize];

        // Initialize index for iterating through message
        int index = 0;

        // Encrypt message character by character
        while (index < message.length()) {

            // Convert each character of message to its corresponding integer value
            for (int i = 0; i < matrixSize; i++) {
                if (index < message.length()) {
                    // Store the integer value of current character in messageVector
                    messageVector[i] = message.charAt(index++) - 'A';
                } else {
                    // If message is shorter than the keyMatrix, fill the remaining messageVector with 'X'
                    messageVector[i] = 'X' - 'A';
                }
            }

            // Multiply messageVector with keyMatrix and store the result in cipherVector
            for (int i = 0; i < matrixSize; i++) {
                cipherVector[i] = 0;
                for (int j = 0; j < matrixSize; j++) {
                    cipherVector[i] += keyMatrix[i][j] * messageVector[j];
                }
                // Perform modulo 26 operation on cipherVector to get the final cipherText character
                cipherVector[i] = cipherVector[i] % 26;
                // Append the final character to StringBuilder cipherText
                cipherText.append((char) (cipherVector[i] + 'A'));
            }
        }

        // Return the encrypted message as a String
        return cipherText.toString();
    }

    // Private method for validating determinant of keyMatrix
    private void validateDeterminant(int[][] keyMatrix, int n) {

        // Calculate the determinant of keyMatrix modulo 26
        int det = determinant(keyMatrix, n) % 26;

        // Check if determinant is zero or not coprime to 26
        if (det == 0 || gcd(det, 26) != 1) {
            // Throw an exception if determinant is invalid
            throw new IllegalArgumentException("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.");
        }
    }

    // Recursive method for calculating determinant of a matrix
    private int determinant(int[][] matrix, int n) {

        // Base case: determinant of a 1x1 matrix
        if (n == 1) {
            return matrix[0][0];
        }

        // Initialize sign, subMatrix and calculate determinant recursively
        int sign = 1;
        int[][] subMatrix = new int[n - 1][n - 1];
        int det = 0;

        // Calculate determinant of subMatrices and add to the final determinant
        for (int x = 0; x < n; x++) {
            int subI = 0;
            for (int i = 1; i < n; i++) {
                int subJ = 0;
                for (int j = 0; j < n; j++) {
                    if (j != x) {
                        // Store the subMatrix elements
                        subMatrix[subI][subJ++] = matrix[i][j];
                    }
                }
                subI++;
            }
            det += sign * matrix[0][x] * determinant(subMatrix, n - 1);
            sign = -sign;
        }

        // Return the final determinant
        return det;
    }

    // Helper method for calculating greatest common divisor
    private int gcd(int a, int b) {

        // Base case: if b is zero, return a
        if (b == 0) {
            return a;
        }

        // Recursive case: calculate gcd of b and the remainder of a modulo b
        return gcd(b, a % b);
    }

    // Main method for taking user input and calling encrypt method
    public static void main(String[] args) {

        // Initialize Scanner for user input
        Scanner scanner = new Scanner(System.in);

        // Get user operation and matrix size
        String operation = scanner.nextLine().toLowerCase();
        int matrixSize = scanner.nextInt();

        // Initialize keyMatrix with user input
        int[][] keyMatrix = new int[matrixSize][matrixSize];
        boolean validMatrix = false;

        // Validate user input for keyMatrix
        while (!validMatrix) {
            try {
                for (int i = 0; i < matrixSize; i++) {
                    for (int j = 0; j < matrixSize; j++) {
                        keyMatrix[i][j] = scanner.nextInt();
                    }
                    scanner.nextLine(); // consume newline character
                }
                new Main().validateDeterminant(keyMatrix, matrixSize);
                validMatrix = true;
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
                System.out.println("Please enter a valid matrix.");
                scanner.nextLine(); // consume error message and newline character
            }
        }

        // Perform encryption or decryption based on user operation
        if ("encrypt".equals(operation)) {
            scanner.nextLine(); // consume newline character
            String message = scanner.nextLine();
            String encryptedMessage = new Main().encrypt(message, keyMatrix);
            System.out.println("Encrypted Message: " + encryptedMessage);
        } else {
            System.out.println("Decryption functionality not implemented in this example.");
        }

        // Close Scanner
        scanner.close();
    }
}
