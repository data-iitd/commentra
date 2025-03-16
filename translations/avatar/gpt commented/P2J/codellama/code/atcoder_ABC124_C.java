
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        sc.close();

        // Count the occurrences of '0' and '1' at even indices
        Map<Character, Integer> even = new HashMap<>();
        for (int i = 0; i < s.length(); i += 2) {
            char c = s.charAt(i);
            even.put(c, even.getOrDefault(c, 0) + 1);
        }

        // Count the occurrences of '0' and '1' at odd indices
        Map<Character, Integer> odd = new HashMap<>();
        for (int i = 1; i < s.length(); i += 2) {
            char c = s.charAt(i);
            odd.put(c, odd.getOrDefault(c, 0) + 1);
        }

        // Calculate the minimum number of changes needed to make the string alternate
        // Option 1: Change all even indexed '0's to '1's and odd indexed '1's to '0's
        // Option 2: Change all even indexed '1's to '0's and odd indexed '0's to '1's
        // Print the minimum of the two options
        int minChanges = Math.min(s.length() - (even.getOrDefault('0', 0) + odd.getOrDefault('1', 0)),
                                  s.length() - (even.getOrDefault('1', 0) + odd.getOrDefault('0', 0)));
        System.out.println(minChanges);
    }
}

