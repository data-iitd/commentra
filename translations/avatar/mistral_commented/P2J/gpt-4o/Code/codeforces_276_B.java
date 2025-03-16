import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the input as a string
        String input = scanner.nextLine();
        
        // Initialize a HashMap to store the count of each unique element
        Map<Character, Integer> dt = new HashMap<>();
        
        // Iterate through each character in the input string
        for (char i : input.toCharArray()) {
            // Check if the character already exists as a key in the HashMap
            dt.put(i, dt.getOrDefault(i, 0) + 1);
        }
        
        // Initialize a counter 'cnt' to 0 and a boolean variable 'x' to true
        int cnt = 0;
        boolean x = true;
        
        // Iterate through each key-value pair in the HashMap
        for (Map.Entry<Character, Integer> entry : dt.entrySet()) {
            int value = entry.getValue();
            // If the value is odd and 'cnt' is less than 1, increment 'cnt' by 1
            if (value % 2 != 0 && cnt < 1) {
                cnt++;
            } 
            // If the value is odd and 'cnt' is already greater than or equal to 1, set 'x' to false and break the loop
            else if (value % 2 != 0 && cnt >= 1) {
                x = false;
                break;
            }
        }
        
        // After the loop, check the value of 'x'
        if (x) {
            // If it is true, print "First"
            System.out.println("First");
        } else if (!x && input.length() % 2 == 0) {
            // If it is false and the length of the input string is even, print "Second"
            System.out.println("Second");
        } else if (!x && input.length() % 2 != 0) {
            // If it is false and the length of the input string is odd, print "First"
            System.out.println("First");
        }
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
