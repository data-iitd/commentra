import java.util.Scanner; // Import the Scanner class to read input from the user

public class Main {
    public static void main(String[] args) { // The entry point of the program
        Scanner in = new Scanner(System.in); // Create a new Scanner object to read input from the user
        String c = in.next(); // Read a single character from the user input and store it in the variable c
        Character letter = c.charAt(0); // Convert the character stored in c to a Character object and assign it to the variable letter
        letter++; // Increment the character stored in letter by 1

        System.out.println(letter); // Print the incremented character to the console
    }
}
