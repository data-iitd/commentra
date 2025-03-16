
import java.util.Scanner;

public class s206203202{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        int x = N % K;
        int min = Math.min(Math.abs(x - K), x);
        System.out.println(min);
    }
}
// END-OF-CODE