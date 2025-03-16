import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int sa = 0;
        for (int i = 0; i < n; i++) {
            if (sc.next().equals("-")) {
                sa++;
            }
        }
        sa = Math.min(n - sa, sa);
        String[] ss = new String[m];
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            b -= a;
            ss[i] = (b % 2 == 0 && b <= sa * 2) ? "1\n" : "0\n";
        }
        for (String s : ss) {
            System.out.print(s);
        }
    }
}

