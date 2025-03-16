
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables h and r
        int h, r;

        // Read two integers from standard input
        Scanner sc = new Scanner(System.in);
        h = sc.nextInt();
        r = sc.nextInt();

        // Compare the value of r with -h
        if (r > -h) {
            // If r is greater than -h, print "1"
            System.out.println("1");
        }
        else if (r == -h) {
            // If r is equal to -h, print "0"
            System.out.println("0");
        }
        else {
            // If r is less than -h, print "-1"
            System.out.println("-1");
        }
    }
}

