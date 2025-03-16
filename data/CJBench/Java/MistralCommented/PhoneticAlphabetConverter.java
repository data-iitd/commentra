
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public final class Main {
    private Main() {}

    // Initialize a HashMap named PHONETIC_MAP to store the mapping between characters and their phonetic alphabet representations
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

        // Main method entry point
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read user input
            while (true) { // Infinite loop to keep the program running until the user enters "exit"
                String input = scanner.nextLine().trim(); // Read a line of user input and trim any leading/trailing whitespaces
                if (input.equalsIgnoreCase("exit")) { // Check if the user entered "exit" to exit the program
                    System.out.println("Exiting..."); // Print a message to indicate that the program is exiting
                    break; // Exit the loop and close the Scanner object
                }
                if (input.isEmpty()) { // Check if the user entered an empty line
                    System.out.println("Invalid Input: Input cannot be blank"); // Print an error message if the input is empty
                    continue; // Continue to the next iteration of the loop
                }
                String result = textToPhonetic(input); // Call the textToPhonetic method to convert the user input to its phonetic alphabet representation
                System.out.println("Phonetic Alphabet: " + result); // Print the phonetic alphabet representation of the user input
            }
            scanner.close(); // Close the Scanner object to free up system resources
        }

        // Method to convert a given text string to its phonetic alphabet representation
        public static String textToPhonetic(String text) {
            StringBuilder phonetic = new StringBuilder(); // Initialize a StringBuilder object to store the phonetic alphabet representation
            for (char c : text.toUpperCase().toCharArray()) { // Iterate through each character in the user input string
                if (Character.isWhitespace(c)) { // Check if the character is a whitespace character
                    continue; // Skip the character if it is a whitespace character
                }
                phonetic.append(PHONETIC_MAP.getOrDefault(c, String.valueOf(c))).append(" "); // Append the phonetic alphabet representation of the character or its actual character representation followed by a space
            }
            return phonetic.toString().trim(); // Return the final phonetic alphabet representation of the user input string
        }
    }

