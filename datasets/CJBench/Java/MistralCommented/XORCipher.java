
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

public final class Main {
    // Declare the default character set for UTF-8 encoding
    private static final Charset CS_DEFAULT = StandardCharsets.UTF_8;

    private Main() {
    }

    // Converts a byte array to a hexadecimal string
    private static String bytesToHex(byte[] bytes) {
        StringBuilder hexString = new StringBuilder();
        for (byte b : bytes) {
            // Convert a single byte to hexadecimal string
            String hex = Integer.toHexString(b & 0xFF);
            // Add a leading zero if the hexadecimal string has only one character
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
            // Extract two hexadecimal digits and convert them to a byte
            data[i / 2] = (byte) ((Character.digit(hex.charAt(i), 16) << 4)
                                + Character.digit(hex.charAt(i + 1), 16));
        }
        return data;
    }

    // XOR operation between two byte arrays
    public static byte[] xor(final byte[] inputBytes, final byte[] keyBytes) {
        byte[] outputBytes = new byte[inputBytes.length];
        for (int i = 0; i < inputBytes.length; ++i) {
            // Perform XOR operation between each byte of inputBytes and keyBytes
            outputBytes[i] = (byte) (inputBytes[i] ^ keyBytes[i % keyBytes.length]);
        }
        return outputBytes;
    }

    // Encrypts a plain text using the provided key
    public static String encrypt(final String plainText, final String key) {
        if (key.isEmpty()) {
            throw new IllegalArgumentException("Key must not be empty");
        }
        // Convert plain text to byte array
        byte[] plainTextBytes = plainText.getBytes(CS_DEFAULT);
        // Convert key to byte array
        byte[] keyBytes = key.getBytes(CS_DEFAULT);
        // Perform XOR operation between plainTextBytes and keyBytes
        byte[] xorResult = xor(plainTextBytes, keyBytes);
        // Convert the XOR result to hexadecimal string
        return bytesToHex(xorResult);
    }

    // Decrypts a cipher text using the provided key
    public static String decrypt(final String cipherText, final String key) {
        if (key.isEmpty()) {
            throw new IllegalArgumentException("Key must not be empty");
        }
        // Convert cipher text to byte array
        byte[] cipherBytes = hexToBytes(cipherText);
        // Convert key to byte array
        byte[] keyBytes = key.getBytes(CS_DEFAULT);
        // Perform XOR operation between cipherBytes and keyBytes
        byte[] xorResult = xor(cipherBytes, keyBytes);
        // Convert the XOR result to a string using the default character set
        return new String(xorResult, CS_DEFAULT);
    }

    // Main method to read user input and perform encryption or decryption
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String operation = scanner.nextLine().toLowerCase(); // Read the operation ('encrypt' or 'decrypt')
        System.out.print("Enter the key: "); // Request the user to enter the key
        String key = scanner.nextLine(); // Read the key from the user

        if (operation.equals("encrypt")) { // If the operation is 'encrypt'
            String plainText = scanner.nextLine(); // Read the plain text from the user
            try {
                String cipherText = encrypt(plainText, key); // Encrypt the plain text using the key
                System.out.println("Encrypted Message: " + cipherText); // Print the encrypted message
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage()); // Print an error message if the key is empty
            }
        } else if (operation.equals("decrypt")) { // If the operation is 'decrypt'
            String cipherText = scanner.nextLine(); // Read the cipher text from the user
            try {
                String plainText = decrypt(cipherText, key); // Decrypt the cipher text using the key
                System.out.println("Decrypted Message: " + plainText); // Print the decrypted message
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage()); // Print an error message if the key is empty
            }
        } else {
            System.out.println("Invalid operation. Please choose 'encrypt' or 'decrypt'."); // Print an error message for invalid operation
        }

        scanner.close(); // Close the scanner
    }
}