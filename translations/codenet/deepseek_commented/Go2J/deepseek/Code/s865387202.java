import java.util.*;

class City {
    int prefecture;
    int position;
    int year;

    City(int prefecture, int year, int position) {
        this.prefecture = prefecture;
        this.year = year;
        this.position = position;
    }
}

class Cities extends ArrayList<City> {}

class CMap extends HashMap<Integer, Cities> {}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        CMap h = new CMap();

        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            Cities cities = h.get(x);
            if (cities == null) {
                cities = new Cities();
                h.put(x, cities);
            }
            cities.add(new City(x, y, i));
        }

        String[] results = new String[m];
        for (Map.Entry<Integer, Cities> entry : h.entrySet()) {
            Integer key = entry.getKey();
            Cities cities = entry.getValue();
            Collections.sort(cities, (a, b) -> Integer.compare(a.year, b.year));
            for (int i = 0; i < cities.size(); i++) {
                City city = cities.get(i);
                results[city.position] = String.format("%06d%06d", city.prefecture, i + 1);
            }
        }

        System.out.println(String.join("\n", results));
    }
}
