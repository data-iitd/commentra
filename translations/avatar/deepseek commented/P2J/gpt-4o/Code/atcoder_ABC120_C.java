import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input string from the user
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        // Check if all characters in the string are the same
        if (s.chars().distinct().count() == 1) {
            System.out.println(0);
            return;
        }
        
        // Count the frequency of each character in the string
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }
        
        // Calculate the answer as twice the minimum frequency of any character
        int minFrequency = Integer.MAX_VALUE;
        for (int freq : frequencyMap.values()) {
            if (freq < minFrequency) {
                minFrequency = freq;
            }
        }
        
        int ans = minFrequency * 2;
        
        // Print the answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
