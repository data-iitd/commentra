import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ColorMatcher {

    public static void solution() {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first line of input which represents the colors bought
        String boughtLine = scanner.nextLine();
        // Count the occurrences of each color bought using HashMap
        Map<Character, Integer> boughtCount = new HashMap<>();
        for (char color : boughtLine.toCharArray()) {
            boughtCount.put(color, boughtCount.getOrDefault(color, 0) + 1);
        }
        
        // Read the second line of input which represents the colors made
        String madeLine = scanner.nextLine();
        // Count the occurrences of each color made using HashMap
        Map<Character, Integer> madeCount = new HashMap<>();
        for (char color : madeLine.toCharArray()) {
            madeCount.put(color, madeCount.getOrDefault(color, 0) + 1);
        }
        
        // Initialize the result variable to store the total count of matched colors
        int res = 0;
        
        // Iterate through each color in the madeCount
        for (char color : madeCount.keySet()) {
            // If a color made is not found in the bought colors, return -1
            if (!boughtCount.containsKey(color)) {
                System.out.println(-1);
                return;
            }
            // Add the minimum of the bought and made counts for each color to the result
            res += Math.min(boughtCount.get(color), madeCount.get(color));
        }
        
        // Print the total count of matched colors
        System.out.println(res);
    }

    public static void main(String[] args) {
        // Set the number of test cases (currently set to 1)
        int t = 1;
        // Loop through each test case
        for (int i = 0; i < t; i++) {
            solution();
        }
    }
}

// <END-OF-CODE>
