
import java.util.Arrays;
import java.util.Scanner;
public class RailFenceCipher {
    public String encrypt(String str, int rails) {
        if (rails == 1 || rails >= str.length()) {
            return str;
        }
        boolean down = true;
        char[][] strRail = new char[rails][str.length()];
        for (int i = 0; i < rails; i++) {
            Arrays.fill(strRail[i], '\n');
        }
        int row = 0, col = 0, i = 0;
        while (col < str.length()) {
            if (row == 0) {
                down = true;
            } 
            else if (row == rails - 1) {
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
    public String decrypt(String str, int rails) {
        if (rails == 1 || rails >= str.length()) {
            return str;
        }
        boolean down = true;
        char[][] strRail = new char[rails][str.length()];
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
        int index = 0;
        for (int i = 0; i < rails; i++) {
            for (int j = 0; j < str.length(); j++) {
                if (strRail[i][j] == '*') {
                    strRail[i][j] = str.charAt(index++);
                }
            }
        }
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
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String operation = scanner.next();
        int rails = scanner.nextInt();
        scanner.nextLine(); 
        if (operation.equalsIgnoreCase("encrypt")) {
            String plaintext = scanner.nextLine();
            RailFenceCipher cipher = new RailFenceCipher();
            String encrypted = cipher.encrypt(plaintext, rails);
            System.out.println("Encrypted Message: " + encrypted);
        } else if (operation.equalsIgnoreCase("decrypt")) {
            String ciphertext = scanner.nextLine();
            RailFenceCipher cipher = new RailFenceCipher();
            String decrypted = cipher.decrypt(ciphertext, rails);
            System.out.println("Decrypted Message: " + decrypted);
        } else {
            System.out.println("Invalid operation. Please choose 'encrypt' or 'decrypt'.");
        }
        scanner.close();
    }
}
