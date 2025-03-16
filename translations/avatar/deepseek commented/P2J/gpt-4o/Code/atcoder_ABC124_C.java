import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take a string input from the user and store it in the variable `s`
        String s = scanner.nextLine();
        
        // Create a map to count occurrences of characters at even indices
        Map<Character, Integer> even = new HashMap<>();
        // Create a map to count occurrences of characters at odd indices
        Map<Character, Integer> odd = new HashMap<>();
        
        // Count occurrences of characters at even and odd indices
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (i % 2 == 0) {
                even.put(c, even.getOrDefault(c, 0) + 1);
            } else {
                odd.put(c, odd.getOrDefault(c, 0) + 1);
            }
        }
        
        // Calculate the number of flips needed for both scenarios
        int flipsToZeroEven = s.length() - (even.getOrDefault('0', 0) + odd.getOrDefault('1', 0));
        int flipsToOneEven = s.length() - (even.getOrDefault('1', 0) + odd.getOrDefault('0', 0));
        
        // Print the minimum of the two outcomes
        System.out.println(Math.min(flipsToZeroEven, flipsToOneEven));
        
        scanner.close();
    }
}

// <END-OF-CODE>
