
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            int l = i;
            for (int j = i + 1; j < n; j++) {
                if (p[j] < p[l]) {
                    l = j;
                }
            }
            if (l != i) {
                int m = p[i];
                p[i] = p[l];
                p[l] = m;
            }
        }
        int o = 0;
        for (int i = 0; i < k; i++) {
            o += p[i];
        }
        System.out.println(o);
    }
}

