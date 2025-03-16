import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] m = new int[n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                m[i][j] = sc.nextInt();
            }
        }
        Arrays.sort(m, (a, b) -> Integer.compare(b[0], a[0]));
        int[] a = m[0];
        for (int[] i : m) {
            if (i[1] > a[1]) {
                System.out.println("Happy Alex");
                break;
            }
            a = i;
        } else {
            System.out.println("Poor Alex");
        }
    }
}
