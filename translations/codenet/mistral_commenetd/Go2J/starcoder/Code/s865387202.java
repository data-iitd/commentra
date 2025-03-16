// Package main contains the entry point of the program.
package main;

import java.util.Scanner;
import java.util.stream.Collectors;

// Define a custom city class with three fields: prefecture, position, and year.
class city {
	int prefecture;
	int position;
	int year;

	// Define a constructor for the city class.
	city(int prefecture, int position, int year) {
		this.prefecture = prefecture;
		this.position = position;
		this.year = year;
	}
}

// Define a custom cities class as a slice of pointers to city structs.
class cities {
	city[] cities;

	// Define a constructor for the cities class.
	cities(city[] cities) {
		this.cities = cities;
	}

	// Define a method for sorting the cities slice using the Less method.
	void sort() {
		Arrays.sort(cities, (city a, city b) -> a.year - b.year);
	}

	// Define a method for formatting the result string using String.format and return it.
	String format(int position) {
		return String.format("%06d%06d", cities[position].prefecture, position + 1);
	}
}

// Define a custom cMap class as a map with an integer key and a cities slice as the value.
class cMap {
	Map<Integer, cities> cMap;

	// Define a constructor for the cMap class.
	cMap(Map<Integer, cities> cMap) {
		this.cMap = cMap;
	}

	// Define a method for sorting the cities slice using the Less method.
	void sort() {
		for (cities v : cMap.values()) {
			v.sort();
		}
	}

	// Define a method for formatting the result string using String.format and return it.
	String format(int position) {
		return String.format("%06d%06d", cMap.keySet().toArray()[position], position + 1);
	}
}

// Main function is the entry point of the program.
public class euler073 {
	// Define a static main method.
	public static void main(String[] args) {
		// Create a new Scanner to read input from stdin.
		Scanner input = new Scanner(System.in);

		// Read the number of cities and events from the standard input.
		int n = input.nextInt();
		int m = input.nextInt();

		// Initialize an empty cMap named h.
		cMap h = new cMap(new HashMap<>());

		// Read m pairs of integers x and y from the standard input.
		for (int i = 0; i < m; i++) {
			// Read an integer x from the standard input.
			int x = input.nextInt();

			// Read an integer y from the standard input.
			int y = input.nextInt();

			// Check if the prefecture x already exists in the cMap.
			boolean exists = h.cMap.containsKey(x);

			// If the prefecture x does not exist in the cMap, create a new cities slice with one element and assign it to the key x in the cMap.
			if (!exists) {
				h.cMap.put(x, new cities(new city[] {new city(x, i, y)}));
			} else {
				// If the prefecture x already exists in the cMap, append a new city struct to the existing cities slice.
				h.cMap.get(x).cities = Arrays.copyOf(h.cMap.get(x).cities, h.cMap.get(x).cities.length + 1);
				h.cMap.get(x).cities[h.cMap.get(x).cities.length - 1] = new city(x, i, y);
			}
		}

		// Initialize a slice named results with length m and zeroed elements.
		String[] results = new String[m];

		// Iterate through each value v in the cMap.
		for (cities v : h.cMap.values()) {
			// Sort the cities slice v using the Less method.
			v.sort();

			// Iterate through each city struct ci in the sorted cities slice v.
			for (int i = 0; i < v.cities.length; i++) {
				// Format the result string using String.format and assign it to the corresponding index in the results slice.
				results[v.cities[i].position] = v.format(i);
			}
		}

		// Print the final result using Stream.of and Collectors.joining.
		System.out.println(Arrays.stream(results).collect(Collectors.joining("\n")));
	}
}

// End of code

