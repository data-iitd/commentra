import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] lis = new int[n];
        for (int i = 0; i < n; i++) {
            lis[i] = sc.nextInt();
        }

        int a = 1;
        int b = lis[n - 1];
        int ans = b;

        while (a <= b) {
            int mid = (a + b) / 2;
            if (check(lis, k, mid)) {
                ans = mid;
                b = mid - 1;
            } else {
                a = mid + 1;
            }
        }

        System.out.println(ans);
    }

    public static boolean check(int[] lis, int k, int mid) {
        for (int i = 0; i < lis.length; i++) {
            if (lis[i] % mid == 0) {
                k++;
            }
            k -= lis[i] / mid;
        }
        return k >= 0;
    }
}

