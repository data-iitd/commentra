import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        String input = scanner.next();
        int sa = input.indexOf('-');
        sa = Math.min(n - sa, sa);
        StringBuilder ss = new StringBuilder();

        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            b -= a;
            if (b % 2 == 1 && b <= sa * 2) {
                ss.append("1\n");
            } else {
                ss.append("0\n");
            }
        }
        System.out.println(ss.toString());
    }
}

