
import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Scanner;

public class Main {
    // Instance variables
    private BigInteger modulus;
    private BigInteger privateKey;
    private BigInteger publicKey;

    // Constructor
    public Main(int bits) {
        generateKeys(bits);
    }

    // Encryption method
    public synchronized String encrypt(String message) {
        if (message.isEmpty()) { // Check if message is empty
            throw new IllegalArgumentException("Message is empty");
        }
        return (new BigInteger(message.getBytes())).modPow(publicKey, modulus).toString(); // Encrypt the message using public key and modulus
    }

    // Decryption method
    public synchronized String decrypt(String encryptedMessage) {
        if (encryptedMessage.isEmpty()) { // Check if encrypted message is empty
            throw new IllegalArgumentException("Message is empty");
        }
        return new String((new BigInteger(encryptedMessage)).modPow(privateKey, modulus).toByteArray()); // Decrypt the message using private key and modulus
    }

    // Generate keys method
    public final synchronized void generateKeys(int bits) {
        SecureRandom random = new SecureRandom(); // Initialize SecureRandom object
        BigInteger p = new BigInteger(bits / 2, 100, random); // Generate prime number p with given number of bits
        BigInteger q = new BigInteger(bits / 2, 100, random); // Generate prime number q with given number of bits
        modulus = p.multiply(q); // Multiply p and q to get modulus
        BigInteger phi = (p.subtract(BigInteger.ONE)).multiply(q.subtract(BigInteger.ONE)); // Calculate phi(n) = (p-1)*(q-1)
        publicKey = BigInteger.valueOf(3L); // Initialize public key as 3

        // Find a public key such that gcd(phi, publicKey) = 1
        while (phi.gcd(publicKey).intValue() > 1) {
            publicKey = publicKey.add(BigInteger.TWO); // Increment public key by 2 until gcd(phi, publicKey) = 1
        }

        privateKey = publicKey.modInverse(phi); // Calculate private key as the modular inverse of public key modulo phi
    }

    // Main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize Scanner object
        int bits = scanner.nextInt(); // Read the number of bits from the user
        Main rsa = new Main(bits); // Create an instance of Main class with the given number of bits
        System.out.println("Public Key: " + rsa.publicKey); // Print the public key
        System.out.println("Modulus: " + rsa.modulus); // Print the modulus
        String operation = scanner.next(); // Read the operation from the user
        scanner.nextLine(); // Consume the newline character

        if (operation.equalsIgnoreCase("encrypt")) { // If the operation is 'encrypt'
            String message = scanner.nextLine(); // Read the message from the user
            String encryptedMessage = rsa.encrypt(message); // Encrypt the message using the instance's encrypt method
            System.out.println("Encrypted Message: " + encryptedMessage); // Print the encrypted message
        } else if (operation.equalsIgnoreCase("decrypt")) { // If the operation is 'decrypt'
            String encryptedMessage = scanner.nextLine(); // Read the encrypted message from the user
            String decryptedMessage = rsa.decrypt(encryptedMessage); // Decrypt the message using the instance's decrypt method
            System.out.println("Decrypted Message: " + decryptedMessage); // Print the decrypted message
        } else { // If the operation is not 'encrypt' or 'decrypt'
            System.out.println("Invalid operation"); // Print an error message
        }
        scanner.close(); // Close the Scanner object
    }
}