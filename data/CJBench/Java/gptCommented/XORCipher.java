import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

public final class Main {
    // Default character set for encoding and decoding
    private static final Charset CS_DEFAULT = StandardCharsets.UTF_8;

    // Private constructor to prevent instantiation of the utility class
    private Main() {
    }

    // Converts an array of bytes to a hexadecimal string representation
    private static String bytesToHex(byte[] bytes) {
        StringBuilder hexString = new StringBuilder();
        // Iterate through each byte in the array
        for (byte b : bytes) {
            // Convert byte to hex string and ensure two characters
            String hex = Integer.toHexString(b & 0xFF);
            if (hex.length() == 1) {
                hexString.append('0'); // Append leading zero for single hex digits
            }
            hexString.append(hex); // Append the hex value to the string
        }
        return hexString.toString(); // Return the complete hex string
    }

    // Converts a hexadecimal string representation back to an array of bytes
    private static byte[] hexToBytes(String hex) {
        int len = hex.length();
        byte[] data = new byte[len / 2]; // Create byte array of half the hex string length
        // Iterate through the hex string two characters at a time
        for (int i = 0; i < len; i += 2) {
            // Convert each pair of hex characters to a byte
            data[i / 2] = (byte) ((Character.digit(hex.charAt(i), 16) << 4)
                                + Character.digit(hex.charAt(i + 1), 16));
        }
        return data; // Return the byte array
    }

    // Performs XOR operation between input bytes and key bytes
    public static byte[] xor(final byte[] inputBytes, final byte[] keyBytes) {
        byte[] outputBytes = new byte[inputBytes.length]; // Create output byte array
        // Iterate through each byte in the input
        for (int i = 0; i < inputBytes.length; ++i) {
            // XOR the input byte with the corresponding key byte (cyclically)
            outputBytes[i] = (byte) (inputBytes[i] ^ keyBytes[i % keyBytes.length]);
        }
        return outputBytes; // Return the result of the XOR operation
    }

    // Encrypts the given plaintext using the specified key
    public static String encrypt(final String plainText, final String key) {
        // Check if the key is empty and throw an exception if it is
        if (key.isEmpty()) {
            throw new IllegalArgumentException("Key must not be empty");
        }
        // Convert plaintext and key to byte arrays
        byte[] plainTextBytes = plainText.getBytes(CS_DEFAULT);
        byte[] keyBytes = key.getBytes(CS_DEFAULT);
        // Perform XOR operation on plaintext and key
        byte[] xorResult = xor(plainTextBytes, keyBytes);
        // Convert the XOR result to a hex string and return it
        return bytesToHex(xorResult);
    }

    // Decrypts the given ciphertext using the specified key
    public static String decrypt(final String cipherText, final String key) {
        // Check if the key is empty and throw an exception if it is
        if (key.isEmpty()) {
            throw new IllegalArgumentException("Key must not be empty");
        }
        // Convert the ciphertext from hex string to byte array
        byte[] cipherBytes = hexToBytes(cipherText);
        byte[] keyBytes = key.getBytes(CS_DEFAULT);
        // Perform XOR operation on ciphertext and key
        byte[] xorResult = xor(cipherBytes, keyBytes);
        // Convert the result back to a string and return it
        return new String(xorResult, CS_DEFAULT);
    }

    // Main method to execute the program
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        // Read the operation type (encrypt or decrypt) from user input
        String operation = scanner.nextLine().toLowerCase();
        System.out.print("Enter the key: ");
        String key = scanner.nextLine();
        
        // Check if the operation is encryption
        if (operation.equals("encrypt")) {
            String plainText = scanner.nextLine(); // Read plaintext from user
            try {
                // Encrypt the plaintext and display the ciphertext
                String cipherText = encrypt(plainText, key);
                System.out.println("Encrypted Message: " + cipherText);
            } catch (IllegalArgumentException e) {
                // Handle empty key exception
                System.out.println(e.getMessage());
            }
        } 
        // Check if the operation is decryption
        else if (operation.equals("decrypt")) {
            String cipherText = scanner.nextLine(); // Read ciphertext from user
            try {
                // Decrypt the ciphertext and display the plaintext
                String plainText = decrypt(cipherText, key);
                System.out.println("Decrypted Message: " + plainText);
            } catch (IllegalArgumentException e) {
                // Handle empty key exception
                System.out.println(e.getMessage());
            }
        } 
        // Handle invalid operation input
        else {
            System.out.println("Invalid operation. Please choose 'encrypt' or 'decrypt'.");
        }
        scanner.close(); // Close the scanner resource
    }
}
