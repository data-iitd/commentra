import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three integer variables to hold input values
        int a, b, c;

        // Read three integers from standard input
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        // Check if the sum of a and b is greater than or equal to c
        if (a + b >= c) {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No"
            System.out.println("No");
        }
    }
}

