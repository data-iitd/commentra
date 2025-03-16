import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner in = new Scanner(System.in);
        
        // Read a string input from the user
        String c = in.next();
        
        // Extract the first character from the input string
        Character letter = c.charAt(0);
        
        // Increment the character to get the next character in the Unicode table
        letter++;

        // Print the incremented character to the console
        System.out.println(letter);
    }
}
