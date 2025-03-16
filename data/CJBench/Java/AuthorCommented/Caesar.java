
import java.util.Scanner;

/**
 * A Java implementation of Caesar Cipher.
 * It is a type of substitution cipher in which each letter in the plaintext
 * is replaced by a letter some fixed number of positions down the alphabet.
 */
public class Caesar {

    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String operation = scanner.nextLine().trim().toLowerCase();

        if ("encode".equals(operation)) {
            String plaintext = scanner.nextLine();
            int shift = scanner.nextInt();
            Caesar cipher = new Caesar();
            System.out.println("Encoded Message: " + cipher.encode(plaintext, shift));
        } else if ("decode".equals(operation)) {
            String encryptedText = scanner.nextLine();
            int shift = scanner.nextInt();
            Caesar cipher = new Caesar();
            System.out.println("Decoded Message: " + cipher.decode(encryptedText, shift));
        } else if ("bruteforce".equals(operation)) {
            String encryptedText = scanner.nextLine();
            Caesar cipher = new Caesar();
            String[] possibleSolutions = cipher.bruteforce(encryptedText);
            for (int i = 0; i < possibleSolutions.length; i++) {
                System.out.println("Shift " + i + ": " + possibleSolutions[i]);
            }
        } else {
            System.out.println("Invalid operation. Please enter encode, decode, or bruteforce.");
        }

        scanner.close();
    }

    /**
     * Encrypt text by shifting every Latin char by add number shift for ASCII
     * Example : A + 1 -> B
     *
     * @return Encrypted message
     */
    public String encode(String message, int shift) {
        StringBuilder encoded = new StringBuilder();
        shift %= 26;

        for (char current : message.toCharArray()) {
            if (isCapitalLatinLetter(current)) {
                //            int current = message.charAt(i); //using char to shift characters because
                //            ascii
                // is in-order latin alphabet
                current += shift;
                encoded.append((char) (current > 'Z' ? current - 26 : current));
            } else if (isSmallLatinLetter(current)) {
                current += shift;
                encoded.append((char) (current > 'z' ? current - 26 : current));
            } else {
                encoded.append(current);
            }
        }
        return encoded.toString();
    }

    /**
     * Decrypt message by shifting back every Latin char to previous the ASCII
     * Example : B - 1 -> A
     *
     * @return message
     */
    public String decode(String encryptedMessage, int shift) {
        StringBuilder decoded = new StringBuilder();
        shift %= 26;

        for (char current : encryptedMessage.toCharArray()) {
            if (isCapitalLatinLetter(current)) {
                current -= shift;
                decoded.append((char) (current < 'A' ? current + 26 : current));
            } else if (isSmallLatinLetter(current)) {
                current -= shift;
                decoded.append((char) (current < 'a' ? current + 26 : current));
            } else {
                decoded.append(current);
            }
        }
        return decoded.toString();
    }

    /**
     * @return true if character is capital Latin letter or false for others
     */
    private static boolean isCapitalLatinLetter(char c) {
        return c >= 'A' && c <= 'Z';
    }

    /**
     * @return true if character is small Latin letter or false for others
     */
    private static boolean isSmallLatinLetter(char c) {
        return c >= 'a' && c <= 'z';
    }

    /**
     *  @return string array which contains all the possible decoded combination.
     */
    public String[] bruteforce(String encryptedMessage) {
        String[] listOfAllTheAnswers = new String[27];
        for (int i = 0; i <= 26; i++) {
            listOfAllTheAnswers[i] = decode(encryptedMessage, i);
        }
        return listOfAllTheAnswers;
    }
}
