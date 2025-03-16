
// Package main contains the entry point of the program.
package main;

// Import the 'Scanner' class for input/output operations.
import java.util.Scanner;

// Define a custom city class with three fields: prefecture, position, and year.
class City {
    int prefecture;
    int position;
    int year;

    public City(int prefecture, int position, int year) {
        this.prefecture = prefecture;
        this.position = position;
        this.year = year;
    }
}

// Define a custom cities class as a list of city objects.
class Cities {
    List<City> cities;

    public Cities() {
        this.cities = new ArrayList<>();
    }

    public void add(City city) {
        this.cities.add(city);
    }

    public int size() {
        return this.cities.size();
    }

    public City get(int index) {
        return this.cities.get(index);
    }
}

// Define a custom cMap class as a map with an integer key and a cities object as the value.
class CMap {
    Map<Integer, Cities> cMap;

    public CMap() {
        this.cMap = new HashMap<>();
    }

    public void put(int key, Cities value) {
        this.cMap.put(key, value);
    }

    public Cities get(int key) {
        return this.cMap.get(key);
    }
}

// Main function is the entry point of the program.
public class Main {
    public static void main(String[] args) {
        // Read the number of cities and events from the standard input.
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize an empty cMap named h.
        CMap h = new CMap();

        // Read m pairs of integers x and y from the standard input.
        for (int i = 0; i < m; i++) {
            // Read an integer x from the standard input.
            int x = scanner.nextInt();

            // Read an integer y from the standard input.
            int y = scanner.nextInt();

            // Check if the prefecture x already exists in the cMap.
            if (!h.cMap.containsKey(x)) {
                // If the prefecture x does not exist in the cMap, create a new cities object with one element and assign it to the key x in the cMap.
                Cities cities = new Cities();
                cities.add(new City(x, i, y));
                h.put(x, cities);
            } else {
                // If the prefecture x already exists in the cMap, append a new city object to the existing cities object.
                Cities cities = h.get(x);
                cities.add(new City(x, i, y));
                h.put(x, cities);
            }
        }

        // Initialize a list named results with length m and zeroed elements.
        List<String> results = new ArrayList<>();

        // Iterate through each value v in the cMap.
        for (int i = 0; i < m; i++) {
            // Sort the cities object v using the Less method.
            Cities cities = h.get(i);
            Collections.sort(cities.cities, new Comparator<City>() {
                @Override
                public int compare(City o1, City o2) {
                    return o1.year - o2.year;
                }
            });

            // Iterate through each city object ci in the sorted cities object v.
            for (int j = 0; j < cities.size(); j++) {
                // Format the result string using String.format and assign it to the corresponding index in the results list.
                results.set(cities.get(j).position, String.format("%06d%06d", cities.get(j).prefecture, j + 1));
            }
        }

        // Print the final result using String.join and System.out.println.
        System.out.println(String.join("\n", results));
    }
}

// End of code 