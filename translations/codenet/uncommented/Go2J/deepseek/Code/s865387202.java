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
        Map<Integer, List<City>> h = new HashMap<>();
        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            h.putIfAbsent(x, new ArrayList<>());
            h.get(x).add(new City(x, y, i));
        }

        String[] results = new String[m];

        for (List<City> v : h.values()) {
            Collections.sort(v, new CityComparator());
            for (int idx = 0; idx < v.size(); idx++) {
                City ci = v.get(idx);
                results[ci.position] = String.format("%06d%06d", ci.prefecture, idx + 1);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (String result : results) {
            sb.append(result).append("\n");
        }
        System.out.println(sb.toString().trim());
    }
}
