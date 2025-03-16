import java.util.Scanner;

public class Main {
    // Method to encrypt a message using a key matrix
    public String encrypt(String message, int[][] keyMatrix) {
        // Convert the message to uppercase and remove non-alphabetic characters
        message = message.toUpperCase().replaceAll("[^A-Z]", "");
        int matrixSize = keyMatrix.length; // Get the size of the key matrix
        validateDeterminant(keyMatrix, matrixSize); // Validate the key matrix determinant
        StringBuilder cipherText = new StringBuilder(); // StringBuilder to build the encrypted message
        int[] messageVector = new int[matrixSize]; // Vector to hold message characters
        int[] cipherVector = new int[matrixSize]; // Vector to hold encrypted characters
        int index = 0; // Index to track the position in the message

        // Process the message in blocks of size equal to the matrix size
        while (index < message.length()) {
            // Fill the message vector with characters from the message
            for (int i = 0; i < matrixSize; i++) {
                if (index < message.length()) {
                    messageVector[i] = message.charAt(index++) - 'A'; // Convert char to int
                } else {
                    messageVector[i] = 'X' - 'A'; // Pad with 'X' if message is shorter than matrix size
                }
            }
            // Encrypt the message vector using the key matrix
            for (int i = 0; i < matrixSize; i++) {
                cipherVector[i] = 0; // Initialize cipher vector
                for (int j = 0; j < matrixSize; j++) {
                    cipherVector[i] += keyMatrix[i][j] * messageVector[j]; // Matrix multiplication
                }
                cipherVector[i] = cipherVector[i] % 26; // Modulo 26 to wrap around alphabet
                cipherText.append((char) (cipherVector[i] + 'A')); // Convert back to char and append to cipher text
            }
        }
        return cipherText.toString(); // Return the final encrypted message
    }

    // Method to validate the determinant of the key matrix
    private void validateDeterminant(int[][] keyMatrix, int n) {
        int det = determinant(keyMatrix, n) % 26; // Calculate determinant modulo 26
        // Check if determinant is zero or not coprime to 26
        if (det == 0 || gcd(det, 26) != 1) {
            throw new IllegalArgumentException("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.");
        }
    }

    // Method to calculate the determinant of a matrix
    private int determinant(int[][] matrix, int n) {
        int det = 0; // Initialize determinant
        if (n == 1) {
            return matrix[0][0]; // Base case for 1x1 matrix
        }
        int sign = 1; // Variable to alternate signs for cofactor expansion
        int[][] subMatrix = new int[n - 1][n - 1]; // Submatrix for determinant calculation

        // Calculate determinant using cofactor expansion
        for (int x = 0; x < n; x++) {
            int subI = 0; // Row index for submatrix
            for (int i = 1; i < n; i++) {
                int subJ = 0; // Column index for submatrix
                for (int j = 0; j < n; j++) {
                    if (j != x) {
                        subMatrix[subI][subJ++] = matrix[i][j]; // Fill submatrix
                    }
                }
                subI++;
            }
            det += sign * matrix[0][x] * determinant(subMatrix, n - 1); // Recursive determinant calculation
            sign = -sign; // Alternate sign
        }
        return det; // Return the calculated determinant
    }

    // Method to calculate the greatest common divisor (GCD) of two numbers
    private int gcd(int a, int b) {
        if (b == 0) {
            return a; // Base case for GCD
        }
        return gcd(b, a % b); // Recursive GCD calculation
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Scanner for user input
        Main hillCipher = new Main(); // Create an instance of the Main class
        String operation = scanner.nextLine().toLowerCase(); // Read the operation (encrypt/decrypt)
        int matrixSize = scanner.nextInt(); // Read the size of the key matrix
        int[][] keyMatrix = new int[matrixSize][matrixSize]; // Initialize the key matrix
        boolean validMatrix = false; // Flag to check if the matrix is valid

        // Loop to read the key matrix and validate it
        while (!validMatrix) {
            try {
                // Read the key matrix values from user input
                for (int i = 0; i < matrixSize; i++) {
                    for (int j = 0; j < matrixSize; j++) {
                        keyMatrix[i][j] = scanner.nextInt();
                    }
                }
                hillCipher.validateDeterminant(keyMatrix, matrixSize); // Validate the key matrix
                validMatrix = true; // Set flag to true if validation is successful
            } catch (IllegalArgumentException e) {
                // Handle invalid matrix input
                System.out.println(e.getMessage());
                System.out.println("Please enter a valid matrix.");
            }
        }

        // Check if the operation is encryption
        if ("encrypt".equals(operation)) {
            scanner.nextLine(); // Consume the newline character
            String message = scanner.nextLine(); // Read the message to encrypt
            String encryptedMessage = hillCipher.encrypt(message, keyMatrix); // Encrypt the message
            System.out.println("Encrypted Message: " + encryptedMessage); // Output the encrypted message
        } else {
            System.out.println("Decryption functionality not implemented in this example."); // Placeholder for decryption
        }
        scanner.close(); // Close the scanner
    }
}
