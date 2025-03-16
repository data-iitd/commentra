
import java.util.Scanner;

public class s969060017{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        if (b % a == 0) {
            System.out.println(a + b);
        } else {
            System.out.println(b - a);
        }
    }
}
// END-OF-CODE