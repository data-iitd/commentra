import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextInt()) {
            int[] c = new int[3];
            c[0] = scanner.nextInt();
            c[1] = scanner.nextInt();
            c[2] = scanner.nextInt();

            int sum = c[0] + c[1];
            boolean[] card = new boolean[10];

            for (int i = 0; i < 3; i++) {
                card[c[i] - 1] = true;
            }

            int count = 0;
            for (int i = 0; i < 10; i++) {
                if (!card[i] && sum + i + 1 <= 20) {
                    count++;
                }
            }

            if (count >= 4) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

        scanner.close();
    }
}
