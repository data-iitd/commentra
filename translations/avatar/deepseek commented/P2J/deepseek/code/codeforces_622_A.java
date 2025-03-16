import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int l = 1;
        int r = n;

        while (l < r) {
            int mid = l + (r - l) / 2;
            double idxcnt = mid * (mid + 1) / 2;
            if (idxcnt < n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        l -= 1;
        double idxcnt = l * (l + 1) / 2;

        System.out.println((int)(n - idxcnt));
    }
}

