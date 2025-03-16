
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = scan.nextInt();
        }
        int q = scan.nextInt();
        int[] y = new int[q];
        for (int i = 0; i < q; i++) {
            y[i] = scan.nextInt();
        }
        int sum = 0;
        for (int i = 0; i < q; i++) {
            for (int j = 0; j < n; j++) {
                if (y[i] == x[j]) {
                    sum++;
                    break;
                }
            }
        }
        System.out.println(sum);
    }
}

