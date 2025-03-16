import java.util.Scanner; // Importing Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object
        String S = sc.nextLine(); // Read input string S
        String T = sc.nextLine(); // Read input string T
        sc.close(); // Close the Scanner

        String[] A = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}; // Array of all lowercase letters

        boolean res = true; // Initialize result as true

        // Loop through each letter in the alphabet
        for (String s : A) {
            int sIdx = S.indexOf(s); // Find the index of the current letter in S
            if (sIdx < 0) continue; // If the letter is not in S, continue to the next letter

            String t = String.valueOf(T.charAt(sIdx)); // Find the corresponding letter in T

            int idx = 0; // Initialize index for comparison
            while (idx < S.length()) {
                if (S.indexOf(s, idx) >= 0) { // If the letter appears in S from the current index
                    if (S.indexOf(s, idx) != T.indexOf(t, idx)) { // Check if the positions match
                        res = false; // If positions do not match, set res to false
                        break; // Break out of the loop
                    } else {
                        idx = S.indexOf(s, idx) + 1; // Update index to check the next position
                    }
                } else if (T.indexOf(t, idx) >= 0) { // If the letter appears in T from the current index
                    res = false; // If positions do not match, set res to false
                    break; // Break out of the loop
                } else {
                    break; // If neither letter appears, break out of the loop
                }
            }
            if (!res) break; // If res is false, break out of the outer loop
        }

        if (res) {
            System.out.println("Yes"); // If res is true, print "Yes"
        } else {
            System.out.println("No"); // If res is false, print "No"
        }
    }
}
