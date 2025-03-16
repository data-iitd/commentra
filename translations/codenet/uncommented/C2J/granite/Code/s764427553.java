
import java.util.Scanner;

public class s764427553{
    public static void main(String[] args) {
        final int MAX_V = 999999;
        int[] prime = new int[MAX_V + 1];
        for (int i = 2; i <= MAX_V; i++) {
            prime[i] = 1;
        }
        for (int i = 2; i * i <= MAX_V; i++) {
            if (prime[i] == 1) {
                for (int k = 2 * i; k <= MAX_V; k += i) {
                    prime[k] = 0;
                }
            }
        }
        prime[0] = 0;
        prime[1] = 0;
        Scanner sc = new Scanner(System.in);
        int count = 0;
        while (sc.hasNextInt()) {
            count++;
            int n = sc.nextInt();
            int cnt = 0;
            for (int i = n; i > 0; i--) {
                if (prime[i] == 1) {
                    cnt++;
                }
            }
            System.out.println(cnt);
            if (count == 30) {
                break;
            }
        }
    }
}

