import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    static Set<String> ODD = new HashSet<>(); // Initialize an empty HashSet named ODD
    static Set<String> EVE = new HashSet<>(); // Initialize an empty HashSet named EVE

    static { // Initialize the HashSets ODD and EVE with their respective elements
        ODD.add("R");
        ODD.add("U");
        ODD.add("D");
        EVE.add("L");
        EVE.add("U");
        EVE.add("D");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input from the console
        String N = sc.nextLine(); // Read a line of input from the console and store it in the variable N
        char[] tap = N.toCharArray(); // Convert the String N to a character array named tap

        boolean isGood = true; // Initialize a boolean variable named isGood to true

        for (int i = 0; i < N.length(); i++) { // Iterate through each character in the character array tap
            if ((i + 1) % 2 == 0) { // Check if the index i is even
                if (!isMatch(EVE, tap[i])) { // Check if the character at index i does not match any element in the HashSet EVE
                    isGood = false; // Set isGood to false if a mismatch is found
                    break; // Exit the loop if a mismatch is found
                }
            } else { // The index i is odd
                if (!isMatch(ODD, tap[i])) { // Check if the character at index i does not match any element in the HashSet ODD
                    isGood = false; // Set isGood to false if a mismatch is found
                    break; // Exit the loop if a mismatch is found
                }
            }
        }

        System.out.println(isGood ? "Yes" : "No"); // Print "Yes" if isGood is true, otherwise print "No"
    }

    private static boolean isMatch(Set<String> set, char c) { // A method to check if a character matches any element in a HashSet
        return set.contains(String.valueOf(c)); // Return true if the character c is present in the HashSet set, otherwise return false
    }
}
