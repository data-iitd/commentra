
import java.util.Scanner; // Import the Scanner class for reading input from the command line

public class Main {
    public static void main(String[] args) { // The main function is the entry point of the program
        Scanner sc = new Scanner(System.in); // Create a new Scanner object for reading input from the command line
        String s = sc.nextLine(); // Read a string from the standard input and store it in the 's' variable

        for (int j = 0; j < s.length(); j++) { // Iterate through each character in the string 's' using index 'j'
            for (int i = 0; i < s.length(); i++) { // Nested loop to compare each character with all other characters in the string
                if ((i != j) && (s.charAt(i) == s.charAt(j))) { // Check if the current characters at indices 'i' and 'j' are the same and not the same index
                    System.out.println("no"); // If duplicate characters are found, print 'no' and exit the program
                    return;
                }
            }
        }

        System.out.println("yes"); // If no duplicate characters are found, print 'yes'
    }
}

