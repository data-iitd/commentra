import java.util.*; // Importing the utility class Scanner from java.util package

public class Main { // Defining the main class named Main
    public static void main(String[] args){ // Defining the main method that is the entry point of the program
        
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the standard input stream
        // Read the first character from the user input
        String C = sc.next();

        // Print the character that is one ASCII value greater than the given character
        System.out.println((char)(C.charAt(0)+1));
    }
}
