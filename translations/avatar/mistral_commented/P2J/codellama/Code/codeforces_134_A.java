
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = scan.nextInt();
        }
        int[] d = new int[n];
        int x = 0;
        for (int i = 0; i < n; i++) {
            x += w[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (x - w[i] == w[i] * (n - 1)) {
                d[count++] = i + 1;
            }
        }
        System.out.println(count);
        for (int i = 0; i < count; i++) {
            System.out.print(d[i] + " ");
        }
    }
}

