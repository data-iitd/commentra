
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of test cases
        int t = sc.nextInt();

        // Run the solution function for each test case
        for (int i = 0; i < t; i++) {
            solution();
        }
    }

    // Define helper functions
    public static void hpop(PriorityQueue<Integer> heap) {
        heap.poll();
    }

    public static void hpush(PriorityQueue<Integer> heap, int item) {
        heap.add(item);
    }

    // Function to find the solution
    public static void solution() {
        // Read the first line and count the number of occurrences of each color
        String line = sc.next();
        Map<Character, Integer> bought_count = new HashMap<>();
        for (char c : line.toCharArray()) {
            bought_count.put(c, bought_count.getOrDefault(c, 0) + 1);
        }

        // Read the second line and count the number of occurrences of each color
        line = sc.next();
        Map<Character, Integer> made_cout = new HashMap<>();
        for (char c : line.toCharArray()) {
            made_cout.put(c, made_cout.getOrDefault(c, 0) + 1);
        }

        // Initialize result to 0
        int res = 0;

        // Iterate through each color in made_cout
        for (char color : made_cout.keySet()) {
            // Check if the color is present in bought_count
            if (!bought_count.containsKey(color)) {
                // If not, print -1 and exit the function
                System.out.println(-1);
                return;
            }

            // Update the result by adding the minimum of bought and made counts
            res += Math.min(bought_count.get(color), made_cout.get(color));
        }

        // Print the result
        System.out.println(res);
    }
}

