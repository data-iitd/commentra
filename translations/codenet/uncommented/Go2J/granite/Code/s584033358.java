
import java.util.Scanner;

public class s584033358{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.close();

        if (k <= (n + n % 2) / 2) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
