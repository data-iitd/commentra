import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        resolve();
    }

    public static void resolve() {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        int[] low = new int[n];
        int[] high = new int[n];

        for (int i = 0; i < n; i++) {
            String[] input = scanner.nextLine().split(" ");
            low[i] = Integer.parseInt(input[0]);
            high[i] = Integer.parseInt(input[1]);
        }

        Arrays.sort(low);
        Arrays.sort(high);

        if (n % 2 == 1) {
            System.out.println(high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
        } else {
            double hh = (high[n / 2 - 1] + high[n / 2]) / 2.0;
            double ll = (low[n / 2 - 1] + low[n / 2]) / 2.0;
            System.out.println((int) ((hh - ll) * 2) + 1);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
