import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Read the total number of persons (n) and the number of groups (k)
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Initialize a map to store the groups each person belongs to
        Map<Integer, List<Integer>> map = new HashMap<>();

        // Loop through each group
        for (int i = 0; i < k; i++) {
            // Read the number of persons in the current group
            int d = scanner.nextInt();
            // Loop through each person in the current group
            for (int j = 0; j < d; j++) {
                // Read the person's identifier
                int person = scanner.nextInt();

                // If the person is not already in the map, initialize their entry
                if (!map.containsKey(person)) {
                    map.put(person, new ArrayList<>());
                }
                // Add the current group size (d) to the person's list of groups
                map.get(person).add(d);
            }
        }

        // Initialize a counter for persons who are not in any group
        int count = 0;
        // Loop through all persons from 1 to n
        for (int i = 1; i <= n; i++) {
            // If the person is not in the map, increment the counter
            if (!map.containsKey(i)) {
                count++;
            }
        }

        // Output the count of persons who are not in any group
        System.out.println(count);
    }
}
