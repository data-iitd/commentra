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

// The code imports necessary classes for security and input operations.
public final class Main {
    private Main() {
    }

    // Private constructor to prevent instantiation of the Main class.
    private static final char[] HEX_ARRAY = "0123456789ABCDEF".toCharArray();

    // Utility array to convert byte arrays to hexadecimal strings.
    private static Cipher aesCipher;

    // Cipher object for AES encryption/decryption is declared but not instantiated.
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        String plainText = scanner.nextLine();
        SecretKey secKey = getSecretEncryptionKey();
        System.out.println("Generated AES Key (Hex Form): " + bytesToHex(secKey.getEncoded()));
        byte[] cipherText = encryptText(plainText, secKey);
        System.out.println("Encrypted Text (Hex Form): " + bytesToHex(cipherText));
        String decryptedText = decryptText(cipherText, secKey);
        System.out.println("Decrypted Text: " + decryptedText);
    }

    // Generates a 128-bit AES key.
    public static SecretKey getSecretEncryptionKey() throws NoSuchAlgorithmException {
        KeyGenerator aesKeyGenerator = KeyGenerator.getInstance("AES");
        aesKeyGenerator.init(128); 
        return aesKeyGenerator.generateKey();
    }

    // Encrypts the input text using AES in GCM mode.
    public static byte[] encryptText(String plainText, SecretKey secKey)
            throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException,
            IllegalBlockSizeException, BadPaddingException {
        aesCipher = Cipher.getInstance("AES/GCM/NoPadding");
        aesCipher.init(Cipher.ENCRYPT_MODE, secKey);
        return aesCipher.doFinal(plainText.getBytes());
    }

    // Decrypts the cipher text using AES in GCM mode with the same parameters used during encryption.
    public static String decryptText(byte[] byteCipherText, SecretKey secKey)
            throws NoSuchAlgorithmException, NoSuchPaddingException, InvalidKeyException,
            IllegalBlockSizeException, BadPaddingException, InvalidAlgorithmParameterException {
        Cipher decryptionCipher = Cipher.getInstance("AES/GCM/NoPadding");
        GCMParameterSpec gcmParameterSpec = new GCMParameterSpec(128, aesCipher.getIV());
        decryptionCipher.init(Cipher.DECRYPT_MODE, secKey, gcmParameterSpec);
        byte[] bytePlainText = decryptionCipher.doFinal(byteCipherText);
        return new String(bytePlainText);
    }

    // Converts byte arrays to hexadecimal strings.
    public static String bytesToHex(byte[] bytes) {
        char[] hexChars = new char[bytes.length * 2];
        for (int j = 0; j < bytes.length; j++) {
            int v = bytes[j] & 0xFF;
            hexChars[j * 2] = HEX_ARRAY[v >>> 4];
            hexChars[j * 2 + 1] = HEX_ARRAY[v & 0x0F];
        }
        return new String(hexChars);
    }
}
