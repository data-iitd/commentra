
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int i = 0, ans = 0, count = 0;
        while (i < N - 1) {
            if (A[i] == A[i + 1]) {
                count++;
                if (count % 2 != 0) {
                    ans++;
                }
            } else {
                count = 0;
            }
            i++;
        }
        System.out.println(ans);
    }
}

