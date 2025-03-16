import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the list
        int n = Integer.parseInt(scanner.nextLine());

        // Read the list of integers and count the occurrences of each integer
        Map<Integer, Integer> w = new HashMap<>();
        String[] input = scanner.nextLine().split(" ");
        for (String s : input) {
            int num = Integer.parseInt(s);
            w.put(num, w.getOrDefault(num, 0) + 1);
        }

        // Initialize a variable to store the count of pairs
        int c = 0;

        // Iterate over each integer in the Map
        for (int i : w.keySet()) {
            // If the integer is 0, calculate the number of ways to choose 2 items from the occurrences of 0
            if (i == 0) {
                c += w.get(i) * (w.get(i) - 1);
            }
            // If the integer is not 0, check if its negative counterpart is also in the Map
            else {
                if (w.containsKey(-i)) {
                    // Calculate the number of ways to choose 2 items from the occurrences of i and -i
                    c += w.get(i) * w.get(-i);
                }
            }
        }

        // Print the result of c / 2, which represents the number of unique pairs
        System.out.println(c / 2);
    }
}
