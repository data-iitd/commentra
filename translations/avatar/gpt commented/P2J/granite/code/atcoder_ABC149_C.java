
import java.util.Scanner;

public class atcoder_ABC149_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();

        boolean[] prime = new boolean[100010];
        for (int i = 0; i < 100010; i++) {
            prime[i] = true;
        }
        prime[0] = false;
        prime[1] = false;
        for (int i = 4; i < 100010; i += 2) {
            prime[i] = false;
        }
        int i = 3;
        while (i * i <= 100008) {
            if (prime[i]) {
                for (int j = i + i; j < 100008; j += i) {
                    prime[j] = false;
                }
            }
            i += 2;
        }
        for (int j = X; j < 100008; j++) {
            if (prime[j]) {
                System.out.println(j);
                break;
            }
        }
    }
}
