import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Take input string from the user
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        
        // Create a map to count the frequency of each character in the string
        Map<Character, Integer> charCount = new HashMap<>();
        
        // Count occurrences of each character
        for (char c : S.toCharArray()) {
            charCount.put(c, charCount.getOrDefault(c, 0) + 1);
        }
        
        // Create a set of unique characters from the input string
        HashSet<Character> uniqueChars = new HashSet<>(charCount.keySet());
        
        // Check if the number of unique characters is not equal to 2
        if (uniqueChars.size() != 2) {
            // If there are not exactly 2 unique characters, print "No" and exit
            System.out.println("No");
            return;
        }
        
        // Iterate over each unique character in the set
        for (char i : uniqueChars) {
            // Check if the count of the current character is not equal to 2
            if (charCount.get(i) != 2) {
                // If any character does not appear exactly twice, print "No" and exit
                System.out.println("No");
                return;
            }
        }
        
        // If both conditions are satisfied, print "Yes"
        System.out.println("Yes");
    }
}

// <END-OF-CODE>
