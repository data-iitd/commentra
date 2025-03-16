
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables x and a
        int x, a;

        // Read two integer values from user input and store them in x and a
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();
        a = sc.nextInt();

        // Check if x is greater than or equal to a
        // If true, print 10; otherwise, print 0
        System.out.println((x >= a) * 10);

        // Return 0 to indicate successful completion of the program
        return 0;
    }
}
