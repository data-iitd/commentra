
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.Iterator;

public class Solution {
    public static void main(String[] args) {
        // Read the first line of input which represents the colors bought
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        // Count the occurrences of each color bought using HashMap
        Map<Character, Integer> bought_count = new HashMap<Character, Integer>();
        for (int i = 0; i < line.length(); i++) {
            char color = line.charAt(i);
            if (bought_count.containsKey(color)) {
                bought_count.put(color, bought_count.get(color) + 1);
            } else {
                bought_count.put(color, 1);
            }
        }
        
        // Read the second line of input which represents the colors made
        line = scanner.nextLine();
        // Count the occurrences of each color made using HashMap
        Map<Character, Integer> made_count = new HashMap<Character, Integer>();
        for (int i = 0; i < line.length(); i++) {
            char color = line.charAt(i);
            if (made_count.containsKey(color)) {
                made_count.put(color, made_count.get(color) + 1);
            } else {
                made_count.put(color, 1);
            }
        }
        
        // Initialize the result variable to store the total count of matched colors
        int res = 0;
        
        // Iterate through each color in the made_count
        Set<Character> keys = made_count.keySet();
        Iterator<Character> it = keys.iterator();
        while (it.hasNext()) {
            char color = it.next();
            // If a color made is not found in the bought colors, return -1
            if (!bought_count.containsKey(color)) {
                System.out.println(-1);
                return;
            }
            // Add the minimum of the bought and made counts for each color to the result
            res += Math.min(bought_count.get(color), made_count.get(color));
        }
        
        // Print the total count of matched colors
        System.out.println(res);
    }
}

