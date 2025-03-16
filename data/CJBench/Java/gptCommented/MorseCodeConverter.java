import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public final class Main {
    // Maps each character to its corresponding Morse code representation
    private static final Map<Character, String> MORSE_MAP = new HashMap<>();
    // Maps each Morse code representation back to its corresponding character
    private static final Map<String, Character> REVERSE_MAP = new HashMap<>();

    // Static block to initialize the Morse code mappings
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
        // Populate the reverse map for Morse to character conversion
        MORSE_MAP.forEach((k, v) -> REVERSE_MAP.put(v, k));
    }

    public static void main(String[] args) {
        // Create a scanner to read user input
        Scanner scanner = new Scanner(System.in);
        // Read the operation type (text-to-morse or morse-to-text)
        String operation = scanner.nextLine().trim().toLowerCase();
        
        // Determine the operation based on user input
        switch (operation) {
            case "text-to-morse":
                // Read the text input to convert to Morse code
                String text = scanner.nextLine();
                // Convert the text to Morse code
                String morseCode = textToMorse(text);
                // Output the resulting Morse code
                System.out.println("Morse Code: " + morseCode);
                break;
            case "morse-to-text":
                // Prompt user for Morse code input
                System.out.print("Enter the Morse code to convert to text: ");
                String morse = scanner.nextLine();
                // Convert the Morse code to text
                String convertedText = morseToText(morse);
                // Output the resulting text
                System.out.println("Text: " + convertedText);
                break;
            default:
                // Handle invalid operation input
                System.out.println("Invalid operation. Please enter 'text-to-morse' or 'morse-to-text'.");
        }
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    // Method to convert text to Morse code
    public static String textToMorse(String text) {
        StringBuilder morse = new StringBuilder();
        // Split the input text into words
        String[] words = text.toUpperCase().split(" ");
        // Iterate through each word
        for (int i = 0; i < words.length; i++) {
            // Iterate through each character in the word
            for (char c : words[i].toCharArray()) {
                // Append the Morse code for the character, or an empty string if not found
                morse.append(MORSE_MAP.getOrDefault(c, "")).append(" ");
            }
            // Append a separator for words, except for the last word
            if (i < words.length - 1) {
                morse.append("| ");
            }
        }
        // Return the Morse code as a trimmed string
        return morse.toString().trim();
    }

    // Method to convert Morse code to text
    public static String morseToText(String morse) {
        StringBuilder text = new StringBuilder();
        // Split the Morse code into words based on the separator
        String[] words = morse.split(" \\| ");
        // Iterate through each Morse code word
        for (int i = 0; i < words.length; i++) {
            // Iterate through each Morse code character in the word
            for (String code : words[i].split(" ")) {
                // Append the corresponding character, or '?' if not found
                text.append(REVERSE_MAP.getOrDefault(code, '?'));
            }
            // Append a space between words, except for the last word
            if (i < words.length - 1) {
                text.append(" ");
            }
        }
        // Return the converted text
        return text.toString();
    }
}
