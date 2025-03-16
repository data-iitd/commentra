import java.util.*;

class City {
    int prefecture;
    int position;
    int year;

    City(int prefecture, int year, int position) {
        this.prefecture = prefecture;
        this.position = position;
        this.year = year;
    }
}

class CityComparator implements Comparator<City> {
    public int compare(City c1, City c2) {
        return Integer.compare(c1.year, c2.year);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine();

        Map<Integer, List<City>> cityMap = new HashMap<>();

        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            scanner.nextLine();

            cityMap.putIfAbsent(x, new ArrayList<>());
            cityMap.get(x).add(new City(x, y, i));
        }

        String[] results = new String[m];

        for (Map.Entry<Integer, List<City>> entry : cityMap.entrySet()) {
            List<City> cities = entry.getValue();
            Collections.sort(cities, new CityComparator());

            for (int i = 0; i < cities.size(); i++) {
                City city = cities.get(i);
                results[city.position] = String.format("%06d%06d", city.prefecture, i + 1);
            }
        }

        System.out.println(String.join("\n", results));
    }
}
