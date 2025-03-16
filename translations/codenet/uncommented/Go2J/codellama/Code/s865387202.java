
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Map<Integer, List<City>> h = new HashMap<>();
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            List<City> cities = h.get(x);
            if (cities == null) {
                cities = new ArrayList<>();
                cities.add(new City(x, y, i));
                h.put(x, cities);
            } else {
                cities.add(new City(x, y, i));
            }
        }

        List<String> results = new ArrayList<>();

        for (List<City> v : h.values()) {
            Collections.sort(v, new Comparator<City>() {
                @Override
                public int compare(City o1, City o2) {
                    return o1.year - o2.year;
                }
            });
            for (City ci : v) {
                results.add(String.format("%06d%06d", ci.prefecture, v.indexOf(ci) + 1));
            }
        }
        for (String result : results) {
            System.out.println(result);
        }
    }

    static class City {
        int prefecture;
        int year;
        int position;

        public City(int prefecture, int year, int position) {
            this.prefecture = prefecture;
            this.year = year;
            this.position = position;
        }
    }
}

