
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare two integer variables n and k
        int n, k;

        // Read two integers from user input
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();

        // Check if n is divisible by k
        if (n % k == 0) {
            // If n is divisible by k, print 0
            System.out.println("0");
        } else {
            // If n is not divisible by k, print 1
            System.out.println("1");
        }
    }
}

