import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
public final class Main {
    // Morse code map for character to Morse code conversion
    private static final Map<Character, String> MORSE_MAP = new HashMap<>();
    // Reverse map for Morse code to character conversion
    private static final Map<String, Character> REVERSE_MAP = new HashMap<>();
    // Static block to initialize the Morse and Reverse maps
    static {
        MORSE_MAP.put('A', ".-");
        MORSE_MAP.put('B', "-...");
        MORSE_MAP.put('C', "-.-.");
        MORSE_MAP.put('D', "-..");
        MORSE_MAP.put('E', ".");
        MORSE_MAP.put('F', "..-.");
        MORSE_MAP.put('G', "--.");
        MORSE_MAP.put('H', "....");
        MORSE_MAP.put('I', "..");
        MORSE_MAP.put('J', ".---");
        MORSE_MAP.put('K', "-.-");
        MORSE_MAP.put('L', ".-..");
        MORSE_MAP.put('M', "--");
        MORSE_MAP.put('N', "-.");
        MORSE_MAP.put('O', "---");
        MORSE_MAP.put('P', ".--.");
        MORSE_MAP.put('Q', "--.-");
        MORSE_MAP.put('R', ".-.");
        MORSE_MAP.put('S', "...");
        MORSE_MAP.put('T', "-");
        MORSE_MAP.put('U', "..-");
        MORSE_MAP.put('V', "...-");
        MORSE_MAP.put('W', ".--");
        MORSE_MAP.put('X', "-..-");
        MORSE_MAP.put('Y', "-.--");
        MORSE_MAP.put('Z', "--..");
        // Populate the reverse map from Morse code to characters
        MORSE_MAP.forEach((k, v) -> REVERSE_MAP.put(v, k));
    }
    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the operation type from the user
        String operation = scanner.nextLine().trim().toLowerCase();
        // Perform the operation based on the user input
        switch (operation) {
            case "text-to-morse":
                // Read the text to be converted to Morse code
                String text = scanner.nextLine();
                // Convert the text to Morse code
                String morseCode = textToMorse(text);
                // Print the Morse code
                System.out.println("Morse Code: " + morseCode);
                break;
            case "morse-to-text":
                // Prompt the user to enter Morse code
                System.out.print("Enter the Morse code to convert to text: ");
                String morse = scanner.nextLine();
                // Convert the Morse code to text
                String convertedText = morseToText(morse);
                // Print the converted text
                System.out.println("Text: " + convertedText);
                break;
            default:
                // Print an error message for invalid operation
                System.out.println("Invalid operation. Please enter 'text-to-morse' or 'morse-to-text'.");
        }
        // Close the scanner
        scanner.close();
    }
    // Method to convert text to Morse code
    public static String textToMorse(String text) {
        StringBuilder morse = new StringBuilder();
        // Split the text into words
        String[] words = text.toUpperCase().split(" ");
        for (int i = 0; i < words.length; i++) {
            for (char c : words[i].toCharArray()) {
                // Append Morse code for each character
                morse.append(MORSE_MAP.getOrDefault(c, "")).append(" ");
            }
            if (i < words.length - 1) {
                morse.append("| ");
            }
        }
        return morse.toString().trim();
    }
    // Method to convert Morse code to text
    public static String morseToText(String morse) {
        StringBuilder text = new StringBuilder();
        // Split the Morse code into words
        String[] words = morse.split(" \\| ");
        for (int i = 0; i < words.length; i++) {
            for (String code : words[i].split(" ")) {
                // Convert each Morse code symbol back to a character
                text.append(REVERSE_MAP.getOrDefault(code, '?'));
            }
            if (i < words.length - 1) {
                text.append(" ");
            }
        }
        return text.toString();
    }
}
