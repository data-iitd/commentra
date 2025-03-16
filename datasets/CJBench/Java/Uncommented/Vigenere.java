
import java.util.Scanner;
public class Vigenere {
    public String encrypt(final String message, final String key) {
        if (key.isEmpty()) {
            throw new IllegalArgumentException("Key cannot be empty.");
        }
        StringBuilder result = new StringBuilder();
        int j = 0;
        for (int i = 0; i < message.length(); i++) {
            char c = message.charAt(i);
            if (Character.isLetter(c)) {
                if (Character.isUpperCase(c)) {
                    result.append((char) ((c + key.toUpperCase().charAt(j) - 2 * 'A') % 26 + 'A'));
                } else {
                    result.append((char) ((c + key.toLowerCase().charAt(j) - 2 * 'a') % 26 + 'a'));
                }
                j = ++j % key.length();
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }
    public String decrypt(final String message, final String key) {
        if (key.isEmpty()) {
            throw new IllegalArgumentException("Key cannot be empty.");
        }
        StringBuilder result = new StringBuilder();
        int j = 0;
        for (int i = 0; i < message.length(); i++) {
            char c = message.charAt(i);
            if (Character.isLetter(c)) {
                if (Character.isUpperCase(c)) {
                    result.append((char) ('Z' - (25 - (c - key.toUpperCase().charAt(j))) % 26));
                } else {
                    result.append((char) ('z' - (25 - (c - key.toLowerCase().charAt(j))) % 26));
                }
                j = ++j % key.length();
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String operation = scanner.nextLine().toLowerCase();
        String key = scanner.nextLine();
        if (operation.equals("encrypt")) {
            String plaintext = scanner.nextLine();
            Vigenere cipher = new Vigenere();
            String encrypted = cipher.encrypt(plaintext, key);
            System.out.println("Encrypted Message: " + encrypted);
        } else if (operation.equals("decrypt")) {
            String ciphertext = scanner.nextLine();
            Vigenere cipher = new Vigenere();
            String decrypted = cipher.decrypt(ciphertext, key);
            System.out.println("Decrypted Message: " + decrypted);
        } else {
            System.out.println("Invalid operation. Please choose 'encrypt' or 'decrypt'.");
        }
        scanner.close();
    }
}
