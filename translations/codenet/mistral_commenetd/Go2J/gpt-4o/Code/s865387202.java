// Import necessary packages
import java.util.*;

// Define a custom City class with three fields: prefecture, position, and year.
class City {
    int prefecture;
    int position;
    int year;

    // Constructor for the City class
    public City(int prefecture, int year, int position) {
        this.prefecture = prefecture;
        this.year = year;
        this.position = position;
    }
}

// Main class containing the entry point of the program
public class Main {
    public static void main(String[] args) {
        // Read the number of cities and events from the standard input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Initialize a map to hold cities grouped by prefecture
        Map<Integer, List<City>> h = new HashMap<>();

        // Read m pairs of integers x and y from the standard input
        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            scanner.nextLine(); // Consume the newline

            // Check if the prefecture x already exists in the map
            h.putIfAbsent(x, new ArrayList<>());
            // Append a new City object to the existing list for prefecture x
            h.get(x).add(new City(x, y, i));
        }

        // Initialize a results list with length m
        String[] results = new String[m];

        // Iterate through each list of cities in the map
        for (List<City> cities : h.values()) {
            // Sort the cities list using a custom comparator
            cities.sort(Comparator.comparingInt(c -> c.year));

            // Iterate through each city in the sorted list
            for (int idx = 0; idx < cities.size(); idx++) {
                City ci = cities.get(idx);
                // Format the result string and assign it to the corresponding index in the results array
                results[ci.position] = String.format("%06d%06d", ci.prefecture, idx + 1);
            }
        }

        // Print the final result
        System.out.println(String.join("\n", results));
    }
}
// <END-OF-CODE>
