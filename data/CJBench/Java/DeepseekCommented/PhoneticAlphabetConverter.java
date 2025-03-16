import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public final class Main {
    private Main() {} // Private constructor to prevent instantiation

    // Static block to initialize the PHONETIC_MAP with character mappings
    private static final Map<Character, String> PHONETIC_MAP = new HashMap<>();
    static {
        PHONETIC_MAP.put('A', "Alpha");
        PHONETIC_MAP.put('B', "Bravo");
        PHONETIC_MAP.put('C', "Charlie");
        PHONETIC_MAP.put('D', "Delta");
        PHONETIC_MAP.put('E', "Echo");
        PHONETIC_MAP.put('F', "Foxtrot");
        PHONETIC_MAP.put('G', "Golf");
        PHONETIC_MAP.put('H', "Hotel");
        PHONETIC_MAP.put('I', "India");
        PHONETIC_MAP.put('J', "Juliett");
        PHONETIC_MAP.put('K', "Kilo");
        PHONETIC_MAP.put('L', "Lima");
        PHONETIC_MAP.put('M', "Mike");
        PHONETIC_MAP.put('N', "November");
        PHONETIC_MAP.put('O', "Oscar");
        PHONETIC_MAP.put('P', "Papa");
        PHONETIC_MAP.put('Q', "Quebec");
        PHONETIC_MAP.put('R', "Romeo");
        PHONETIC_MAP.put('S', "Sierra");
        PHONETIC_MAP.put('T', "Tango");
        PHONETIC_MAP.put('U', "Uniform");
        PHONETIC_MAP.put('V', "Victor");
        PHONETIC_MAP.put('W', "Whiskey");
        PHONETIC_MAP.put('X', "X-ray");
        PHONETIC_MAP.put('Y', "Yankee");
        PHONETIC_MAP.put('Z', "Zulu");
        PHONETIC_MAP.put('0', "Zero");
        PHONETIC_MAP.put('1', "One");
        PHONETIC_MAP.put('2', "Two");
        PHONETIC_MAP.put('3', "Three");
        PHONETIC_MAP.put('4', "Four");
        PHONETIC_MAP.put('5', "Five");
        PHONETIC_MAP.put('6', "Six");
        PHONETIC_MAP.put('7', "Seven");
        PHONETIC_MAP.put('8', "Eight");
        PHONETIC_MAP.put('9', "Nine");
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            String input = scanner.nextLine().trim(); // Read input and trim whitespace
            if (input.equalsIgnoreCase("exit")) { // Check if the user wants to exit
                System.out.println("Exiting...");
                break;
            }
            if (input.isEmpty()) { // Check if the input is blank
                System.out.println("Invalid Input: Input cannot be blank");
                continue;
            }
            String result = textToPhonetic(input); // Convert input to phonetic alphabet
            System.out.println("Phonetic Alphabet: " + result); // Print the result
        }
        scanner.close(); // Close the scanner
    }

    // Method to convert text to phonetic alphabet
    public static String textToPhonetic(String text) {
        StringBuilder phonetic = new StringBuilder();
        for (char c : text.toUpperCase().toCharArray()) { // Convert text to uppercase and iterate over characters
            if (Character.isWhitespace(c)) { // Skip whitespace characters
                continue;
            }
            phonetic.append(PHONETIC_MAP.getOrDefault(c, String.valueOf(c))).append(" "); // Append phonetic equivalent or character itself with a space
        }
        return phonetic.toString().trim(); // Return the final string, trimmed of trailing spaces
    }
}
