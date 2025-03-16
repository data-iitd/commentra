
import java.util.Scanner;

public class s584033358{
    public static void main(String[] args) {
        // Declare two integer variables n and k
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Check if k is less than or equal to half of n (rounded up)
        if (k <= (n + n % 2) / 2) {
            // If the condition is true, print "YES"
            System.out.println("YES");
        } else {
            // If the condition is false, print "NO"
            System.out.println("NO");
        }
    }
}
