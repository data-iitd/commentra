
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public final class Main {
    // Initialize a HashMap named MORSE_MAP to store Morse code mappings for each English alphabet character.
    private static final Map<Character, String> MORSE_MAP = new HashMap<>();

    // Initialize a HashMap named REVERSE_MAP to store the reverse mapping of Morse code to English alphabet characters.
    private static final Map<String, Character> REVERSE_MAP = new HashMap<>();

    static {
        // Initialize MORSE_MAP with Morse code mappings for each English alphabet character.
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

        // Initialize REVERSE_MAP with reverse mappings of Morse code to English alphabet characters.
        MORSE_MAP.forEach((k, v) -> REVERSE_MAP.put(v, k));
    }

    public static void main(String[] args) {
        // Initialize a Scanner object to read user input.
        Scanner scanner = new Scanner(System.in);

        // Read user operation from the console.
        String operation = scanner.nextLine().trim().toLowerCase();

        // Switch the user operation and call the corresponding method.
        switch (operation) {
            case "text-to-morse":
                // Read text from the console.
                String text = scanner.nextLine();

                // Convert text to Morse code and print it to the console.
                String morseCode = textToMorse(text);
                System.out.println("Morse Code: " + morseCode);
                break;
            case "morse-to-text":
                // Read Morse code from the console.
                System.out.print("Enter the Morse code to convert to text: ");
                String morse = scanner.nextLine();

                // Convert Morse code to text and print it to the console.
                String convertedText = morseToText(morse);
                System.out.println("Text: " + convertedText);
                break;
            default:
                // Print an error message if the user enters an invalid operation.
                System.out.println("Invalid operation. Please enter 'text-to-morse' or 'morse-to-text'.");
        }

        // Close the Scanner object.
        scanner.close();
    }

    // Convert text to Morse code.
    public static String textToMorse(String text) {
        // Initialize a StringBuilder object to store Morse code.
        StringBuilder morse = new StringBuilder();

        // Split text into words and iterate through each character in each word.
        String[] words = text.toUpperCase().split(" ");
        for (int i = 0; i < words.length; i++) {
            for (char c : words[i].toCharArray()) {
                // Append Morse code for the character to the StringBuilder object.
                morse.append(MORSE_MAP.getOrDefault(c, "")).append(" ");
            }

            // Add a separator "| " between words, except for the last word.
            if (i < words.length - 1) {
                morse.append("| ");
            }
        }

        // Return the Morse code as a String.
        return morse.toString().trim();
    }

    // Convert Morse code to text.
    public static String morseToText(String morse) {
        // Initialize a StringBuilder object to store text.
        StringBuilder text = new StringBuilder();

        // Split Morse code into words and iterate through each character in each word.
        String[] words = morse.split(" \\| ");
        for (int i = 0; i < words.length; i++) {
            for (String code : words[i].split(" ")) {
                // Append the English alphabet character corresponding to the Morse code to the StringBuilder object.
                text.append(REVERSE_MAP.getOrDefault(code, '?'));
            }

            // Add a separator " " between words, except for the last word.
            if (i < words.length - 1) {
                text.append(" ");
            }
        }

        // Return the text as a String.
        return text.toString();
    }
}