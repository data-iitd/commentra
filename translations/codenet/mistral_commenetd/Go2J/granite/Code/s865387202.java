
// Package main contains the entry point of the program.
package main;

import java.util.*;

// Define a custom city class with three fields: prefecture, position, and year.
class city implements Comparable<city> {
    int prefecture;
    int position;
    int year;

    // Constructor for the city class.
    public city(int prefecture, int position, int year) {
        this.prefecture = prefecture;
        this.position = position;
        this.year = year;
    }

    // Implement the compareTo method to compare two city objects based on their year field.
    @Override
    public int compareTo(city other) {
        return this.year - other.year;
    }
}

// Define a custom cities class as a list of city objects.
class cities extends ArrayList<city> {
    // Implement the sort method to sort the list of city objects based on their year field.
    public void sort() {
        Collections.sort(this);
    }
}

// Define a custom cMap class as a map with an integer key and a list of city objects as the value.
class cMap extends HashMap<Integer, cities> {
    // Implement the put method to add a new city object to the list of city objects associated with a given key.
    @Override
    public cities put(Integer key, cities value) {
        cities old = super.put(key, value);
        if (old!= null) {
            old.addAll(value);
        }
        return old;
    }
}

// s865387202 function is the entry point of the program.
public class s865387202{
    public static void main(String[] args) {
        // Read the number of cities and events from the standard input.
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize an empty cMap named h.
        cMap h = new cMap();

        // Read m pairs of integers x and y from the standard input.
        for (int i = 0; i < m; i++) {
            // Read an integer x from the standard input.
            int x = scanner.nextInt();

            // Read an integer y from the standard input.
            int y = scanner.nextInt();

            // Check if the prefecture x already exists in the cMap.
            cities cities = h.get(x);

            // If the prefecture x does not exist in the cMap, create a new cities object with one city and assign it to the key x in the cMap.
            if (cities == null) {
                cities = new cities();
                cities.add(new city(x, i, y));
                h.put(x, cities);
            } else {
                // If the prefecture x already exists in the cMap, add a new city to the existing cities object.
                cities.add(new city(x, i, y));
            }
        }

        // Initialize a list named results with length m and zeroed elements.
        List<String> results = new ArrayList<>();

        // Iterate through each value v in the cMap.
        for (cities cities : h.values()) {
            // Sort the cities list using the compareTo method.
            cities.sort();

            // Iterate through each city object ci in the sorted cities list.
            for (int idx = 0; idx < cities.size(); idx++) {
                // Format the result string using String.format and assign it to the corresponding index in the results list.
                results.add(String.format("%06d%06d", cities.get(idx).prefecture, idx + 1));
            }
        }

        // Print the final result using String.join and System.out.println.
        System.out.println(String.join("\n", results));
    }
}

// End of code