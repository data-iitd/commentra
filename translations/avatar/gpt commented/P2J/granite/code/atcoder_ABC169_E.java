
import java.util.Arrays;
import java.util.Scanner;

public class atcoder_ABC169_E{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] low = new int[n];
        int[] high = new int[n];
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            low[i] = a;
            high[i] = b;
        }
        Arrays.sort(low);
        Arrays.sort(high);
        if (n % 2 == 1) {
            int index = (n + 1) / 2 - 1;
            System.out.println(high[index] - low[index] + 1);
        } else {
            int index1 = n / 2 - 1;
            int index2 = n / 2;
            double hh = (high[index1] + high[index2]) / 2.0;
            double ll = (low[index1] + low[index2]) / 2.0;
            System.out.println((int) ((hh - ll) * 2) + 1);
        }
    }
}

