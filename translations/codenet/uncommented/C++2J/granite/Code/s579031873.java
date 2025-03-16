
import java.util.*;

public class s579031873{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int X = sc.nextInt();
        int[] a = new int[N];
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
            X -= a[i];
            if (a[i] < min) min = a[i];
        }
        int ans = N + X / min;
        System.out.println(ans);
    }
}

