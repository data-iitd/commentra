import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int at = scanner.nextInt();
        int b = scanner.nextInt();
        int bt = scanner.nextInt();
        String[] time1 = scanner.next().split(":");
        String[] time2 = scanner.next().split(":");
        int t1 = Integer.parseInt(time1[0]) * 60 + Integer.parseInt(time1[1]);
        int t2 = Integer.parseInt(time2[0]) * 60 + Integer.parseInt(time2[1]);
        int st = t2 + (t1 - 5) * 60;
        int fin = st + at;
        int now = 0;
        int ans = 0;
        while (now < fin && now < 1140) {
            if (now + bt > st) {
                ans += 1;
            }
            now += b;
        }
        System.out.println(ans);
    }
}

