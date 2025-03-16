import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input

        // Prompt the user to enter a string
        System.out.print("Enter a string: ");
        String s = scanner.nextLine(); // Read the user input as a string

        // Replace all occurrences of the string "2017" in the string `s` with the string "2018".
        s = s.replace("2017", "2018");

        // Print the modified string to the standard output.
        System.out.println("Modified string: " + s);
    }
}
