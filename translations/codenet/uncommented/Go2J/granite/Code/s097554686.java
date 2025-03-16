
import java.util.Scanner;

public class s097554686{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int t = scanner.nextInt();
        int[] mem = new int[size];
        for (int i = 0; i < n; i++) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            mem[l] += 1;
            mem[r] -= 1;
        }
        int ans = mem[0];
        for (int i = 1; i < t + 1; i++) {
            mem[i] += mem[i - 1];
            if (ans < mem[i]) {
                ans = mem[i];
            }
        }
        System.out.println(ans);
    }
}
