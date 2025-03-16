
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
public final class XORCipher {
    private static final Charset CS_DEFAULT = StandardCharsets.UTF_8;
    private XORCipher() {
    }
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
    private static byte[] hexToBytes(String hex) {
        int len = hex.length();
        byte[] data = new byte[len / 2];
        for (int i = 0; i < len; i += 2) {
            data[i / 2] = (byte) ((Character.digit(hex.charAt(i), 16) << 4)
                                + Character.digit(hex.charAt(i + 1), 16));
        }
        return data;
    }
    public static byte[] xor(final byte[] inputBytes, final byte[] keyBytes) {
        byte[] outputBytes = new byte[inputBytes.length];
        for (int i = 0; i < inputBytes.length; ++i) {
            outputBytes[i] = (byte) (inputBytes[i] ^ keyBytes[i % keyBytes.length]);
        }
        return outputBytes;
    }
    public static String encrypt(final String plainText, final String key) {
        if (key.isEmpty()) {
            throw new IllegalArgumentException("Key must not be empty");
        }
        byte[] plainTextBytes = plainText.getBytes(CS_DEFAULT);
        byte[] keyBytes = key.getBytes(CS_DEFAULT);
        byte[] xorResult = xor(plainTextBytes, keyBytes);
        return bytesToHex(xorResult);
    }
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
        System.out.print("Enter the key: ");
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
