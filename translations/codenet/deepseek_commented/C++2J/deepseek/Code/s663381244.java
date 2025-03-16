import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.useDelimiter("\\s*");

        List<Integer> m = new ArrayList<>();
        m.add(10);
        m.add(50);
        m.add(100);
        m.add(500);

        boolean first = true;
        while (scanner.hasNextInt()) {
            int money = scanner.nextInt();
            if (money == 0) {
                break;
            }

            if (!first) {
                System.out.println();
            }
            first = false;

            int sum = 0;
            int[] num = new int[4];
            for (int i = 0; i < 4; i++) {
                num[i] = scanner.nextInt();
                sum += num[i] * m.get(i);
            }

            int change = sum - money;
            for (int i = 3; i >= 0; i--) {
                if (change / m.get(i) > 0) {
                    num[i] -= change / m.get(i);
                    change %= m.get(i);
                }
            }

            for (int i = 0; i < 4; i++) {
                if (num[i] > 0) {
                    System.out.println(m.get(i) + " " + num[i]);
                }
            }
        }
    }
}
