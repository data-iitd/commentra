import java.util.Scanner;

final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Static variables for encryption parameters
    static int a = 17; // Multiplier for encryption
    static int b = 20; // Increment for encryption

    // Method to encrypt a message using a simple affine cipher
    static String encryptMessage(char[] msg) {
        StringBuilder cipher = new StringBuilder(); // StringBuilder to hold the encrypted message
        // Iterate through each character in the message
        for (int i = 0; i < msg.length; i++) {
            // Check if the character is not a space
            if (msg[i] != ' ') {
                // Apply the affine transformation and append the encrypted character
                cipher.append((char) ((((a * (msg[i] - 'A')) + b) % 26) + 'A'));
            } else {
                // If it's a space, append it directly
                cipher.append(msg[i]);
            }
        }
        // Return the final encrypted message as a string
        return cipher.toString();
    }

    // Method to decrypt a cipher text back to the original message
    static String decryptCipher(String cipher) {
        StringBuilder msg = new StringBuilder(); // StringBuilder to hold the decrypted message
        int aInv = 0; // Variable to hold the modular inverse of 'a'
        int flag; // Variable to check the condition for finding aInv

        // Find the modular inverse of 'a' such that (a * aInv) % 26 == 1
        for (int i = 0; i < 26; i++) {
            flag = (a * i) % 26;
            if (flag == 1) {
                aInv = i; // Store the value of aInv
                break; // Exit the loop once found
            }
        }

        // Iterate through each character in the cipher text
        for (int i = 0; i < cipher.length(); i++) {
            // Check if the character is not a space
            if (cipher.charAt(i) != ' ') {
                // Apply the inverse affine transformation and append the decrypted character
                msg.append((char) (((aInv * ((cipher.charAt(i) - 'A') - b + 26)) % 26) + 'A'));
            } else {
                // If it's a space, append it directly
                msg.append(cipher.charAt(i));
            }
        }
        // Return the final decrypted message as a string
        return msg.toString();
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String msg = scanner.nextLine().toUpperCase(); // Read input message and convert to uppercase
        String cipherText = encryptMessage(msg.toCharArray()); // Encrypt the message
        System.out.println("Encrypted Message: " + cipherText); // Display the encrypted message
        String decryptedText = decryptCipher(cipherText); // Decrypt the cipher text
        System.out.println("Decrypted Message: " + decryptedText); // Display the decrypted message
        scanner.close(); // Close the scanner to free resources
    }
}
