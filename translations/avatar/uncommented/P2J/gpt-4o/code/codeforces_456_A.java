import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        int[][] m = new int[n][2];

        for (int i = 0; i < n; i++) {
            String[] input = scanner.nextLine().split(" ");
            m[i][0] = Integer.parseInt(input[0]);
            m[i][1] = Integer.parseInt(input[1]);
        }

        Arrays.sort(m, (a, b) -> Integer.compare(b[0], a[0]));

        int[] a = m[0];
        for (int i = 1; i < m.length; i++) {
            if (m[i][1] > a[1]) {
                System.out.println("Happy Alex");
                return;
            }
            a = m[i];
        }
        System.out.println("Poor Alex");
    }
}
// <END-OF-CODE>
