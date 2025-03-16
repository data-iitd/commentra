import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long H = scanner.nextLong();
        long W = scanner.nextLong();

        long ans;

        if (H == 1 || W == 1) {
            ans = 1;
        } else {
            long m = H * W;
            if (m % 2 == 0) {
                ans = m / 2;
            } else {
                ans = m / 2 + 1;
            }
        }

        System.out.println(ans);
    }
}

