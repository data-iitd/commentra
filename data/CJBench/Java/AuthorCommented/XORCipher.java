
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

/**
 * A simple implementation of the XOR cipher that allows both encryption and decryption
 * using a given key. This cipher works by applying the XOR bitwise operation between
 * the bytes of the input text and the corresponding bytes of the key (repeating the key
 * if necessary).
 *
 * Usage:
 * - Encryption: Converts plaintext into a hexadecimal-encoded ciphertext.
 * - Decryption: Converts the hexadecimal ciphertext back into plaintext.
 *
 * Characteristics:
 * - Symmetric: The same key is used for both encryption and decryption.
 * - Simple but vulnerable: XOR encryption is insecure for real-world cryptography,
 *   especially when the same key is reused.
 *
 * Example:
 * Plaintext: "Hello!"
 * Key: "key"
 * Encrypted: "27090c03120b"
 * Decrypted: "Hello!"
 *
 * Reference: <a href="https://en.wikipedia.org/wiki/XOR_cipher">XOR Cipher - Wikipedia</a>
 *
 * @author <a href="https://github.com/lcsjunior">lcsjunior</a>
 */
public final class XORCipher {

    private static final Charset CS_DEFAULT = StandardCharsets.UTF_8;

    private XORCipher() {
    }

    // Converts a byte array to a hexadecimal string
    private static String bytesToHex(byte[] bytes) {
        StringBuilder hexString = new StringBuilder();
        for (byte b : bytes) {
            String hex = Integer.toHexString(b & 0xFF);
            if (hex.length() == 1) {
                hexString.append('0');
            }
            hexString.append(hex);
        }
        return hexString.toString();
    }

    // Converts a hexadecimal string to a byte array
    private static byte[] hexToBytes(String hex) {
        int len = hex.length();
        byte[] data = new byte[len / 2];
        for (int i = 0; i < len; i += 2) {
            data[i / 2] = (byte) ((Character.digit(hex.charAt(i), 16) << 4)
                                + Character.digit(hex.charAt(i + 1), 16));
        }
        return data;
    }

    /**
     * Applies the XOR operation between the input bytes and the key bytes.
     * If the key is shorter than the input, it wraps around (cyclically).
     *
     * @param inputBytes The input byte array (plaintext or ciphertext).
     * @param keyBytes The key byte array used for XOR operation.
     * @return A new byte array containing the XOR result.
     */
    public static byte[] xor(final byte[] inputBytes, final byte[] keyBytes) {
        byte[] outputBytes = new byte[inputBytes.length];
        for (int i = 0; i < inputBytes.length; ++i) {
            outputBytes[i] = (byte) (inputBytes[i] ^ keyBytes[i % keyBytes.length]);
        }
        return outputBytes;
    }

     /**
     * Encrypts the given plaintext using the XOR cipher with the specified key.
     * The result is a hexadecimal-encoded string representing the ciphertext.
     *
     * @param plainText The input plaintext to encrypt.
     * @param key The encryption key.
     * @throws IllegalArgumentException if the key is empty.
     * @return A hexadecimal string representing the encrypted text.
     */
    public static String encrypt(final String plainText, final String key) {
        if (key.isEmpty()) {
            throw new IllegalArgumentException("Key must not be empty");
        }

        byte[] plainTextBytes = plainText.getBytes(CS_DEFAULT);
        byte[] keyBytes = key.getBytes(CS_DEFAULT);
        byte[] xorResult = xor(plainTextBytes, keyBytes);
        return bytesToHex(xorResult);
    }

    /**
     * Decrypts the given ciphertext (in hexadecimal format) using the XOR cipher
     * with the specified key. The result is the original plaintext.
     *
     * @param cipherText The hexadecimal string representing the encrypted text.
     * @param key The decryption key (must be the same as the encryption key).
     * @throws IllegalArgumentException if the key is empty.
     * @return The decrypted plaintext.
     */
    public static String decrypt(final String cipherText, final String key) {
        if (key.isEmpty()) {
            throw new IllegalArgumentException("Key must not be empty");
        }

        byte[] cipherBytes = hexToBytes(cipherText);
        byte[] keyBytes = key.getBytes(CS_DEFAULT);
        byte[] xorResult = xor(cipherBytes, keyBytes);
        return new String(xorResult, CS_DEFAULT);
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        String operation = scanner.nextLine().toLowerCase();

        String key = scanner.nextLine();

        if (operation.equals("encrypt")) {
            String plainText = scanner.nextLine();
            try {
                String cipherText = encrypt(plainText, key);
                System.out.println("Encrypted Message: " + cipherText);
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        } else if (operation.equals("decrypt")) {
            String cipherText = scanner.nextLine();
            try {
                String plainText = decrypt(cipherText, key);
                System.out.println("Decrypted Message: " + plainText);
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        } else {
            System.out.println("Invalid operation. Please choose 'encrypt' or 'decrypt'.");
        }

        scanner.close();
    }
}
