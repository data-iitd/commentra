
import java.util.Scanner;
final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class from outside
    }
    static int a = 17;
    static int b = 20;

    // Method to encrypt a message using the given Caesar cipher algorithm
    static String encryptMessage(char[] msg) {
        StringBuilder cipher = new StringBuilder(); // Initialize an empty StringBuilder to store the encrypted message
        for (int i = 0; i < msg.length; i++) {
            if (msg[i] != ' ') { // If the current character is not a space
                cipher.append((char) ((((a * (msg[i] - 'A')) + b) % 26) + 'A')); // Encrypt the character using the Caesar cipher algorithm and append it to the StringBuilder
            } else {
                cipher.append(msg[i]); // If the current character is a space, just append it to the StringBuilder as it is
            }
        }
        return cipher.toString(); // Return the encrypted message as a String
    }

    // Method to decrypt a message encrypted using the given Caesar cipher algorithm
    static String decryptCipher(String cipher) {
        StringBuilder msg = new StringBuilder(); // Initialize an empty StringBuilder to store the decrypted message
        int aInv = 0;
        int flag;

        // Find the multiplicative inverse of 'a' modulo 26 to decrypt the message
        for (int i = 0; i < 26; i++) {
            flag = (a * i) % 26;
            if (flag == 1) {
                aInv = i;
                break;
            }
        }

        for (int i = 0; i < cipher.length(); i++) {
            if (cipher.charAt(i) != ' ') { // If the current character is not a space
                msg.append((char) (((aInv * ((cipher.charAt(i) - 'A') - b + 26)) % 26) + 'A')); // Decrypt the character using the inverse of 'a' and append it to the StringBuilder
            } else {
                msg.append(cipher.charAt(i)); // If the current character is a space, just append it to the StringBuilder as it is
            }
        }
        return msg.toString(); // Return the decrypted message as a String
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read input from the user
        String msg = scanner.nextLine().toUpperCase(); // Read a line of input from the user and convert it to uppercase
        char[] msgChars = msg.toCharArray(); // Convert the input String to a char array for processing
        String cipherText = encryptMessage(msgChars); // Encrypt the message using the encryptMessage() method and store the result in a String variable
        System.out.println("Encrypted Message: " + cipherText); // Print the encrypted message to the console
        String decryptedText = decryptCipher(cipherText); // Decrypt the encrypted message using the decryptCipher() method and store the result in a String variable
        System.out.println("Decrypted Message: " + decryptedText); // Print the decrypted message to the console
        scanner.close(); // Close the Scanner object to free up system resources
    }
}

