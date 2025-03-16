import java.util.*;

class City {
    int prefecture; // Represents the prefecture number of the city
    int position;   // Represents the position of the city in its prefecture
    int year;       // Represents the year the city was established

    public City(int prefecture, int year, int position) {
        this.prefecture = prefecture;
        this.year = year;
        this.position = position;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Number of prefectures
        int m = scanner.nextInt(); // Number of cities
        scanner.nextLine(); // Consume the newline

        Map<Integer, List<City>> cityMap = new HashMap<>(); // Map from prefecture numbers to lists of cities

        // Loop to read city entries
        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt(); // Prefecture number
            int y = scanner.nextInt(); // Year
            scanner.nextLine(); // Consume the newline

            cityMap.putIfAbsent(x, new ArrayList<>()); // Create a new entry if prefecture doesn't exist
            cityMap.get(x).add(new City(x, y, i)); // Add the city to the list
        }

        List<String> results = new ArrayList<>(Collections.nCopies(m, "")); // Initialize a list to hold the formatted city strings

        // Loop to sort and format cities
        for (List<City> cities : cityMap.values()) {
            Collections.sort(cities, Comparator.comparingInt(c -> c.year)); // Sort cities by establishment year
            for (int idx = 0; idx < cities.size(); idx++) {
                City ci = cities.get(idx);
                results.set(ci.position, String.format("%06d%06d", ci.prefecture, idx + 1)); // Format the city string
            }
        }

        System.out.println(String.join("\n", results)); // Join the formatted city strings and print them
    }
}
// <END-OF-CODE>
