import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int n = s.length();
        
        // Create two maps to count the frequency of '0' and '1' in the first and second half of the string 's' respectively
        Map<Character, Integer> even = new HashMap<>();
        Map<Character, Integer> odd = new HashMap<>();
        
        // Count the frequency of '0' and '1' in the first half (even indices)
        for (int i = 0; i < n / 2; i++) {
            char c = s.charAt(i);
            even.put(c, even.getOrDefault(c, 0) + 1);
        }
        
        // Count the frequency of '0' and '1' in the second half (odd indices)
        for (int i = n / 2; i < n; i++) {
            char c = s.charAt(i);
            odd.put(c, odd.getOrDefault(c, 0) + 1);
        }
        
        // Calculate the minimum difference between the length of the string 's' and the sum of the frequencies of '0' and '1' in either half of the string
        int minDiff = Math.min(n - (even.getOrDefault('0', 0) + odd.getOrDefault('1', 0)), 
                               n - (even.getOrDefault('1', 0) + odd.getOrDefault('0', 0)));
        
        // Print the minimum difference
        System.out.println(minDiff);
    }
}
