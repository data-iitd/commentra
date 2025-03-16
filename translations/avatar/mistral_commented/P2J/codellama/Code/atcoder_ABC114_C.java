
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int ans = 0;

        for (int i = 0; i <= N; i++) {
            if (i % 7 == 0 && i % 5 == 0 && i % 3 == 0) {
                ans++;
            }
        }

        System.out.println(ans);
    }
}

