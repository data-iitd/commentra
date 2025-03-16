import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] low = new int[n];
        int[] high = new int[n];
        for (int i = 0; i < n; i++) {
            low[i] = sc.nextInt();
            high[i] = sc.nextInt();
        }
        if (n % 2 == 1) {
            int hh = high[(n + 1) / 2 - 1];
            int ll = low[(n + 1) / 2 - 1];
            System.out.println(hh - ll + 1);
        } else {
            int hh = (high[n / 2 - 1] + high[n / 2]) / 2;
            int ll = (low[n / 2 - 1] + low[n / 2]) / 2;
            System.out.println((hh - ll) * 2 + 1);
        }
    }
}
