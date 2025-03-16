import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        Arrays.sort(a);
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
