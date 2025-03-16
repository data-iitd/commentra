import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize Scanner to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the operation type from the input
        String operation = scanner.nextLine().trim().toLowerCase();
        
        // Check which operation is selected and proceed accordingly
        if ("encode".equals(operation)) {
            // Read the plaintext message from the input
            String plaintext = scanner.nextLine();
            // Read the shift value from the input
            int shift = scanner.nextInt();
            // Create a new instance of the Main class to call the encode method
            Main cipher = new Main();
            // Print the encoded message
            System.out.println("Encoded Message: " + cipher.encode(plaintext, shift));
        } else if ("decode".equals(operation)) {
            // Read the encrypted message from the input
            String encryptedText = scanner.nextLine();
            // Read the shift value from the input
            int shift = scanner.nextInt();
            // Create a new instance of the Main class to call the decode method
            Main cipher = new Main();
            // Print the decoded message
            System.out.println("Decoded Message: " + cipher.decode(encryptedText, shift));
        } else if ("bruteforce".equals(operation)) {
            // Read the encrypted message from the input
            String encryptedText = scanner.nextLine();
            // Create a new instance of the Main class to call the bruteforce method
            Main cipher = new Main();
            // Get all possible decoded messages using bruteforce
            String[] possibleSolutions = cipher.bruteforce(encryptedText);
            // Print each decoded message with its corresponding shift
            for (int i = 0; i < possibleSolutions.length; i++) {
                System.out.println("Shift " + i + ": " + possibleSolutions[i]);
            }
        } else {
            // Print an error message if the operation is invalid
            System.out.println("Invalid operation. Please enter encode, decode, or bruteforce.");
        }
        
        // Close the Scanner to free up resources
        scanner.close();
    }
    
    // Encode method to shift characters in a message
    public String encode(String message, int shift) {
        StringBuilder encoded = new StringBuilder();
        // Normalize the shift value to ensure it is within the range of 0-25
        shift %= 26;
        // Iterate over each character in the message
        for (char current : message.toCharArray()) {
            // Check if the character is an uppercase Latin letter and shift it
            if (isCapitalLatinLetter(current)) {
                current += shift;
                encoded.append((char) (current > 'Z' ? current - 26 : current));
            } else if (isSmallLatinLetter(current)) { // Check if the character is a lowercase Latin letter and shift it
                current += shift;
                encoded.append((char) (current > 'z' ? current - 26 : current));
            } else {
                // Append the character as is if it is not a Latin letter
                encoded.append(current);
            }
        }
        // Return the encoded message
        return encoded.toString();
    }
    
    // Decode method to shift characters in a message back
    public String decode(String encryptedMessage, int shift) {
        StringBuilder decoded = new StringBuilder();
        // Normalize the shift value to ensure it is within the range of 0-25
        shift %= 26;
        // Iterate over each character in the encrypted message
        for (char current : encryptedMessage.toCharArray()) {
            // Check if the character is an uppercase Latin letter and shift it back
            if (isCapitalLatinLetter(current)) {
                current -= shift;
                decoded.append((char) (current < 'A' ? current + 26 : current));
            } else if (isSmallLatinLetter(current)) { // Check if the character is a lowercase Latin letter and shift it back
                current -= shift;
                decoded.append((char) (current < 'a' ? current + 26 : current));
            } else {
                // Append the character as is if it is not a Latin letter
                decoded.append(current);
            }
        }
        // Return the decoded message
        return decoded.toString();
    }
    
    // Helper method to check if a character is an uppercase Latin letter
    private static boolean isCapitalLatinLetter(char c) {
        return c >= 'A' && c <= 'Z';
    }
    
    // Helper method to check if a character is a lowercase Latin letter
    private static boolean isSmallLatinLetter(char c) {
        return c >= 'a' && c <= 'z';
    }
    
    // Bruteforce method to decode the message using all possible shifts
    public String[] bruteforce(String encryptedMessage) {
        String[] listOfAllTheAnswers = new String[27];
        // Attempt to decode the message using each possible shift
        for (int i = 0; i <= 26; i++) {
            listOfAllTheAnswers[i] = decode(encryptedMessage, i);
        }
        // Return the array of decoded messages
        return listOfAllTheAnswers;
    }
}
