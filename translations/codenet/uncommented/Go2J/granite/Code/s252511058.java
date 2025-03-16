
import java.util.*;

class s252511058 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] x = new int[N];
        int[] l = new int[N];
        int[] r = new int[N];
        for (int i = 0; i < N; i++) {
            x[i] = sc.nextInt();
            l[i] = sc.nextInt();
            r[i] = x[i] + l[i];
        }
        int ans = 1;
        int right = r[0];
        for (int i = 1; i < N; i++) {
            if (l[i] >= right - x[i]) {
                right = r[i];
                ans++;
            }
        }
        System.out.println(ans);
    }
}

