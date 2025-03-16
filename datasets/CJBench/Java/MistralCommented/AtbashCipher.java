import java.util.Scanner; // Import Scanner class for reading input from standard input

public class Main { // Main class representing the entry point of the Java application
    private String toConvert; // Instance variable to store the string to be converted

    public Main() { // Default constructor
    }

    public Main(String str) { // Constructor that initializes the instance variable with the given string
        this.toConvert = str;
    }

    public String getString() { // Getter method for the instance variable toConvert
        return toConvert;
    }

    public void setString(String str) { // Setter method for the instance variable toConvert
        this.toConvert = str;
    }

    private boolean isCapital(char ch) { // Private helper method to check if a character is capital
        return ch >= 'A' && ch <= 'Z';
    }

    private boolean isSmall(char ch) { // Private helper method to check if a character is small
        return ch >= 'a' && ch <= 'z';
    }

    public String convert() { // Public method to convert the string to its ROT-13 encryption
        StringBuilder convertedString = new StringBuilder(); // Create an empty StringBuilder object to store the converted string

        for (char ch : toConvert.toCharArray()) { // Iterate through each character in the string toConvert
            if (isSmall(ch)) { // If the character is small
                convertedString.append((char) ('z' - (ch - 'a'))); // Append the corresponding character in ROT-13 encryption scheme
            } else if (isCapital(ch)) { // If the character is capital
                convertedString.append((char) ('Z' - (ch - 'A'))); // Append the corresponding character in ROT-13 encryption scheme
            } else { // If the character is neither small nor capital
                convertedString.append(ch); // Append the character as it is
            }
        }

        return convertedString.toString(); // Return the converted string
    }

    public static void main(String[] args) { // Main method to read input from standard input, convert it, and print the result
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from standard input
        String inputText = scanner.nextLine(); // Read a line of text from standard input
        Main cipher = new Main(inputText); // Create a Main object with the input text
        String result = cipher.convert(); // Convert the input text to its ROT-13 encryption
        System.out.println("Converted Text: " + result); // Print the converted text to standard output
        scanner.close(); // Close the Scanner object
    }
}
