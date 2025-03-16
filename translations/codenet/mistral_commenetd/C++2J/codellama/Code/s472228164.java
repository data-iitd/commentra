import java.util.Scanner; // Import Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a new Scanner object

        int x = sc.nextInt(); // Read input value for x from standard input
        int y = sc.nextInt(); // Read input value for y from standard input

        if(y % 2 == 0) { // Check if y is even
            int t = (int)(0.5*y) - x; // Calculate t as half of y minus x

            if(t >= 0 && (x-t) >= 0) { // Check if t is greater than or equal to zero and if x - t is also greater than or equal to zero
                System.out.println("Yes"); // If both conditions are true, print "Yes" to standard output
            }
            else {
                System.out.println("No"); // If either condition is false, print "No" to standard output
            }
        }
        else {
            System.out.println("No"); // If y is not even, print "No" to standard output
        }
    }
}

