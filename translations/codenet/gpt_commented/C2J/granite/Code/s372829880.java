
import java.util.Scanner;

public class s372829880{
    public static void main(String[] args) {
        // Declare two integer variables x and a
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int a = scanner.nextInt();

        // Check if x is greater than or equal to a
        // If true, print 10; otherwise, print 0
        System.out.println((x >= a)? 10 : 0);

        // Return 0 to indicate successful completion of the program
        System.out.println(0);
    }
}
