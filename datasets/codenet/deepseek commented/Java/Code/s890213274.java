
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize Scanner to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read three integers from the user input
        int A1 = sc.nextInt();
        int A2 = sc.nextInt();
        int A3 = sc.nextInt();
        
        // Check if the sum of the three integers is greater than or equal to 22
        if ((A1 + A2 + A3) >= 22) {
            // If the condition is true, print "bust"
            System.out.println("bust");
        } else {
            // If the condition is false, print "win"
            System.out.println("win");
        }
    }
}

