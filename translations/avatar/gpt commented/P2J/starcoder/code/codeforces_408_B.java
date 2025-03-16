import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the first line of input which represents the colors bought
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        // Count the occurrences of each color bought using HashMap
        HashMap<Character, Integer> bought_count = new HashMap<Character, Integer>();
        for (char c : line.toCharArray()) {
            bought_count.put(c, bought_count.getOrDefault(c, 0) + 1);
        }
        
        // Read the second line of input which represents the colors made
        line = sc.nextLine();
        // Count the occurrences of each color made using HashMap
        HashMap<Character, Integer> made_count = new HashMap<Character, Integer>();
        for (char c : line.toCharArray()) {
            made_count.put(c, made_count.getOrDefault(c, 0) + 1);
        }
        
        // Initialize the result variable to store the total count of matched colors
        int res = 0;
        
        // Iterate through each color in the made_count
        for (char color : made_count.keySet()) {
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

