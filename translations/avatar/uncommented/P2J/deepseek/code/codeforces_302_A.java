import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        String input = scanner.next();
        int sa = input.indexOf('-');
        sa = Math.min(n - sa, sa);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            b -= a;
            if (b % 2 == 1 && b <= sa * 2) {
                sb.append("1\n");
            } else {
                sb.append("0\n");
            }
        }
        System.out.print(sb.toString());
    }
}
