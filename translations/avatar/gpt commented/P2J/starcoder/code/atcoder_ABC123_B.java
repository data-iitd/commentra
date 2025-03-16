import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] menu = new int[5];
        for (int i = 0; i < 5; i++) {
            menu[i] = sc.nextInt();
        }
        Arrays.sort(menu, (a, b) -> b[1]);
        int ans = 0;
        for (int i = 1; i < 5; i++) {
            ans += Math.ceil(menu[i] / 10.0) * 10;
        }
        System.out.println(ans + menu[0]);
    }
}

