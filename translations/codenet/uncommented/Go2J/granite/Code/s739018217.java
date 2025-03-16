
import java.util.Scanner;

public class s739018217{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = m * 1900 + (n - m) * 100;
        System.out.println(x * (int) Math.pow(2.0, m));
    }
}
// END-OF-CODE