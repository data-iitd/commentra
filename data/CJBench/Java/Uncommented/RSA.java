
import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Scanner;
public class RSA {
    private BigInteger modulus;
    private BigInteger privateKey;
    private BigInteger publicKey;
    public RSA(int bits) {
        generateKeys(bits);
    }
    public synchronized String encrypt(String message) {
        if (message.isEmpty()) {
            throw new IllegalArgumentException("Message is empty");
        }
        return (new BigInteger(message.getBytes())).modPow(publicKey, modulus).toString();
    }
    public synchronized String decrypt(String encryptedMessage) {
        if (encryptedMessage.isEmpty()) {
            throw new IllegalArgumentException("Message is empty");
        }
        return new String((new BigInteger(encryptedMessage)).modPow(privateKey, modulus).toByteArray());
    }
    public final synchronized void generateKeys(int bits) {
        SecureRandom random = new SecureRandom();
        BigInteger p = new BigInteger(bits / 2, 100, random);
        BigInteger q = new BigInteger(bits / 2, 100, random);
        modulus = p.multiply(q);
        BigInteger phi = (p.subtract(BigInteger.ONE)).multiply(q.subtract(BigInteger.ONE));
        publicKey = BigInteger.valueOf(3L);
        while (phi.gcd(publicKey).intValue() > 1) {
            publicKey = publicKey.add(BigInteger.TWO);
        }
        privateKey = publicKey.modInverse(phi);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int bits = scanner.nextInt();
        RSA rsa = new RSA(bits);
        System.out.println("Public Key: " + rsa.publicKey);
        System.out.println("Modulus: " + rsa.modulus);
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
