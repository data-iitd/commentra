import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Scanner;

public class Main {
    // Private variables to store RSA keys
    private BigInteger modulus;
    private BigInteger privateKey;
    private BigInteger publicKey;

    // Constructor to initialize RSA keys
    public Main(int bits) {
        generateKeys(bits); // Generate RSA keys of the specified bit size
    }

    // Method to encrypt a message using RSA public key
    public synchronized String encrypt(String message) {
        if (message.isEmpty()) {
            throw new IllegalArgumentException("Message is empty");
        }
        // Convert message to BigInteger, encrypt it, and return as string
        return (new BigInteger(message.getBytes())).modPow(publicKey, modulus).toString();
    }

    // Method to decrypt an encrypted message using RSA private key
    public synchronized String decrypt(String encryptedMessage) {
        if (encryptedMessage.isEmpty()) {
            throw new IllegalArgumentException("Message is empty");
        }
        // Convert encrypted message to BigInteger, decrypt it, and convert back to string
        return new String((new BigInteger(encryptedMessage)).modPow(privateKey, modulus).toByteArray());
    }

    // Method to generate RSA keys of the specified bit size
    public final synchronized void generateKeys(int bits) {
        SecureRandom random = new SecureRandom();
        // Generate two large prime numbers p and q
        BigInteger p = new BigInteger(bits / 2, 100, random);
        BigInteger q = new BigInteger(bits / 2, 100, random);
        // Calculate modulus as the product of p and q
        modulus = p.multiply(q);
        // Calculate the totient function phi
        BigInteger phi = (p.subtract(BigInteger.ONE)).multiply(q.subtract(BigInteger.ONE));
        // Initialize public key to 3 and ensure it is coprime with phi
        publicKey = BigInteger.valueOf(3L);
        while (phi.gcd(publicKey).intValue() > 1) {
            publicKey = publicKey.add(BigInteger.TWO);
        }
        // Calculate private key as the modular inverse of public key mod phi
        privateKey = publicKey.modInverse(phi);
    }

    // Main method to run the RSA encryption/decryption application
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of bits for the key size
        int bits = scanner.nextInt();
        Main rsa = new Main(bits);
        // Print the public key and modulus
        System.out.println("Public Key: " + rsa.publicKey);
        System.out.println("Modulus: " + rsa.modulus);
        // Read the operation (encrypt or decrypt) and the message
        String operation = scanner.next();
        scanner.nextLine(); 
        if (operation.equalsIgnoreCase("encrypt")) {
            String message = scanner.nextLine();
            String encryptedMessage = rsa.encrypt(message);
            System.out.println("Encrypted Message: " + encryptedMessage);
        } else if (operation.equalsIgnoreCase("decrypt")) {
            String encryptedMessage = scanner.nextLine();
            String decryptedMessage = rsa.decrypt(encryptedMessage);
            System.out.println("Decrypted Message: " + decryptedMessage);
        } else {
            System.out.println("Invalid operation");
        }
        scanner.close();
    }
}
