
import java.util.Scanner; // Import the Scanner class

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object
        int m1 = sc.nextInt(); // Read an integer from the standard input
        int d1 = sc.nextInt(); // Read an integer from the standard input
        int m2 = sc.nextInt(); // Read an integer from the standard input
        int d2 = sc.nextInt(); // Read an integer from the standard input
        if (m1 != m2) System.out.println("1"); // Check if the values of m1 and m2 are not equal, if true print 1
        else System.out.println("0"); // If m1 and m2 are equal, print 0
    }
}

