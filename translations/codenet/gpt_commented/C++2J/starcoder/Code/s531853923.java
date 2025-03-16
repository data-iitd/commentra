
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Declare four integer variables to hold input values
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();

        // Check if the product of a and b is odd and the sum of c and d is odd
        if (a * b % 2 == 1 && (c + d) % 2 == 1)
        {
            // If both conditions are true, output "No"
            System.out.println("No");
        }
        else
        {
            // If either condition is false, output "Yes"
            System.out.println("Yes");
        }
    }
}

