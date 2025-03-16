package main;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		Map<Integer, City[]> h = new HashMap<>();
		for (int i = 0; i < m; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			City[] cities = h.get(x);
			if (cities == null) {
				h.put(x, new City[] { new City(x, y, i) });
			} else {
				City[] newCities = Arrays.copyOf(cities, cities.length + 1);
				newCities[cities.length] = new City(x, y, i);
				h.put(x, newCities);
			}
		}
		for (Map.Entry<Integer, City[]> entry : h.entrySet()) {
			Arrays.sort(entry.getValue());
			for (int i = 0; i < entry.getValue().length; i++) {
				entry.getValue()[i].position = i;
			}
		}
		for (Map.Entry<Integer, City[]> entry : h.entrySet()) {
			for (City city : entry.getValue()) {
				System.out.println(String.format("%06d%06d", city.prefecture, city.position + 1));
			}
		}
	}

}

class City implements Comparable<City> {

	int prefecture;
	int year;
	int position;

	public City(int prefecture, int year, int position) {
		this.prefecture = prefecture;
		this.year = year;
		this.position = position;
	}

	@Override
	public int compareTo(City o) {
		return year - o.year;
	}

}

