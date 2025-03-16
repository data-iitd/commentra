import java.util.*;

class City {
    int prefecture; // Prefecture number
    int position;   // Position in the input
    int year;       // Year associated with the city

    public City(int prefecture, int year, int position) {
        this.prefecture = prefecture;
        this.year = year;
        this.position = position;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // number of prefectures
        int m = scanner.nextInt(); // number of cities
        scanner.nextLine(); // consume the remaining newline
        
        // Initialize a map to hold cities grouped by their prefecture
        Map<Integer, List<City>> cityMap = new HashMap<>();
        
        // Read city data from input
        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt(); // prefecture number
            int y = scanner.nextInt(); // year
            scanner.nextLine(); // consume the remaining newline
            
            // Check if the prefecture already exists in the map
            cityMap.putIfAbsent(x, new ArrayList<>());
            // Add the new city to the existing list
            cityMap.get(x).add(new City(x, y, i));
        }

        // Prepare a results list to hold formatted output for each city
        String[] results = new String[m];

        // Iterate over each group of cities in the map
        for (List<City> cities : cityMap.values()) {
            // Sort the cities by year
            cities.sort(Comparator.comparingInt(c -> c.year));
            // Format the output for each city based on its position and year
            for (int idx = 0; idx < cities.size(); idx++) {
                City ci = cities.get(idx);
                results[ci.position] = String.format("%06d%06d", ci.prefecture, idx + 1);
            }
        }
        
        // Print the results, joining them with newline characters
        System.out.println(String.join("\n", results));
    }
}
// <END-OF-CODE>
