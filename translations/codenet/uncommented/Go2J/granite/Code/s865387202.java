
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class s865387202{

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        Map<Integer, List<City>> map = new HashMap<>();
        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            map.computeIfAbsent(x, k -> new ArrayList<>()).add(new City(x, y, i));
        }
        scanner.close();

        String[] results = new String[m];
        map.forEach((key, value) -> {
            value.sort(Comparator.comparingInt(City::getYear));
            for (int i = 0; i < value.size(); i++) {
                results[value.get(i).getPosition()] = String.format("%06d%06d", value.get(i).getPrefecture(), i + 1);
            }
        });

        Arrays.stream(results).forEach(System.out::println);
    }

    static class City {
        private final int prefecture;
        private final int year;
        private final int position;

        public City(int prefecture, int year, int position) {
            this.prefecture = prefecture;
            this.year = year;
            this.position = position;
        }

        public int getPrefecture() {
            return prefecture;
        }

        public int getYear() {
            return year;
        }

        public int getPosition() {
            return position;
        }
    }
}

