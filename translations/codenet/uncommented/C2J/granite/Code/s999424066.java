
import java.util.Scanner;

public class s999424066{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        c *= 2;
        if (a + b <= c) {
            System.out.println(a * x + b * y);
        } else {
            if (x <= y) {
                if (b <= c) {
                    System.out.println(c * x + (y - x) * b);
                } else {
                    System.out.println(c * y);
                }
            } else {
                if (a <= c) {
                    System.out.println(c * y + (x - y) * a);
                } else {
                    System.out.println(c * x);
                }
            }
        }
    }
}
//END-OF-CODE