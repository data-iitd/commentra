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

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // consume the remaining newline

        Map<Integer, List<City>> h = new HashMap<>();

        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            scanner.nextLine(); // consume the remaining newline

            h.putIfAbsent(x, new ArrayList<>());
            h.get(x).add(new City(x, y, i));
        }

        String[] results = new String[m];

        for (List<City> cities : h.values()) {
            cities.sort(Comparator.comparingInt(c -> c.year));
            for (int idx = 0; idx < cities.size(); idx++) {
                City ci = cities.get(idx);
                results[ci.position] = String.format("%06d%06d", ci.prefecture, idx + 1);
            }
        }

        System.out.println(String.join("\n", results));
    }
}

// <END-OF-CODE>
