import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        while (true) {
            int n = sc.nextInt();
            if (n == 0) {
                break;
            }
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            int ans = n;
            for (int i = 0; i < n - 4; i++) {
                int[] count = new int[3];
                for (int j = i; j < i + 4; j++) {
                    if (a[j] - 1 >= 0) {
                        count[a[j] - 1]++;
                    }
                }
                int color = 0;
                for (int j = 0; j < 3; j++) {
                    if (count[j] >= 3) {
                        color = j + 1;
                        break;
                    }
                }
                if (color!= 0) {
                    for (int j = i; j < i + 4; j++) {
                        int buf = a[j];
                        a[j] = color;
                        ans = Math.min(ans, chain(a, n));
                        a[j] = buf;
                    }
                }
            }
            System.out.println(ans);
        }
    }
    
    public static int chain(int[] a, int n) {
        int count = 0;
        while (a[count]!= 0) {
            count++;
        }
        if (count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3]) {
            return 0;
        }
        return count;
    }
}
