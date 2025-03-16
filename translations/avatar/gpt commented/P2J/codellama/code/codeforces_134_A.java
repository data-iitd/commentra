
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = in.nextInt();
        }
        int x = 0;
        for (int i = 0; i < n; i++) {
            x += w[i];
        }
        int[] d = new int[n];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if ((x - w[i]) / (n - 1) == w[i]) {
                d[j++] = i + 1;
            }
        }
        System.out.println(j);
        for (int i = 0; i < j; i++) {
            System.out.print(d[i] + " ");
        }
        System.out.println();
    }
}

