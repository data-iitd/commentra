
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Initialize Scanner to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read the number of people (n) and the number of pairs of disliked people (k)
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Create a map to store the dislike relationships
        // Key: person, Value: list of people they dislike
        Map<Integer, List<Integer>> map = new HashMap<>();

        // Read each pair of disliked people
        for (int i = 0; i < k; i++) {
            // Read the number of people in the current pair
            int d = scanner.nextInt();
            // Read each person in the current pair
            for (int j = 0; j < d; j++) {
                int person = scanner.nextInt();

                // Ensure each person has an entry in the map
                if (!map.containsKey(person)) {
                    map.put(person, new ArrayList<>());
                }
                // Add the current pair's number to the person's list of disliked people
                map.get(person).add(d);
            }
        }

        // Count the number of people who have no dislikes
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (!map.containsKey(i)) {
                count++;
            }
        }

        // Print the count of people who have no dislikes
        System.out.println(count);

    }
}