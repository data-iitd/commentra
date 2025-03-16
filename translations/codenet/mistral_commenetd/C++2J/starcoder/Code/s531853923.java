
import java.util.*;
public class Main {
    public static void main(String[] args) {
        // Declare four integer variables to store input values
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();

        // Check if the condition is true
        if (a*b%2==1&&(c+d)%2==1)
        {
            // If the condition is true, print "No" to the output stream
            System.out.println("No");
        }
        // If the condition is false, print "Yes" to the output stream
        else
        {
            System.out.println("Yes");
        }
    }
}
