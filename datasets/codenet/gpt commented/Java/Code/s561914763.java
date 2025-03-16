import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    // Define sets for odd and even indexed characters
    static Set<String> ODD = new HashSet<>();
    static Set<String> EVE = new HashSet<>();
    
    // Static block to initialize the sets with allowed characters
    static {
        ODD.add("R"); // Add 'R' to the ODD set
        ODD.add("U"); // Add 'U' to the ODD set
        ODD.add("D"); // Add 'D' to the ODD set
        EVE.add("L"); // Add 'L' to the EVE set
        EVE.add("U"); // Add 'U' to the EVE set
        EVE.add("D"); // Add 'D' to the EVE set
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the input string
        String N = sc.nextLine();
        char[] tap = N.toCharArray(); // Convert the input string to a character array

        boolean isGood = true; // Initialize a flag to track if the input is valid
        
        // Iterate through each character in the input string
        for (int i = 0; i < N.length(); i++) {
            // Check if the index is even
            if ((i + 1) % 2 == 0) {
                // Validate against the EVE set for even indexed characters
                if (!isMatch(EVE, tap[i])) {
                    isGood = false; // Set flag to false if there's a mismatch
                    break; // Exit the loop early
                }
            } else {
                // Validate against the ODD set for odd indexed characters
                if (!isMatch(ODD, tap[i])) {
                    isGood = false; // Set flag to false if there's a mismatch
                    break; // Exit the loop early
                }
            }
        }

        // Output the result based on the validity of the input
        System.out.println(isGood ? "Yes" : "No");
    }

    // Helper method to check if a character is in the specified set
    private static boolean isMatch(Set<String> set, char c) {
        return set.contains(String.valueOf(c)); // Check if the character exists in the set
    }
}
