import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CharacterFrequency {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();  // Read the input string
        char[] s = input.toCharArray();  // Convert the input string into a character array
        boolean x = true;  // Initialize a boolean variable to track the result
        Map<Character, Integer> dt = new HashMap<>();  // Initialize an empty dictionary to store character frequencies

        // Iterate over each character in the input string and update the frequency count in the dictionary
        for (char i : s) {
            dt.put(i, dt.getOrDefault(i, 0) + 1);
        }

        int cnt = 0;  // Initialize a counter to keep track of characters with an odd frequency
        x = true;  // Reset the boolean variable to track the result

        // Iterate over the entries in the dictionary to determine if there is more than one character with an odd frequency
        for (Map.Entry<Character, Integer> entry : dt.entrySet()) {
            if (entry.getValue() % 2 != 0 && cnt < 1) {
                cnt++;
            } else if (entry.getValue() % 2 != 0 && cnt >= 1) {
                x = false;
                break;
            }
        }

        // Determine the output based on the value of cnt and the length of the input string
        if (x) {
            System.out.println("First");  // Print "First" if there is at most one character with an odd frequency
        } else if (!x && s.length % 2 == 0) {
            System.out.println("Second");  // Print "Second" if there is more than one character with an odd frequency and the length of the input string is even
        } else if (!x && s.length % 2 != 0) {
            System.out.println("First");  // Print "First" if there is more than one character with an odd frequency and the length of the input string is odd
        }

        scanner.close();  // Close the scanner
    }
}
// <END-OF-CODE>
