import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner to take input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Initialize an empty list 's' by taking input from the user
        String s = scanner.nextLine();
        
        // Create two maps 'even' and 'odd' to count the frequency of '0' and '1' in the first and second half of the string 's' respectively
        Map<Character, Integer> even = new HashMap<>();
        Map<Character, Integer> odd = new HashMap<>();
        
        // Count frequencies in the first half
        for (int i = 0; i < s.length() / 2; i++) {
            even.put(s.charAt(i), even.getOrDefault(s.charAt(i), 0) + 1);
        }
        
        // Count frequencies in the second half
        for (int i = s.length() / 2; i < s.length(); i++) {
            odd.put(s.charAt(i), odd.getOrDefault(s.charAt(i), 0) + 1);
        }
        
        // Calculate the minimum difference
        int minDifference = Math.min(s.length() - (even.getOrDefault('0', 0) + odd.getOrDefault('1', 0)),
                                      s.length() - (even.getOrDefault('1', 0) + odd.getOrDefault('0', 0)));
        
        // Print the result
        System.out.println(minDifference);
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
