
import java.util.*;

public class s579031873{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int X = sc.nextInt();
        int ans = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            int tmp = sc.nextInt();
            X -= tmp;
            ans++;
            if (tmp < min) min = tmp;
        }
        ans += X / min;
        System.out.println(ans);
    }
}
