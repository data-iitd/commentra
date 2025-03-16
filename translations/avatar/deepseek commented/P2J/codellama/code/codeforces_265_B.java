
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt();
        }
        int ans = n - 1;
        int last = 0;
        for (int i = 0; i < n; i++) {
            ans += Math.abs(last - l[i]) + 1;
            last = l[i];
        }
        System.out.println(ans);
    }
}

