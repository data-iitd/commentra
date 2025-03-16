
import java.util.Scanner;

public class s101529434{
    public static void main(String[] args) {
        // Declare two integer variables K and X
        Scanner scanner = new Scanner(System.in);
        int K = scanner.nextInt();
        int X = scanner.nextInt();
        
        // Check if the product of 500 and K is greater than or equal to X
        if (500 * K >= X) {
            // If true, print "Yes"
            System.out.println("Yes");
        } else {
            // If false, print "No"
            System.out.println("No");
        }
    }
}
