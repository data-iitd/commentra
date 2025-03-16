import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int x = in.nextInt();
        int[] a = new int[105];
        for(int i = 0; i < m; i++) {
            int temp = in.nextInt();
            a[temp] = 1;
        }
        int ansl = 0, ansr = 0;
        for(int i = x; i <= n; i++) {
            ansr += a[i];
        }
        for(int i = x; i >= 0; i--) {
            ansl += a[i];
        }
        System.out.println(Math.min(ansl, ansr));
    }
}

