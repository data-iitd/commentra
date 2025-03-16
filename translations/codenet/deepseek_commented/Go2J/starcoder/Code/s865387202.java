import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		Map<Integer, List<City>> h = new HashMap<>();
		for (int i = 0; i < m; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			if (!h.containsKey(x)) {
				h.put(x, new ArrayList<>());
				h.get(x).add(new City(x, y, i));
			} else {
				h.get(x).add(new City(x, y, i));
			}
		}
		List<String> results = new ArrayList<>();
		for (int x : h.keySet()) {
			Collections.sort(h.get(x));
			for (int i = 0; i < h.get(x).size(); i++) {
				results.add(String.format("%06d%06d", h.get(x).get(i).prefecture, i + 1));
			}
		}
		System.out.println(String.join("\n", results));
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
		return this.year - o.year;
	}
}

