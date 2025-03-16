import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        int ans = solve(a, b, c);
        System.out.println(ans);
    }

    public static int solve(int a, int b, int c) {
        int temp = 0;
        if (c == a + b) {
            temp = b + c;
        } else if (c - 1 > a + b) {
            temp = b + c - ((c - 1) - (a + b));
        } else {
            temp = b + c;
        }
        return temp;
    }
}
