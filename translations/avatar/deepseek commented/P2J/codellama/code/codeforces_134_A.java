
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = sc.nextInt();
        }
        int x = 0;
        for (int i = 0; i < n; i++) {
            x += w[i];
        }
        int[] d = new int[n];
        int k = 0;
        for (int i = 0; i < n; i++) {
            if ((x - w[i]) / (n - 1) == w[i]) {
                d[k++] = i + 1;
            }
        }
        System.out.println(k);
        for (int i = 0; i < k; i++) {
            System.out.print(d[i] + " ");
        }
        System.out.println();
    }
}

