import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input string
        String s = scanner.nextLine();
        
        // Count occurrences of '0' and '1' at even and odd indices
        Map<Character, Integer> even = new HashMap<>();
        Map<Character, Integer> odd = new HashMap<>();
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (i % 2 == 0) {
                even.put(ch, even.getOrDefault(ch, 0) + 1);
            } else {
                odd.put(ch, odd.getOrDefault(ch, 0) + 1);
            }
        }
        
        // Calculate the minimum number of changes needed to make the string alternate
        int option1 = s.length() - (even.getOrDefault('0', 0) + odd.getOrDefault('1', 0));
        int option2 = s.length() - (even.getOrDefault('1', 0) + odd.getOrDefault('0', 0));
        
        // Print the minimum of the two options
        System.out.println(Math.min(option1, option2));
        
        scanner.close();
    }
}
// <END-OF-CODE>
