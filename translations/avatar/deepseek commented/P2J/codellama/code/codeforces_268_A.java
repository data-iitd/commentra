
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] q = new String[n];
        int count = 0;

        for (int i = 0; i < n; i++) {
            q[i] = sc.next();
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k == j) {
                    continue;
                }
                if (q[j].charAt(0) == q[k].charAt(q[k].length() - 1)) {
                    count++;
                }
            }
        }

        System.out.println(count);
    }
}

