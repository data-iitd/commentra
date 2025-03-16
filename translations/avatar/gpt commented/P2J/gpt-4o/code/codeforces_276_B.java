import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input and convert it to a character array
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        char[] s = input.toCharArray();

        // Initialize a flag variable and a map to count occurrences of each character
        boolean x = true;
        Map<Character, Integer> dt = new HashMap<>();

        // Count the occurrences of each character in the input array
        for (char i : s) {
            dt.put(i, dt.getOrDefault(i, 0) + 1); // Increment the count
        }

        // Initialize a counter for odd occurrences
        int cnt = 0;

        // Check the counts of each character to determine the number of odd occurrences
        for (int value : dt.values()) {
            if (value % 2 != 0) {
                if (cnt < 1) {
                    cnt++; // Count the first odd occurrence
                } else {
                    x = false; // More than one odd occurrence found, set flag to false
                    break;
                }
            }
        }

        // Determine the output based on the number of odd occurrences and the length of the input
        if (x) {
            System.out.println("First"); // If there are no more than one odd occurrences, print "First"
        } else if (!x && s.length % 2 == 0) {
            System.out.println("Second"); // If there are more than one odd occurrences and the length is even, print "Second"
        } else if (!x && s.length % 2 != 0) {
            System.out.println("First"); // If there are more than one odd occurrences and the length is odd, print "First"
        }

        scanner.close();
    }
}
// <END-OF-CODE>
