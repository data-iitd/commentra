import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (a[i - 1] < a[i] && a[i] > a[i + 1] || a[i - 1] > a[i] && a[i] < a[i + 1]) {
                ans++;
            }
        }
        System.out.println(ans + 1);
    }
}
