
import java.util.Arrays;
import java.util.Scanner;

public class s154250720{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] maps = new int[n];
        int[] num = new int[n];
        for (int i = 0; i < n; i++) {
            maps[i] = scanner.nextInt();
            num[i] = maps[i];
        }
        Arrays.sort(maps);
        int m = n / 2;
        for (int i = 0; i < n; i++) {
            if (num[i] <= maps[m]) {
                System.out.println(maps[m + 1]);
            } else {
                System.out.println(maps[m]);
            }
        }
    }
}
