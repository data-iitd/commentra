
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;
import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.KeyGenerator;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.crypto.spec.GCMParameterSpec;

public final class Main {
    private Main() {
    }

    // Declare a character array for Hex conversion
    private static final char[] HEX_ARRAY = "0123456789ABCDEF".toCharArray();

    // Initialize the AES cipher for encryption and decryption
    private static Cipher aesCipher;

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in); // Create a new Scanner object to read user input

        String plainText = scanner.nextLine(); // Read a line of plain text input from the user

        // Generate a new AES secret key
        SecretKey secKey = getSecretEncryptionKey();

        System.out.println("Generated AES Key (Hex Form): " + bytesToHex(secKey.getEncoded())); // Print the generated key in hexadecimal format

        // Encrypt the plain text using the generated secret key
        byte[] cipherText = encryptText(plainText, secKey);

        System.out.println("Encrypted Text (Hex Form): " + bytesToHex(cipherText)); // Print the encrypted text in hexadecimal format

        // Decrypt the encrypted text using the generated secret key
        String decryptedText = decryptText(cipherText, secKey);

        System.out.println("Decrypted Text: " + decryptedText); // Print the decrypted text

        scanner.close(); // Close the Scanner object to free system resources
    }

    // Generate a new AES secret key using the KeyGenerator
    public static SecretKey getSecretEncryptionKey() throws NoSuchAlgorithmException {
        KeyGenerator aesKeyGenerator = KeyGenerator.getInstance("AES"); // Initialize the AES key generator
        aesKeyGenerator.init(128); // Initialize the key generator with a 128-bit key size
        return aesKeyGenerator.generateKey(); // Generate a new secret key
    }

    // Encrypt the plain text using the AES cipher in GCM mode
    public static byte[] encryptText(String plainText, SecretKey secKey)
            throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException,
            IllegalBlockSizeException, BadPaddingException {
        aesCipher = Cipher.getInstance("AES/GCM/NoPadding"); // Initialize the AES cipher for encryption
        aesCipher.init(Cipher.ENCRYPT_MODE, secKey); // Initialize the cipher with the secret key
        return aesCipher.doFinal(plainText.getBytes()); // Encrypt the plain text and return the ciphertext
    }

    // Decrypt the ciphertext using the AES cipher in GCM mode
    public static String decryptText(byte[] byteCipherText, SecretKey secKey)
            throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException,
            IllegalBlockSizeException, BadPaddingException, InvalidAlgorithmParameterException {
        Cipher decryptionCipher = Cipher.getInstance("AES/GCM/NoPadding"); // Initialize the AES cipher for decryption
        GCMParameterSpec gcmParameterSpec = new GCMParameterSpec(128, aesCipher.getIV()); // Initialize the GCM parameter spec with the IV
        decryptionCipher.init(Cipher.DECRYPT_MODE, secKey, gcmParameterSpec); // Initialize the cipher with the secret key and GCM parameter spec
        byte[] bytePlainText = decryptionCipher.doFinal(byteCipherText); // Decrypt the ciphertext and return the plaintext
        return new String(bytePlainText); // Convert the decrypted byte array to a String and return it
    }

    // Convert a byte array to a hexadecimal string
    public static String bytesToHex(byte[] bytes) {
        char[] hexChars = new char[bytes.length * 2];
        for (int j = 0; j < bytes.length; j++) {
            int v = bytes[j] & 0xFF; // Get the byte value as an unsigned 8-bit integer
            hexChars[j * 2] = HEX_ARRAY[v >>> 4]; // Get the first hex digit based on the high 4 bits
            hexChars[j * 2 + 1] = HEX_ARRAY[v & 0x0F]; // Get the second hex digit based on the low 4 bits
        }
        return new String(hexChars); // Convert the hex character array to a String and return it
    }
}