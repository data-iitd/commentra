
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] l = new int[10000000000];
        int limit = 10000000000;
        int four = 0;
        int seven = 0;
        int number = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        int ans = 0;
        while (number <= limit) {
            if (number > 0 && four == seven) {
                l[i] = number;
                i++;
            }
            four++;
            number = number * 10 + 4;
            seven++;
            number = number * 10 + 7;
        }
        for (j = 0; j < i; j++) {
            if (l[j] >= n) {
                ans = l[j];
                break;
            }
        }
        System.out.println(ans);
    }
}

