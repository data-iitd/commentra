import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        scanner.nextLine();  // Consume newline

        for (int i = 0; i < t; i++) {
            String firstLine = scanner.nextLine();
            String secondLine = scanner.nextLine();
            solution(firstLine, secondLine);
        }
    }

    public static void solution(String firstLine, String secondLine) {
        // Count the number of occurrences of each color in the first line
        Map<Character, Integer> boughtCount = new HashMap<>();
        for (char color : firstLine.toCharArray()) {
            boughtCount.put(color, boughtCount.getOrDefault(color, 0) + 1);
        }

        // Count the number of occurrences of each color in the second line
        Map<Character, Integer> madeCount = new HashMap<>();
        for (char color : secondLine.toCharArray()) {
            madeCount.put(color, madeCount.getOrDefault(color, 0) + 1);
        }

        // Initialize result to 0
        int res = 0;

        // Iterate through each color in madeCount
        for (char color : madeCount.keySet()) {
            // Check if the color is present in boughtCount
            if (!boughtCount.containsKey(color)) {
                // If not, print -1 and return
                System.out.println(-1);
                return;
            }

            // Update the result by adding the minimum of bought and made counts
            res += Math.min(boughtCount.get(color), madeCount.get(color));
        }

        // Print the result
        System.out.println(res);
    }
}
