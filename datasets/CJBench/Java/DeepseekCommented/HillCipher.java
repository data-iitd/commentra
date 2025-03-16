import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Defining the Main class

    // Encrypt method to encrypt the message using Hill cipher algorithm
    public String encrypt(String message, int[][] keyMatrix) {
        message = message.toUpperCase().replaceAll("[^A-Z]", ""); // Convert message to uppercase and remove non-alphabetic characters
        int matrixSize = keyMatrix.length; // Get the size of the key matrix
        validateDeterminant(keyMatrix, matrixSize); // Validate the key matrix determinant
        StringBuilder cipherText = new StringBuilder(); // Initialize a StringBuilder to build the cipher text
        int[] messageVector = new int[matrixSize]; // Initialize an array to hold the message vector
        int[] cipherVector = new int[matrixSize]; // Initialize an array to hold the cipher vector
        int index = 0; // Initialize the index to traverse the message
        while (index < message.length()) { // Loop through the message
            for (int i = 0; i < matrixSize; i++) { // Populate the message vector
                if (index < message.length()) {
                    messageVector[i] = message.charAt(index++) - 'A'; // Convert character to number and add to message vector
                } else {
                    messageVector[i] = 'X' - 'A'; // If message ends, use 'X' as padding
                }
            }
            for (int i = 0; i < matrixSize; i++) { // Calculate the cipher vector
                cipherVector[i] = 0;
                for (int j = 0; j < matrixSize; j++) {
                    cipherVector[i] += keyMatrix[i][j] * messageVector[j]; // Multiply key matrix row by message vector and add to cipher vector
                }
                cipherVector[i] = cipherVector[i] % 26; // Modulo 26 to keep within the alphabet range
                cipherText.append((char) (cipherVector[i] + 'A')); // Convert number back to character and append to cipher text
            }
        }
        return cipherText.toString(); // Return the encrypted message
    }

    // Validate determinant method to check if the key matrix is valid
    private void validateDeterminant(int[][] keyMatrix, int n) {
        int det = determinant(keyMatrix, n) % 26; // Calculate determinant modulo 26
        if (det == 0 || gcd(det, 26) != 1) { // Check if determinant is zero or not coprime to 26
            throw new IllegalArgumentException("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26."); // Throw exception if invalid
        }
    }

    // Recursive method to calculate the determinant of the key matrix
    private int determinant(int[][] matrix, int n) {
        int det = 0;
        if (n == 1) {
            return matrix[0][0]; // Base case for 1x1 matrix
        }
        int sign = 1;
        int[][] subMatrix = new int[n - 1][n - 1]; // Initialize submatrix for recursion
        for (int x = 0; x < n; x++) { // Loop through each element in the first row
            int subI = 0;
            for (int i = 1; i < n; i++) { // Populate submatrix excluding the current row and column
                int subJ = 0;
                for (int j = 0; j < n; j++) {
                    if (j != x) {
                        subMatrix[subI][subJ++] = matrix[i][j];
                    }
                }
                subI++;
            }
            det += sign * matrix[0][x] * determinant(subMatrix, n - 1); // Recursive call and add to determinant
            sign = -sign; // Alternate the sign
        }
        return det; // Return the determinant
    }

    // Method to calculate the greatest common divisor
    private int gcd(int a, int b) {
        if (b == 0) {
            return a; // Base case for gcd
        }
        return gcd(b, a % b); // Recursive call
    }

    // Main method to handle user input and call the encrypt method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize scanner for user input
        Main hillCipher = new Main(); // Create an instance of the Main class
        String operation = scanner.nextLine().toLowerCase(); // Read the operation (encrypt or decrypt)
        int matrixSize = scanner.nextInt(); // Read the size of the key matrix
        int[][] keyMatrix = new int[matrixSize][matrixSize]; // Initialize the key matrix
        boolean validMatrix = false; // Flag to check if the matrix is valid
        while (!validMatrix) { // Loop until a valid matrix is entered
            try {
                for (int i = 0; i < matrixSize; i++) { // Read the key matrix elements
                    for (int j = 0; j < matrixSize; j++) {
                        keyMatrix[i][j] = scanner.nextInt();
                    }
                }
                hillCipher.validateDeterminant(keyMatrix, matrixSize); // Validate the key matrix
                validMatrix = true; // Set flag to true if valid
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage()); // Print error message if invalid
                System.out.println("Please enter a valid matrix."); // Prompt user to enter a valid matrix
            }
        }
        if ("encrypt".equals(operation)) { // Check if the operation is encrypt
            scanner.nextLine(); // Consume the newline character
            String message = scanner.nextLine(); // Read the message to encrypt
            String encryptedMessage = hillCipher.encrypt(message, keyMatrix); // Encrypt the message
            System.out.println("Encrypted Message: " + encryptedMessage); // Print the encrypted message
        } else {
            System.out.println("Decryption functionality not implemented in this example."); // Print message if decryption is not implemented
        }
        scanner.close(); // Close the scanner
    }
}
