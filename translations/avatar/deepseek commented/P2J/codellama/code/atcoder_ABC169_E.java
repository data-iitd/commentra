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
            int mid = n / 2;
            System.out.println(high[mid] - low[mid] + 1);
        } else {
            int mid = n / 2;
            int hh = (high[mid] + high[mid - 1]) / 2;
            int ll = (low[mid] + low[mid - 1]) / 2;
            System.out.println((hh - ll) * 2 + 1);
        }
    }
}
