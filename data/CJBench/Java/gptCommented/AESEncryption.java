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
    // Private constructor to prevent instantiation of the utility class
    private Main() {
    }

    // Hexadecimal character array for converting byte arrays to hex strings
    private static final char[] HEX_ARRAY = "0123456789ABCDEF".toCharArray();
    
    // Cipher instance for AES encryption
    private static Cipher aesCipher;

    public static void main(String[] args) throws Exception {
        // Create a scanner to read user input
        Scanner scanner = new Scanner(System.in);
        
        // Read plaintext input from the user
        String plainText = scanner.nextLine();
        
        // Generate a secret AES encryption key
        SecretKey secKey = getSecretEncryptionKey();
        
        // Display the generated AES key in hexadecimal format
        System.out.println("Generated AES Key (Hex Form): " + bytesToHex(secKey.getEncoded()));
        
        // Encrypt the plaintext using the generated secret key
        byte[] cipherText = encryptText(plainText, secKey);
        
        // Display the encrypted text in hexadecimal format
        System.out.println("Encrypted Text (Hex Form): " + bytesToHex(cipherText));
        
        // Decrypt the ciphertext back to plaintext
        String decryptedText = decryptText(cipherText, secKey);
        
        // Display the decrypted text
        System.out.println("Decrypted Text: " + decryptedText);
    }

    // Method to generate a secret AES encryption key
    public static SecretKey getSecretEncryptionKey() throws NoSuchAlgorithmException {
        // Create a KeyGenerator for AES
        KeyGenerator aesKeyGenerator = KeyGenerator.getInstance("AES");
        
        // Initialize the key generator with a key size of 128 bits
        aesKeyGenerator.init(128); 
        
        // Generate and return the secret key
        return aesKeyGenerator.generateKey();
    }

    // Method to encrypt plaintext using the provided secret key
    public static byte[] encryptText(String plainText, SecretKey secKey)
            throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException,
            IllegalBlockSizeException, BadPaddingException {
        // Initialize the AES cipher in encryption mode
        aesCipher = Cipher.getInstance("AES/GCM/NoPadding");
        aesCipher.init(Cipher.ENCRYPT_MODE, secKey);
        
        // Encrypt the plaintext and return the ciphertext
        return aesCipher.doFinal(plainText.getBytes());
    }

    // Method to decrypt ciphertext using the provided secret key
    public static String decryptText(byte[] byteCipherText, SecretKey secKey)
            throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException,
            IllegalBlockSizeException, BadPaddingException, InvalidAlgorithmParameterException {
        // Create a new cipher instance for decryption
        Cipher decryptionCipher = Cipher.getInstance("AES/GCM/NoPadding");
        
        // Create GCMParameterSpec using the IV from the encryption cipher
        GCMParameterSpec gcmParameterSpec = new GCMParameterSpec(128, aesCipher.getIV());
        
        // Initialize the decryption cipher with the secret key and GCM parameters
        decryptionCipher.init(Cipher.DECRYPT_MODE, secKey, gcmParameterSpec);
        
        // Decrypt the ciphertext and return the plaintext
        byte[] bytePlainText = decryptionCipher.doFinal(byteCipherText);
        return new String(bytePlainText);
    }

    // Method to convert a byte array to a hexadecimal string
    public static String bytesToHex(byte[] bytes) {
        // Create a character array to hold the hex representation
        char[] hexChars = new char[bytes.length * 2];
        
        // Convert each byte to its corresponding hex representation
        for (int j = 0; j < bytes.length; j++) {
            int v = bytes[j] & 0xFF;
            hexChars[j * 2] = HEX_ARRAY[v >>> 4];
            hexChars[j * 2 + 1] = HEX_ARRAY[v & 0x0F];
        }
        
        // Return the hex string
        return new String(hexChars);
    }
}
