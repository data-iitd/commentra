
import java.util.Scanner;
import java.util.Arrays;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        Arrays.sort(A);
        int ans = 0;
        for (int i = 1; i < N; i++) {
            ans += A[i] - A[i-1];
        }
        System.out.println(ans);
    }
}

