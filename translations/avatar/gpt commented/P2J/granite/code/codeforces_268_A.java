
import java.util.Scanner;

public class codeforces_268_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String[][] q = new String[n][];
        int count = 0;

        for (int i = 0; i < n; i++) {
            q[i] = scanner.next().split(" ");
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k == j) {
                    continue;
                }
                if (q[j][0].equals(q[k][q[k].length - 1])) {
                    count++;
                } else {
                    continue;
                }
            }
        }

        System.out.println(count);
    }
}
