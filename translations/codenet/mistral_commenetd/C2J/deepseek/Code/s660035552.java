import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int cnt = 0;
        int t = 0;
        for (int i = 0; i < m; i++) {
            if (t <= a[i]) {
                t = b[i];
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
