import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = 368;
        int[] m = new int[N];
        int[] f = new int[N];

        int operations = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < operations; i++) {
            String[] operation = scanner.nextLine().split(" ");
            int a = Integer.parseInt(operation[1]);
            int b = Integer.parseInt(operation[2]) + 1;

            if (operation[0].equals("M")) {
                m[a] += 2;
                m[b] -= 2;
            } else {
                f[a] += 2;
                f[b] -= 2;
            }
        }

        int a = 0, b = 0, c = 0;

        for (int i = 0; i < N; i++) {
            a += m[i];
            b += f[i];
            c = Math.max(c, Math.min(a, b));
        }

        System.out.println(c);
    }
}
