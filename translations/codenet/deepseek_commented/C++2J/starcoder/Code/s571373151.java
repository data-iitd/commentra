import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] foods = new int[m];

        for (int i = 0; i < n; i++) {
            int k = sc.nextInt();

            for (int j = 0; j < k; j++) {
                int temp = sc.nextInt();
                foods[temp - 1]++;
            }
        }

        int ans = 0;

        for (int elem : foods) {
            if (elem == n) {
                ans++;
            }
        }

        System.out.println(ans);
    }
}

