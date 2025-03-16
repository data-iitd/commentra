import java.util.HashMap; // Importing HashMap and Map for creating a cipher map
import java.util.Map; // Importing Map for creating a cipher map
import java.util.Scanner; // Importing Scanner for reading input from the user

public class Main { // Main class containing the main method
    public static String encode(String message, String cipherSmall) { // Method to encode a message using a cipher alphabet
        StringBuilder encoded = new StringBuilder(); // StringBuilder to build the encoded message
        Map<Character, Character> cipherMap = new HashMap<>(); // Map to store the cipher alphabet
        char beginSmallLetter = 'a'; // Starting character for small letters
        char beginCapitalLetter = 'A'; // Starting character for capital letters
        cipherSmall = cipherSmall.toLowerCase(); // Converting cipherSmall to lowercase
        String cipherCapital = cipherSmall.toUpperCase(); // Creating an uppercase version of cipherSmall
        for (int i = 0; i < cipherSmall.length(); i++) { // Populating the cipher map
            cipherMap.put(beginSmallLetter++, cipherSmall.charAt(i)); // Mapping small letters
            cipherMap.put(beginCapitalLetter++, cipherCapital.charAt(i)); // Mapping capital letters
        }
        for (int i = 0; i < message.length(); i++) { // Iterating through the message
            if (Character.isAlphabetic(message.charAt(i))) { // Checking if the character is alphabetic
                encoded.append(cipherMap.get(message.charAt(i))); // Appending the encoded character
            } else {
                encoded.append(message.charAt(i)); // Appending non-alphabetic characters unchanged
            }
        }
        return encoded.toString(); // Returning the encoded message
    }

    public static String decode(String encryptedMessage, String cipherSmall) { // Method to decode an encrypted message using a cipher alphabet
        StringBuilder decoded = new StringBuilder(); // StringBuilder to build the decoded message
        Map<Character, Character> cipherMap = new HashMap<>(); // Map to store the cipher alphabet
        char beginSmallLetter = 'a'; // Starting character for small letters
        char beginCapitalLetter = 'A'; // Starting character for capital letters
        cipherSmall = cipherSmall.toLowerCase(); // Converting cipherSmall to lowercase
        String cipherCapital = cipherSmall.toUpperCase(); // Creating an uppercase version of cipherSmall
        for (int i = 0; i < cipherSmall.length(); i++) { // Populating the cipher map
            cipherMap.put(cipherSmall.charAt(i), beginSmallLetter++); // Mapping small letters
            cipherMap.put(cipherCapital.charAt(i), beginCapitalLetter++); // Mapping capital letters
        }
        for (int i = 0; i < encryptedMessage.length(); i++) { // Iterating through the encrypted message
            if (Character.isAlphabetic(encryptedMessage.charAt(i))) { // Checking if the character is alphabetic
                decoded.append(cipherMap.get(encryptedMessage.charAt(i))); // Appending the decoded character
            } else {
                decoded.append(encryptedMessage.charAt(i)); // Appending non-alphabetic characters unchanged
            }
        }
        return decoded.toString(); // Returning the decoded message
    }

    public static void main(String[] args) { // Main method - entry point of the program
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input
        String cipherAlphabet = sc.nextLine(); // Reading the cipher alphabet from the user
        String operation = sc.nextLine(); // Reading the operation type (encode or decode) from the user
        if ("encode".equalsIgnoreCase(operation)) { // Checking if the operation is encode
            String message = sc.nextLine(); // Reading the message to be encoded
            String encryptedMessage = encode(message, cipherAlphabet); // Encoding the message
            System.out.println("Encrypted Message: " + encryptedMessage); // Printing the encrypted message
        } else if ("decode".equalsIgnoreCase(operation)) { // Checking if the operation is decode
            String encryptedMessage = sc.nextLine(); // Reading the encrypted message to be decoded
            String decryptedMessage = decode(encryptedMessage, cipherAlphabet); // Decoding the message
            System.out.println("Decrypted Message: " + decryptedMessage); // Printing the decrypted message
        } else {
            System.out.println("Invalid operation. Please enter 'encode' or 'decode'."); // Printing an error message for invalid operation
        }
        sc.close(); // Closing the Scanner
    }
}
