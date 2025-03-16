import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ColorCounter {

    public static void solution() {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first line of input and create a map for the bought colors
        String boughtLine = scanner.nextLine();
        Map<Character, Integer> boughtCount = new HashMap<>();
        for (char color : boughtLine.toCharArray()) {
            boughtCount.put(color, boughtCount.getOrDefault(color, 0) + 1);
        }
        
        // Read the second line of input and create a map for the colors to be made
        String madeLine = scanner.nextLine();
        Map<Character, Integer> madeCount = new HashMap<>();
        for (char color : madeLine.toCharArray()) {
            madeCount.put(color, madeCount.getOrDefault(color, 0) + 1);
        }
        
        // Initialize the result variable to store the total number of colors that can be made
        int res = 0;
        
        // Iterate over each color in the 'madeCount' map
        for (char color : madeCount.keySet()) {
            // Check if the color is not in the 'boughtCount' map
            if (!boughtCount.containsKey(color)) {
                // If a color is not bought, print -1 and exit
                System.out.println(-1);
                return;
            }
            // Calculate the minimum of the counts of the current color in both 'boughtCount' and 'madeCount'
            // and add this to the result
            res += Math.min(boughtCount.get(color), madeCount.get(color));
        }
        
        // Print the final result
        System.out.println(res);
    }

    public static void main(String[] args) {
        // Set the number of test cases to 1
        int t = 1;
        // Run the solution function for one test case
        for (int i = 0; i < t; i++) {
            solution();
        }
    }
}

// <END-OF-CODE>
