
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();

        ArrayList<City>[] h = new ArrayList[n];

        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            sc.nextLine();

            if (h[x] == null) {
                h[x] = new ArrayList<City>();
            }

            h[x].add(new City(x, y, i));
        }

        for (int i = 0; i < n; i++) {
            if (h[i] != null) {
                Collections.sort(h[i], new Comparator<City>() {
                    @Override
                    public int compare(City o1, City o2) {
                        return o1.year - o2.year;
                    }
                });

                for (int j = 0; j < h[i].size(); j++) {
                    System.out.println(String.format("%06d%06d", h[i].get(j).prefecture, j + 1));
                }
            }
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

