import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {}

    // A map to hold the phonetic representations of characters and digits
    private static final Map<Character, String> PHONETIC_MAP = new HashMap<>();
    
    // Static block to initialize the PHONETIC_MAP with character mappings
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

    public static void main(String[] args) {
        // Create a scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Loop to continuously accept user input until "exit" is entered
        while (true) {
            String input = scanner.nextLine().trim();
            
            // Check if the user wants to exit the program
            if (input.equalsIgnoreCase("exit")) {
                System.out.println("Exiting...");
                break;
            }
            
            // Check for empty input and prompt the user
            if (input.isEmpty()) {
                System.out.println("Invalid Input: Input cannot be blank");
                continue;
            }
            
            // Convert the input text to its phonetic representation
            String result = textToPhonetic(input);
            // Output the phonetic representation
            System.out.println("Phonetic Alphabet: " + result);
        }
        
        // Close the scanner to free resources
        scanner.close();
    }

    // Method to convert text to its phonetic representation
    public static String textToPhonetic(String text) {
        StringBuilder phonetic = new StringBuilder();
        
        // Iterate over each character in the input text
        for (char c : text.toUpperCase().toCharArray()) {
            // Skip whitespace characters
            if (Character.isWhitespace(c)) {
                continue;
            }
            // Append the phonetic representation of the character or the character itself if not found
            phonetic.append(PHONETIC_MAP.getOrDefault(c, String.valueOf(c))).append(" ");
        }
        
        // Return the phonetic string, trimmed of any trailing spaces
        return phonetic.toString().trim();
    }
}
