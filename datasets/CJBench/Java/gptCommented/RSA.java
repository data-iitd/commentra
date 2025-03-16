import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Scanner;

public class Main {
    // Variables to hold the modulus, private key, and public key
    private BigInteger modulus;
    private BigInteger privateKey;
    private BigInteger publicKey;

    // Constructor that initializes the RSA keys based on the specified bit length
    public Main(int bits) {
        generateKeys(bits);
    }

    // Method to encrypt a message using the public key
    public synchronized String encrypt(String message) {
        // Check if the message is empty and throw an exception if it is
        if (message.isEmpty()) {
            throw new IllegalArgumentException("Message is empty");
        }
        // Convert the message to a BigInteger, encrypt it, and return the encrypted string
        return (new BigInteger(message.getBytes())).modPow(publicKey, modulus).toString();
    }

    // Method to decrypt an encrypted message using the private key
    public synchronized String decrypt(String encryptedMessage) {
        // Check if the encrypted message is empty and throw an exception if it is
        if (encryptedMessage.isEmpty()) {
            throw new IllegalArgumentException("Message is empty");
        }
        // Convert the encrypted message to a BigInteger, decrypt it, and return the original message
        return new String((new BigInteger(encryptedMessage)).modPow(privateKey, modulus).toByteArray());
    }

    // Method to generate RSA keys (public and private) based on the specified bit length
    public final synchronized void generateKeys(int bits) {
        SecureRandom random = new SecureRandom();
        // Generate two large prime numbers p and q
        BigInteger p = new BigInteger(bits / 2, 100, random);
        BigInteger q = new BigInteger(bits / 2, 100, random);
        
        // Calculate the modulus as p * q
        modulus = p.multiply(q);
        
        // Calculate phi(n) = (p-1)(q-1)
        BigInteger phi = (p.subtract(BigInteger.ONE)).multiply(q.subtract(BigInteger.ONE));
        
        // Initialize the public key with a small odd number
        publicKey = BigInteger.valueOf(3L);
        
        // Ensure that publicKey is coprime to phi(n)
        while (phi.gcd(publicKey).intValue() > 1) {
            publicKey = publicKey.add(BigInteger.TWO);
        }
        
        // Calculate the private key as the modular inverse of publicKey mod phi(n)
        privateKey = publicKey.modInverse(phi);
    }

    // Main method to run the RSA encryption/decryption program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the bit length for key generation from user input
        int bits = scanner.nextInt();
        
        // Create an instance of Main to generate RSA keys
        Main rsa = new Main(bits);
        
        // Display the generated public key and modulus
        System.out.println("Public Key: " + rsa.publicKey);
        System.out.println("Modulus: " + rsa.modulus);
        
        // Read the operation type (encrypt or decrypt) from user input
        String operation = scanner.next();
        scanner.nextLine(); // Consume the newline character
        
        // Perform encryption if the user chose "encrypt"
        if (operation.equalsIgnoreCase("encrypt")) {
            String message = scanner.nextLine(); // Read the message to encrypt
            String encryptedMessage = rsa.encrypt(message); // Encrypt the message
            System.out.println("Encrypted Message: " + encryptedMessage); // Display the encrypted message
        } 
        // Perform decryption if the user chose "decrypt"
        else if (operation.equalsIgnoreCase("decrypt")) {
            String encryptedMessage = scanner.nextLine(); // Read the encrypted message
            String decryptedMessage = rsa.decrypt(encryptedMessage); // Decrypt the message
            System.out.println("Decrypted Message: " + decryptedMessage); // Display the decrypted message
        } 
        // Handle invalid operation input
        else {
            System.out.println("Invalid operation");
        }
        
        // Close the scanner to free resources
        scanner.close();
    }
}
