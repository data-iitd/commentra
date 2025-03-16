
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three integer variables to hold the input values
        int a, b, c;

        // Read three integers from standard input
        Scanner in = new Scanner(System.in);
        a = in.nextInt();
        b = in.nextInt();
        c = in.nextInt();

        // Check if the first number is less than the second, and the second is less than the third
        if (a < b && b < c) 
            System.out.println("Yes");  // If the condition is true, print "Yes"
        else 
            System.out.println("No");   // If the condition is false, print "No"
    }
}
