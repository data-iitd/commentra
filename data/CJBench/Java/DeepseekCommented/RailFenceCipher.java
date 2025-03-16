import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Encrypts the input string using the rail fence cipher technique
    public String encrypt(String str, int rails) {
        // If rails is 1 or greater than the length of the string, return the string as is
        if (rails == 1 || rails >= str.length()) {
            return str;
        }
        
        // Initialize direction and the 2D character array
        boolean down = true;
        char[][] strRail = new char[rails][str.length()];
        
        // Fill the array with newline characters
        for (int i = 0; i < rails; i++) {
            Arrays.fill(strRail[i], '\n');
        }
        
        // Initialize row, column, and index variables
        int row = 0, col = 0, i = 0;
        
        // Traverse the string and fill the array
        while (col < str.length()) {
            if (row == 0) {
                down = true;
            } else if (row == rails - 1) {
                down = false;
            }
            strRail[row][col] = str.charAt(i++);
            col++;
            if (down) {
                row++;
            } else {
                row--;
            }
        }
        
        // Construct the encrypted string from the filled array
        StringBuilder encryptedString = new StringBuilder();
        for (char[] chRow : strRail) {
            for (char ch : chRow) {
                if (ch != '\n') {
                    encryptedString.append(ch);
                }
            }
        }
        return encryptedString.toString();
    }
    
    // Decrypts the input string encrypted with the rail fence cipher technique
    public String decrypt(String str, int rails) {
        if (rails == 1 || rails >= str.length()) {
            return str;
        }
        
        // Initialize direction and the 2D character array
        boolean down = true;
        char[][] strRail = new char[rails][str.length()];
        
        // Mark the positions with asterisks
        int row = 0, col = 0;
        while (col < str.length()) {
            if (row == 0) {
                down = true;
            } else if (row == rails - 1) {
                down = false;
            }
            strRail[row][col] = '*';
            col++;
            if (down) {
                row++;
            } else {
                row--;
            }
        }
        
        // Fill the array with the characters from the encrypted string
        int index = 0;
        for (int i = 0; i < rails; i++) {
            for (int j = 0; j < str.length(); j++) {
                if (strRail[i][j] == '*') {
                    strRail[i][j] = str.charAt(index++);
                }
            }
        }
        
        // Construct the decrypted string by traversing the array
        StringBuilder decryptedString = new StringBuilder();
        row = 0;
        col = 0;
        while (col < str.length()) {
            if (row == 0) {
                down = true;
            } else if (row == rails - 1) {
                down = false;
            }
            decryptedString.append(strRail[row][col]);
            col++;
            if (down) {
                row++;
            } else {
                row--;
            }
        }
        return decryptedString.toString();
    }
    
    // Main method to handle user input and provide output
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String operation = scanner.next();
        int rails = scanner.nextInt();
        scanner.nextLine(); 
        
        if (operation.equalsIgnoreCase("encrypt")) {
            String plaintext = scanner.nextLine();
            Main cipher = new Main();
            String encrypted = cipher.encrypt(plaintext, rails);
            System.out.println("Encrypted Message: " + encrypted);
        } else if (operation.equalsIgnoreCase("decrypt")) {
            String ciphertext = scanner.nextLine();
            Main cipher = new Main();
            String decrypted = cipher.decrypt(ciphertext, rails);
            System.out.println("Decrypted Message: " + decrypted);
        } else {
            System.out.println("Invalid operation. Please choose 'encrypt' or 'decrypt'.");
        }
        scanner.close();
    }
}
