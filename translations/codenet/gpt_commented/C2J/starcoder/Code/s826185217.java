import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare four integer variables to hold input values
        int a, b, c, d;

        // Read four integers from user input
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt();

        // Compare the sum of the first two integers (a and b) with the sum of the last two integers (c and d)
        if (a + b > c + d) {
            // If the sum of a and b is greater, print "Left"
            System.out.println("Left");
        } else if (a + b < c + d) {
            // If the sum of a and b is less, print "Right"
            System.out.println("Right");
        } else {
            // If both sums are equal, print "Balanced"
            System.out.println("Balanced");
        }
    }
}
