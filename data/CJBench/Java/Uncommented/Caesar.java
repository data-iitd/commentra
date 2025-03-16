
import java.util.Scanner;
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
            System.out.println("Enter the encrypted text:");
            String encryptedText = scanner.nextLine();
            System.out.println("Enter the shift value:");
            int shift = scanner.nextInt();
            Caesar cipher = new Caesar();
            System.out.println("Decoded Message: " + cipher.decode(encryptedText, shift));
        } else if ("bruteforce".equals(operation)) {
            System.out.println("Enter the encrypted text:");
            String encryptedText = scanner.nextLine();
            Caesar cipher = new Caesar();
            String[] possibleSolutions = cipher.bruteforce(encryptedText);
            System.out.println("Possible Decoded Messages:");
            for (int i = 0; i < possibleSolutions.length; i++) {
                System.out.println("Shift " + i + ": " + possibleSolutions[i]);
            }
        } else {
            System.out.println("Invalid operation. Please enter encode, decode, or bruteforce.");
        }
        scanner.close();
    }
    public String encode(String message, int shift) {
        StringBuilder encoded = new StringBuilder();
        shift %= 26;
        for (char current : message.toCharArray()) {
            if (isCapitalLatinLetter(current)) {
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
    private static boolean isCapitalLatinLetter(char c) {
        return c >= 'A' && c <= 'Z';
    }
    private static boolean isSmallLatinLetter(char c) {
        return c >= 'a' && c <= 'z';
    }
    public String[] bruteforce(String encryptedMessage) {
        String[] listOfAllTheAnswers = new String[27];
        for (int i = 0; i <= 26; i++) {
            listOfAllTheAnswers[i] = decode(encryptedMessage, i);
        }
        return listOfAllTheAnswers;
    }
}
