
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class s865387202{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        City[] cities = new City[m];
        for (int i = 0; i < m; i++) {
            int prefecture = scanner.nextInt();
            int year = scanner.nextInt();
            cities[i] = new City(prefecture, year, i);
        }
        Arrays.sort(cities, Comparator.comparingInt(City::getYear));
        String[] results = new String[m];
        for (int i = 0; i < m; i++) {
            results[cities[i].getPosition()] = String.format("%06d%06d", cities[i].getPrefecture(), i + 1);
        }
        StringBuilder sb = new StringBuilder();
        for (String result : results) {
            sb.append(result).append("\n");
        }
        System.out.println(sb.toString());
    }
}

class City implements Comparable<City> {
    private int prefecture;
    private int year;
    private int position;

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

    @Override
    public int compareTo(City o) {
        return Integer.compare(this.year, o.year);
    }
}

// End of code