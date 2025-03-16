import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int tmp;
        long min = 1000000, max = -1000000, sum = 0;
        for (int i = 0; i < n; i++) {
            tmp = sc.nextInt();
            if (min > tmp) min = tmp;
            if (max < tmp) max = tmp;
            sum += tmp;
        }
        System.out.println(min + " " + max + " " + sum);
    }
}
