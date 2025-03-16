
import java.util.Scanner;

public class s984400335{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        int min = Math.min(n * a, b);
        System.out.println(min);
    }
}
// END-OF-CODE