import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the operation type (encode, decode, bruteforce) from the user input
        String operation = scanner.nextLine().trim().toLowerCase();
        
        // Check if the operation is to encode a message
        if ("encode".equals(operation)) {
            // Read the plaintext message to be encoded
            String plaintext = scanner.nextLine();
            // Read the shift value for encoding
            int shift = scanner.nextInt();
            Main cipher = new Main();
            // Output the encoded message
            System.out.println("Encoded Message: " + cipher.encode(plaintext, shift));
        } 
        // Check if the operation is to decode a message
        else if ("decode".equals(operation)) {
            // Read the encrypted message to be decoded
            String encryptedText = scanner.nextLine();
            // Read the shift value for decoding
            int shift = scanner.nextInt();
            Main cipher = new Main();
            // Output the decoded message
            System.out.println("Decoded Message: " + cipher.decode(encryptedText, shift));
        } 
        // Check if the operation is to perform a brute force attack
        else if ("bruteforce".equals(operation)) {
            // Read the encrypted message for brute force decoding
            String encryptedText = scanner.nextLine();
            Main cipher = new Main();
            // Get all possible decoded messages using brute force
            String[] possibleSolutions = cipher.bruteforce(encryptedText);
            // Print all possible solutions with their respective shift values
            for (int i = 0; i < possibleSolutions.length; i++) {
                System.out.println("Shift " + i + ": " + possibleSolutions[i]);
            }
        } 
        // Handle invalid operation input
        else {
            System.out.println("Invalid operation. Please enter encode, decode, or bruteforce.");
        }
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    // Method to encode a message using a specified shift
    public String encode(String message, int shift) {
        StringBuilder encoded = new StringBuilder();
        // Normalize the shift value to be within 0-25
        shift %= 26;
        
        // Iterate through each character in the message
        for (char current : message.toCharArray()) {
            // Check if the character is a capital Latin letter
            if (isCapitalLatinLetter(current)) {
                current += shift; // Apply the shift
                // Wrap around if it exceeds 'Z'
                encoded.append((char) (current > 'Z' ? current - 26 : current));
            } 
            // Check if the character is a small Latin letter
            else if (isSmallLatinLetter(current)) {
                current += shift; // Apply the shift
                // Wrap around if it exceeds 'z'
                encoded.append((char) (current > 'z' ? current - 26 : current));
            } 
            // If it's neither, append the character as is
            else {
                encoded.append(current);
            }
        }
        // Return the encoded message as a string
        return encoded.toString();
    }

    // Method to decode an encrypted message using a specified shift
    public String decode(String encryptedMessage, int shift) {
        StringBuilder decoded = new StringBuilder();
        // Normalize the shift value to be within 0-25
        shift %= 26;
        
        // Iterate through each character in the encrypted message
        for (char current : encryptedMessage.toCharArray()) {
            // Check if the character is a capital Latin letter
            if (isCapitalLatinLetter(current)) {
                current -= shift; // Apply the reverse shift
                // Wrap around if it goes below 'A'
                decoded.append((char) (current < 'A' ? current + 26 : current));
            } 
            // Check if the character is a small Latin letter
            else if (isSmallLatinLetter(current)) {
                current -= shift; // Apply the reverse shift
                // Wrap around if it goes below 'a'
                decoded.append((char) (current < 'a' ? current + 26 : current));
            } 
            // If it's neither, append the character as is
            else {
                decoded.append(current);
            }
        }
        // Return the decoded message as a string
        return decoded.toString();
    }

    // Helper method to check if a character is a capital Latin letter
    private static boolean isCapitalLatinLetter(char c) {
        return c >= 'A' && c <= 'Z';
    }

    // Helper method to check if a character is a small Latin letter
    private static boolean isSmallLatinLetter(char c) {
        return c >= 'a' && c <= 'z';
    }

    // Method to perform a brute force attack on an encrypted message
    public String[] bruteforce(String encryptedMessage) {
        String[] listOfAllTheAnswers = new String[27]; // Array to hold all possible decoded messages
        // Try all shifts from 0 to 26
        for (int i = 0; i <= 26; i++) {
            listOfAllTheAnswers[i] = decode(encryptedMessage, i); // Decode with the current shift
        }
        // Return the array of possible solutions
        return listOfAllTheAnswers;
    }
}
