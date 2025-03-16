
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Read the first integer 'n' from the console
        int n = scanner.nextInt();
        // Comment explaining the variable 'n'

        // Read the second integer 'k' from the console
        int k = scanner.nextInt();
        // Comment explaining the variable 'k'

        // Initialize an empty HashMap named 'map' to store the list of days for each person
        Map<Integer, List<Integer>> map = new HashMap<>();

        // Loop through 'k' number of test cases
        for (int i = 0; i < k; i++) {
            // Read the number of days 'd' for the current test case
            int d = scanner.nextInt();
            // Comment explaining the variable 'd'

            // Loop through 'd' number of days for the current test case
            for (int j = 0; j < d; j++) {
                // Read the person's ID 'person' for the current day
                int person = scanner.nextInt();
                // Comment explaining the variable 'person'

                // If the person is not already present in the map, add a new key-value pair for that person with an empty ArrayList as its value
                if (!map.containsKey(person)) {
                    map.put(person, new ArrayList<>());
                }
                // Comment explaining the if condition and the map.put() statement

                // Add the day number 'd' to the list of days for the person
                map.get(person).add(d);
                // Comment explaining the map.get() statement and the add() statement
            }
        }

        // Initialize a counter 'count' to keep track of the number of people who don't have any days recorded in the map
        int count = 0;

        // Loop through all the numbers from 1 to 'n'
        for (int i = 1; i <= n; i++) {
            // If the person is not present in the map, increment the counter
            if (!map.containsKey(i)) {
                count++;
                // Comment explaining the if condition and the increment statement
            }
        }

        // Print the final count to the console
        System.out.println(count);
        // Comment explaining the System.out.println() statement

    }
}