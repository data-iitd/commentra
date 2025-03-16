
import java.util.Scanner; // Import the Scanner class

public class Main { // Start of the Main class
    public static void main(String[] args) { // Start of the main function
        Scanner sc = new Scanner(System.in); // Create a Scanner object

        int m1 = sc.nextInt(); // Read the first month
        int d1 = sc.nextInt(); // Read the first day
        int m2 = sc.nextInt(); // Read the second month
        int d2 = sc.nextInt(); // Read the second day

        if (m1 != m2) { // Check if the months are equal or not
            System.out.println("1"); // If the months are not equal, print "1" to the standard output
        } else {
            System.out.println("0"); // If the months are equal, print "0" to the standard output
        }
    }
}

