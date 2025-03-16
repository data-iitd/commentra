
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class s865387202{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[][] cities = new int[m][3];
        for (int i = 0; i < m; i++) {
            cities[i][0] = scanner.nextInt();
            cities[i][1] = scanner.nextInt();
            cities[i][2] = i;
        }
        Arrays.sort(cities, Comparator.comparingInt(a -> a[1]));
        int[][] prefectureCities = new int[n][2];
        for (int i = 0; i < n; i++) {
            prefectureCities[i][0] = i;
            prefectureCities[i][1] = 0;
        }
        for (int i = 0; i < m; i++) {
            prefectureCities[cities[i][0] - 1][1]++;
        }
        for (int i = 1; i < n; i++) {
            prefectureCities[i][1] += prefectureCities[i - 1][1];
        }
        String[] result = new String[m];
        for (int i = 0; i < m; i++) {
            result[cities[i][2]] = String.format("%06d%06d", cities[i][0], prefectureCities[cities[i][0] - 1][1]);
        }
        for (String s : result) {
            System.out.println(s);
        }
    }
}

