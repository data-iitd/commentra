
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
public final class MorseCodeConverter {
    private static final Map<Character, String> MORSE_MAP = new HashMap<>();
    private static final Map<String, Character> REVERSE_MAP = new HashMap<>();
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
        MORSE_MAP.forEach((k, v) -> REVERSE_MAP.put(v, k));
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String operation = scanner.nextLine().trim().toLowerCase();
        switch (operation) {
            case "text-to-morse":
                String text = scanner.nextLine();
                String morseCode = textToMorse(text);
                System.out.println("Morse Code: " + morseCode);
                break;
            case "morse-to-text":
                System.out.print("Enter the Morse code to convert to text: ");
                String morse = scanner.nextLine();
                String convertedText = morseToText(morse);
                System.out.println("Text: " + convertedText);
                break;
            default:
                System.out.println("Invalid operation. Please enter 'text-to-morse' or 'morse-to-text'.");
        }
        scanner.close();
    }
    public static String textToMorse(String text) {
        StringBuilder morse = new StringBuilder();
        String[] words = text.toUpperCase().split(" ");
        for (int i = 0; i < words.length; i++) {
            for (char c : words[i].toCharArray()) {
                morse.append(MORSE_MAP.getOrDefault(c, "")).append(" ");
            }
            if (i < words.length - 1) {
                morse.append("| ");
            }
        }
        return morse.toString().trim();
    }
    public static String morseToText(String morse) {
        StringBuilder text = new StringBuilder();
        String[] words = morse.split(" \\| ");
        for (int i = 0; i < words.length; i++) {
            for (String code : words[i].split(" ")) {
                text.append(REVERSE_MAP.getOrDefault(code, '?'));
            }
            if (i < words.length - 1) {
                text.append(" ");
            }
        }
        return text.toString();
    }
}
