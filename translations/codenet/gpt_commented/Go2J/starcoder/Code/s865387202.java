package main;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		Map<Integer, List<City>> h = new HashMap<>();
		for (int i = 0; i < m; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			List<City> l = h.get(x);
			if (l == null) {
				l = new ArrayList<>();
				l.add(new City(x, y, i));
				h.put(x, l);
			} else {
				l.add(new City(x, y, i));
			}
		}
		List<String> results = new ArrayList<>();
		for (List<City> l : h.values()) {
			l.sort(new CityComparator());
			for (int i = 0; i < l.size(); i++) {
				results.add(String.format("%06d%06d", l.get(i).prefecture, i + 1));
			}
		}
		System.out.println(String.join("\n", results));
	}

}

class City {
	int prefecture;
	int year;
	int position;

	public City(int prefecture, int year, int position) {
		this.prefecture = prefecture;
		this.year = year;
		this.position = position;
	}
}

class CityComparator implements Comparator<City> {

	@Override
	public int compare(City o1, City o2) {
		return o1.year - o2.year;
	}

}

