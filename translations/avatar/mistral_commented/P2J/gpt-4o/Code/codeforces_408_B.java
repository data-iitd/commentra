import java.util.*;

public class Main {
    // Function to find the solution
    public static void solution() {
        // Read the first line and count the number of occurrences of each color
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        Map<Character, Integer> boughtCount = countOccurrences(line);

        // Read the second line and count the number of occurrences of each color
        line = scanner.nextLine();
        Map<Character, Integer> madeCount = countOccurrences(line);

        // Initialize result to 0
        int res = 0;

        // Iterate through each color in madeCount
        for (char color : madeCount.keySet()) {
            // Check if the color is present in boughtCount
            if (!boughtCount.containsKey(color)) {
                // If not, print -1 and exit the function
                System.out.println(-1);
                return;
            }

            // Update the result by adding the minimum of bought and made counts
            res += Math.min(boughtCount.get(color), madeCount.get(color));
        }

        // Print the result
        System.out.println(res);
    }

    // Helper function to count occurrences of characters in a string
    private static Map<Character, Integer> countOccurrences(String line) {
        Map<Character, Integer> countMap = new HashMap<>();
        for (char c : line.toCharArray()) {
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
        }
        return countMap;
    }

    // Main function to run the solution function for multiple test cases
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of test cases
        int t = Integer.parseInt(scanner.nextLine());

        // Run the solution function for each test case
        for (int i = 0; i < t; i++) {
            solution();
        }
    }
}

// <END-OF-CODE>
