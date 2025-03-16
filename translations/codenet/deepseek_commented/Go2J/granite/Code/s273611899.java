
import java.util.Scanner;

public class s273611899{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int n = scanner.nextInt();
            int x = scanner.nextInt();

            if (n == 0 && x == 0) {
                break;
            }

            int c = 0;
            for (int i = 1; i <= n - 2; i++) {
                for (int j = i + 1; j <= n - 1; j++) {
                    for (int k = j + 1; k <= n; k++) {
                        if (i + j + k == x) {
                            c++;
                        }
                    }
                }
            }
            System.out.println(c);
        }
    }
}
