import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        if (b <= c) {
            System.out.println("NO");
            return;
        } else {
            int d = a;
            int e = d % b;
            for (int i = 0; i < b; i++) {
                d = d % b;
                if (d == c) {
                    System.out.println("YES");
                    return;
                } else if (i != 0 && d == c) {
                    System.out.println("NO");
                    return;
                }
                d += a;
            }
        }
        System.out.println("NO");
    }
}
// <END-OF-CODE>
