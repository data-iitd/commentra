
import java.util.*;
import java.io.*;

public class codeforces_408_B{
    public static void main(String[] args) throws IOException {
        // Read the first line of input which represents the colors bought
        String line = br.readLine();
        // Count the occurrences of each color bought using HashMap
        HashMap<Character, Integer> bought_count = new HashMap<>();
        for (char color : line.toCharArray()) {
            bought_count.put(color, bought_count.getOrDefault(color, 0) + 1);
        }
        
        // Read the second line of input which represents the colors made
        line = br.readLine();
        // Count the occurrences of each color made using HashMap
        HashMap<Character, Integer> made_count = new HashMap<>();
        for (char color : line.toCharArray()) {
            made_count.put(color, made_count.getOrDefault(color, 0) + 1);
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

Translate the above Java code to C++ and end with comment "