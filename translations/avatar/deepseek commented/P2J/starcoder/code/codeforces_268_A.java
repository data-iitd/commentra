
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[][] q = new String[n][];
        int count = 0;
        for (int i = 0; i < n; i++) {
            q[i] = sc.next().split(" ");
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j == k) {
                    continue;
                }
                if (q[j][0].equals(q[k][q[k].length - 1])) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}

