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
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (low[i] > low[j]) {
                    int temp = low[i];
                    low[i] = low[j];
                    low[j] = temp;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (high[i] < high[j]) {
                    int temp = high[i];
                    high[i] = high[j];
                    high[j] = temp;
                }
            }
        }
        if (n % 2 == 0) {
            System.out.println(high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
        } else {
            System.out.println((high[(n) / 2 - 1] + high[(n) / 2]) / 2 - (low[(n) / 2 - 1] + low[(n) / 2]) / 2 + 1);
        }
    }
}
