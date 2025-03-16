import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] menu = new int[n];
        int[] e = new int[n];
        for (int i = 0; i < n; i++) {
            menu[i] = sc.nextInt();
            e[i] = menu[i] % 10;
            if (e[i] == 0) {
                e[i] = 10;
            }
        }
        Arrays.sort(e);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans += Math.ceil((double)menu[i] / 10) * 10;
        }
        System.out.println(ans + menu[0]);
    }
}
