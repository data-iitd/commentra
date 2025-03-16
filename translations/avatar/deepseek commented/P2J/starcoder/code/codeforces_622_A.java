
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int idxcnt = mid * (mid + 1) / 2;
            if (idxcnt < n) l = mid + 1;
            else r = mid;
        }
        l--;
        int idxcnt = l * (l + 1) / 2;
        System.out.println(n - idxcnt);
    }
}

