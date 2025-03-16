import java.util.Scanner;

// This class contains the main method that starts the program
public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read the user's operation from the input
        String operation = scanner.nextLine().trim().toLowerCase();

        // Check which operation the user wants to perform
        if ("encode".equals(operation)) {
            // Read the plaintext and shift value from the input
            String plaintext = scanner.nextLine();
            int shift = scanner.nextInt();

            // Create an instance of the Main class to use the encode method
            Main cipher = new Main();

            // Print the encoded message
            System.out.println("Encoded Message: " + cipher.encode(plaintext, shift));
        } else if ("decode".equals(operation)) {
            // Read the encrypted text and shift value from the input
            String encryptedText = scanner.nextLine();
            int shift = scanner.nextInt();

            // Create an instance of the Main class to use the decode method
            Main cipher = new Main();

            // Print the decoded message
            System.out.println("Decoded Message: " + cipher.decode(encryptedText, shift));
        } else if ("bruteforce".equals(operation)) {
            // Read the encrypted text from the input
            String encryptedText = scanner.nextLine();

            // Create an instance of the Main class to use the bruteforce method
            Main cipher = new Main();

            // Get all possible solutions by brute-forcing
            String[] possibleSolutions = cipher.bruteforce(encryptedText);

            // Print all possible solutions
            for (int i = 0; i < possibleSolutions.length; i++) {
                System.out.println("Shift " + i + ": " + possibleSolutions[i]);
            }
        } else {
            // If the user entered an invalid operation, print an error message
            System.out.println("Invalid operation. Please enter encode, decode, or bruteforce.");
        }

        // Close the Scanner object
        scanner.close();
    }

    // Method to encode a message using a given shift value
    public String encode(String message, int shift) {
        StringBuilder encoded = new StringBuilder();

        // Make sure the shift value is within the valid range (0-25)
        shift %= 26;

        // Iterate through each character in the message
        for (char current : message.toCharArray()) {
            // If the character is a capital Latin letter, add the shift value and handle the wrap-around
            if (isCapitalLatinLetter(current)) {
                current += shift;
                encoded.append((char) (current > 'Z' ? current - 26 : current));
            }
            // If the character is a small Latin letter, add the shift value and handle the wrap-around
            else if (isSmallLatinLetter(current)) {
                current += shift;
                encoded.append((char) (current > 'z' ? current - 26 : current));
            }
            // If the character is not a letter, just append it to the encoded message
            else {
                encoded.append(current);
            }
        }

        // Return the encoded message as a String
        return encoded.toString();
    }

    // Method to decode a message using a given shift value
    public String decode(String encryptedMessage, int shift) {
        StringBuilder decoded = new StringBuilder();

        // Make sure the shift value is within the valid range (0-25)
        shift %= 26;

        // Iterate through each character in the encrypted message
        for (char current : encryptedMessage.toCharArray()) {
            // If the character is a capital Latin letter, subtract the shift value and handle the wrap-around
            if (isCapitalLatinLetter(current)) {
                current -= shift;
                decoded.append((char) (current < 'A' ? current + 26 : current));
            }
            // If the character is a small Latin letter, subtract the shift value and handle the wrap-around
            else if (isSmallLatinLetter(current)) {
                current -= shift;
                decoded.append((char) (current < 'a' ? current + 26 : current));
            }
            // If the character is not a letter, just append it to the decoded message
            else {
                decoded.append(current);
            }
        }

        // Return the decoded message as a String
        return decoded.toString();
    }

    // Helper method to check if a character is a capital Latin letter
    private static boolean isCapitalLatinLetter(char c) {
        // Return true if the character is a capital Latin letter, false otherwise
        return c >= 'A' && c <= 'Z';
    }

    // Helper method to check if a character is a small Latin letter
    private static boolean isSmallLatinLetter(char c) {
        // Return true if the character is a small Latin letter, false otherwise
        return c >= 'a' && c <= 'z';
    }

    // Method to bruteforce the shift value for a given encrypted message
    public String[] bruteforce(String encryptedMessage) {
        String[] listOfAllTheAnswers = new String[27];

        // Iterate through all possible shift values (0-25) and decode the message for each shift value
        for (int i = 0; i <= 26; i++) {
            listOfAllTheAnswers[i] = decode(encryptedMessage, i);
        }

        // Return the array of all possible decoded messages
        return listOfAllTheAnswers;
    }
}
