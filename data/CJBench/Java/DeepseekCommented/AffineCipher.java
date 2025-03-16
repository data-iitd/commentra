import java.util.Scanner;

final class Main {
    private Main() {
    }

    // Static variables for the affine cipher
    static int a = 17;
    static int b = 20;

    // Method to encrypt the message using the affine cipher
    static String encryptMessage(char[] msg) {
        StringBuilder cipher = new StringBuilder();
        for (int i = 0; i < msg.length; i++) {
            if (msg[i] != ' ') {
                // Applying the affine cipher encryption formula
                cipher.append((char) ((((a * (msg[i] - 'A')) + b) % 26) + 'A'));
            } else {
                cipher.append(msg[i]);
            }
        }
        return cipher.toString();
    }

    // Method to decrypt the cipher text using the affine cipher
    static String decryptCipher(String cipher) {
        StringBuilder msg = new StringBuilder();
        int aInv = 0;
        int flag;
        for (int i = 0; i < 26; i++) {
            flag = (a * i) % 26;
            if (flag == 1) {
                aInv = i;
                break;
            }
        }
        for (int i = 0; i < cipher.length(); i++) {
            if (cipher.charAt(i) != ' ') {
                // Applying the affine cipher decryption formula
                msg.append((char) (((aInv * ((cipher.charAt(i) - 'A') - b + 26)) % 26) + 'A'));
            } else {
                msg.append(cipher.charAt(i));
            }
        }
        return msg.toString();
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String msg = scanner.nextLine().toUpperCase();
        String cipherText = encryptMessage(msg.toCharArray());
        System.out.println("Encrypted Message: " + cipherText);
        String decryptedText = decryptCipher(cipherText);
        System.out.println("Decrypted Message: " + decryptedText);
        scanner.close();
    }
}
