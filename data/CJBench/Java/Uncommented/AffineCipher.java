
import java.util.Scanner;
final class AffineCipher {
    private AffineCipher() {
    }
    static int a = 17;
    static int b = 20;
    static String encryptMessage(char[] msg) {
        StringBuilder cipher = new StringBuilder();
        for (int i = 0; i < msg.length; i++) {
            if (msg[i] != ' ') {
                cipher.append((char) ((((a * (msg[i] - 'A')) + b) % 26) + 'A'));
            } else {
                cipher.append(msg[i]);
            }
        }
        return cipher.toString();
    }
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
                msg.append((char) (((aInv * ((cipher.charAt(i) - 'A') - b + 26)) % 26) + 'A'));
            } else {
                msg.append(cipher.charAt(i));
            }
        }
        return msg.toString();
    }
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
