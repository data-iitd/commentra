import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        // Initialize a map to count occurrences of each character
        Map<Character, Integer> dt = new HashMap<>();
        
        // Count the occurrences of each character in the input string
        for (char c : s.toCharArray()) {
            dt.put(c, dt.getOrDefault(c, 0) + 1);
        }
        
        // Initialize a counter for odd occurrences and a flag variable
        int cnt = 0;
        boolean x = true;
        
        // Check the counts of each character to determine the number of odd occurrences
        for (int value : dt.values()) {
            if (value % 2 != 0 && cnt < 1) {
                cnt++;  // Count the first odd occurrence
            } else if (value % 2 != 0 && cnt >= 1) {
                x = false;  // More than one odd occurrence found, set flag to false
                break;
            }
        }
        
        // Determine the output based on the number of odd occurrences and the length of the input
        if (x) {
            System.out.println("First");  // If there are no more than one odd occurrences, print "First"
        } else if (!x && s.length() % 2 == 0) {
            System.out.println("Second");  // If there are more than one odd occurrences and the length is even, print "Second"
        } else if (!x && s.length() % 2 != 0) {
            System.out.println("First");  // If there are more than one odd occurrences and the length is odd, print "First"
        }
    }
}
