import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long l = 1;
        long r = n;
        while (l < r) {
            long mid = l + (r - l) / 2;
            long idxcnt = mid * (mid + 1) / 2;
            if (idxcnt < n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        l -= 1;
        long idxcnt = l * (l + 1) / 2;
        System.out.println(n - idxcnt);
    }
}
