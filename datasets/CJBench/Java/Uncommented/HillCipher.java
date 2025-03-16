
import java.util.Scanner;
public class HillCipher {
    public String encrypt(String message, int[][] keyMatrix) {
        message = message.toUpperCase().replaceAll("[^A-Z]", "");
        int matrixSize = keyMatrix.length;
        validateDeterminant(keyMatrix, matrixSize);
        StringBuilder cipherText = new StringBuilder();
        int[] messageVector = new int[matrixSize];
        int[] cipherVector = new int[matrixSize];
        int index = 0;
        while (index < message.length()) {
            for (int i = 0; i < matrixSize; i++) {
                if (index < message.length()) {
                    messageVector[i] = message.charAt(index++) - 'A';
                } else {
                    messageVector[i] = 'X' - 'A'; 
                }
            }
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
    private void validateDeterminant(int[][] keyMatrix, int n) {
        int det = determinant(keyMatrix, n) % 26;
        if (det == 0 || gcd(det, 26) != 1) {
            throw new IllegalArgumentException("Invalid key matrix. Determinant is zero modulo 26 or not coprime to 26.");
        }
    }
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
            scanner.nextLine(); 
            String message = scanner.nextLine();
            String encryptedMessage = hillCipher.encrypt(message, keyMatrix);
            System.out.println("Encrypted Message: " + encryptedMessage);
        } else {
            System.out.println("Decryption functionality not implemented in this example.");
        }
        scanner.close();
    }
}
