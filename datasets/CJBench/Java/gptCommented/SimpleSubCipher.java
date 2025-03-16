import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Method to encode a message using a given cipher
    public static String encode(String message, String cipherSmall) {
        StringBuilder encoded = new StringBuilder(); // StringBuilder to hold the encoded message
        Map<Character, Character> cipherMap = new HashMap<>(); // Map to hold the character mapping for encoding
        char beginSmallLetter = 'a'; // Starting character for lowercase letters
        char beginCapitalLetter = 'A'; // Starting character for uppercase letters
        
        // Convert the cipher to lowercase and uppercase
        cipherSmall = cipherSmall.toLowerCase();
        String cipherCapital = cipherSmall.toUpperCase();
        
        // Populate the cipherMap with character mappings for both lowercase and uppercase letters
        for (int i = 0; i < cipherSmall.length(); i++) {
            cipherMap.put(beginSmallLetter++, cipherSmall.charAt(i)); // Map lowercase letters
            cipherMap.put(beginCapitalLetter++, cipherCapital.charAt(i)); // Map uppercase letters
        }
        
        // Encode the message using the cipherMap
        for (int i = 0; i < message.length(); i++) {
            if (Character.isAlphabetic(message.charAt(i))) { // Check if the character is alphabetic
                encoded.append(cipherMap.get(message.charAt(i))); // Append the encoded character
            } else {
                encoded.append(message.charAt(i)); // Append non-alphabetic characters unchanged
            }
        }
        return encoded.toString(); // Return the encoded message
    }

    // Method to decode an encrypted message using a given cipher
    public static String decode(String encryptedMessage, String cipherSmall) {
        StringBuilder decoded = new StringBuilder(); // StringBuilder to hold the decoded message
        Map<Character, Character> cipherMap = new HashMap<>(); // Map to hold the character mapping for decoding
        char beginSmallLetter = 'a'; // Starting character for lowercase letters
        char beginCapitalLetter = 'A'; // Starting character for uppercase letters
        
        // Convert the cipher to lowercase and uppercase
        cipherSmall = cipherSmall.toLowerCase();
        String cipherCapital = cipherSmall.toUpperCase();
        
        // Populate the cipherMap with character mappings for decoding
        for (int i = 0; i < cipherSmall.length(); i++) {
            cipherMap.put(cipherSmall.charAt(i), beginSmallLetter++); // Map lowercase letters
            cipherMap.put(cipherCapital.charAt(i), beginCapitalLetter++); // Map uppercase letters
        }
        
        // Decode the encrypted message using the cipherMap
        for (int i = 0; i < encryptedMessage.length(); i++) {
            if (Character.isAlphabetic(encryptedMessage.charAt(i))) { // Check if the character is alphabetic
                decoded.append(cipherMap.get(encryptedMessage.charAt(i))); // Append the decoded character
            } else {
                decoded.append(encryptedMessage.charAt(i)); // Append non-alphabetic characters unchanged
            }
        }
        return decoded.toString(); // Return the decoded message
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object for user input
        String cipherAlphabet = sc.nextLine(); // Read the cipher alphabet from user input
        String operation = sc.nextLine(); // Read the operation (encode/decode) from user input
        
        // Check if the operation is to encode
        if ("encode".equalsIgnoreCase(operation)) {
            String message = sc.nextLine(); // Read the message to encode
            String encryptedMessage = encode(message, cipherAlphabet); // Encode the message
            System.out.println("Encrypted Message: " + encryptedMessage); // Output the encoded message
        } 
        // Check if the operation is to decode
        else if ("decode".equalsIgnoreCase(operation)) {
            String encryptedMessage = sc.nextLine(); // Read the encrypted message to decode
            String decryptedMessage = decode(encryptedMessage, cipherAlphabet); // Decode the message
            System.out.println("Decrypted Message: " + decryptedMessage); // Output the decoded message
        } 
        // Handle invalid operation input
        else {
            System.out.println("Invalid operation. Please enter 'encode' or 'decode'.");
        }
        
        sc.close(); // Close the scanner to prevent resource leaks
    }
}
