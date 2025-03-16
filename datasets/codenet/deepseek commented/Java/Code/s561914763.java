
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    // Set to store characters allowed at odd positions
    static Set<String> ODD = new HashSet<>();
    // Set to store characters allowed at even positions
    static Set<String> EVE = new HashSet<>();

    // Static block to initialize the sets with allowed characters
    static {
        ODD.add("R");
        ODD.add("U");
        ODD.add("D");
        EVE.add("L");
        EVE.add("U");
        EVE.add("D");
    }

    // Main method is the entry point of the program
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        // Read the input string
        String N = sc.nextLine();
        // Convert the input string to a character array for easy manipulation
        char[] tap = N.toCharArray();

        // Variable to track if the input string matches the expected pattern
        boolean isGood = true;
        // Loop through each character in the input string
        for (int i = 0; i < N.length(); i++) {
            // Check if the position is even
            if ((i + 1) % 2 == 0) {
                // Check if the character at this position matches the allowed characters for even positions
                if (!isMatch(EVE, tap[i])) {
                    isGood = false;
                    break;
                }
            } else {
                // Check if the character at this position matches the allowed characters for odd positions
                if (!isMatch(ODD, tap[i])) {
                    isGood = false;
                    break;
                }
            }
        }

        // Print the result based on whether the input string matched the expected pattern
        System.out.println(isGood ? "Yes" : "No");
    }

    // Method to check if a character is in a set
    private static boolean isMatch(Set<String> set, char c) {
        return set.contains(String.valueOf(c));
    }
}

