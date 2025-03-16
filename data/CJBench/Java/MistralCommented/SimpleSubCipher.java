
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Method to encode a message using a given cipher alphabet
    public static String encode(String message, String cipherSmall) {
        StringBuilder encoded = new StringBuilder(); // Initialize an empty StringBuilder to store the encoded message

        Map<Character, Character> cipherMap = new HashMap<>(); // Create an empty HashMap to store the cipher mapping

        char beginSmallLetter = 'a'; // Initialize the small letter index to 'a'
        char beginCapitalLetter = 'A'; // Initialize the capital letter index to 'A'

        // Set the cipher alphabet for small and capital letters
        cipherSmall = cipherSmall.toLowerCase();
        String cipherCapital = cipherSmall.toUpperCase();

        // Build the cipher map by iterating through the cipher alphabet
        for (int i = 0; i < cipherSmall.length(); i++) {
            cipherMap.put(beginSmallLetter++, cipherSmall.charAt(i)); // Map small letters
            cipherMap.put(beginCapitalLetter++, cipherCapital.charAt(i)); // Map capital letters
        }

        // Iterate through the message and encode each character
        for (int i = 0; i < message.length(); i++) {
            if (Character.isAlphabetic(message.charAt(i))) { // If the character is alphabetic
                encoded.append(cipherMap.get(message.charAt(i))); // Append the encoded character to the StringBuilder
            } else {
                encoded.append(message.charAt(i)); // If the character is not alphabetic, append it as is
            }
        }

        // Return the encoded message as a String
        return encoded.toString();
    }

    // Method to decode a message using a given cipher alphabet
    public static String decode(String encryptedMessage, String cipherSmall) {
        StringBuilder decoded = new StringBuilder(); // Initialize an empty StringBuilder to store the decoded message

        Map<Character, Character> cipherMap = new HashMap<>(); // Create an empty HashMap to store the cipher mapping

        char beginSmallLetter = 'a'; // Initialize the small letter index to 'a'
        char beginCapitalLetter = 'A'; // Initialize the capital letter index to 'A'

        // Set the cipher alphabet for small and capital letters
        cipherSmall = cipherSmall.toLowerCase();
        String cipherCapital = cipherSmall.toUpperCase();

        // Build the cipher map by iterating through the cipher alphabet
        for (int i = 0; i < cipherSmall.length(); i++) {
            cipherMap.put(cipherSmall.charAt(i), beginSmallLetter++); // Map small letters
            cipherMap.put(cipherCapital.charAt(i), beginCapitalLetter++); // Map capital letters
        }

        // Iterate through the encrypted message and decode each character
        for (int i = 0; i < encryptedMessage.length(); i++) {
            if (Character.isAlphabetic(encryptedMessage.charAt(i))) { // If the character is alphabetic
                decoded.append(cipherMap.get(encryptedMessage.charAt(i))); // Append the decoded character to the StringBuilder
            } else {
                decoded.append(encryptedMessage.charAt(i)); // If the character is not alphabetic, append it as is
            }
        }

        // Return the decoded message as a String
        return decoded.toString();
    }

    // Main method to read user input and call the appropriate encoding or decoding method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize a Scanner to read user input

        String cipherAlphabet = sc.nextLine(); // Read the cipher alphabet from user input
        String operation = sc.nextLine(); // Read the operation ('encode' or 'decode') from user input

        if ("encode".equalsIgnoreCase(operation)) { // If the operation is 'encode'
            String message = sc.nextLine(); // Read the message to be encoded from user input
            String encryptedMessage = encode(message, cipherAlphabet); // Call the encode method and store the result
            System.out.println("Encrypted Message: " + encryptedMessage); // Print the encrypted message to the console
        } else if ("decode".equalsIgnoreCase(operation)) { // If the operation is 'decode'
            String encryptedMessage = sc.nextLine(); // Read the encrypted message from user input
            String decryptedMessage = decode(encryptedMessage, cipherAlphabet); // Call the decode method and store the result
            System.out.println("Decrypted Message: " + decryptedMessage); // Print the decrypted message to the console
        } else { // If the operation is not 'encode' or 'decode'
            System.out.println("Invalid operation. Please enter 'encode' or 'decode'."); // Print an error message to the console
        }

        sc.close(); // Close the Scanner to free system resources
    }
}