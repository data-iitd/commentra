import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int[] mem = new int[t + 1];
        for (int i = 0; i < n; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
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

