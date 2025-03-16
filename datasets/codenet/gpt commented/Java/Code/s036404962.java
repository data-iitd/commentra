import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        @SuppressWarnings("resource")
        Scanner scan = new Scanner(System.in);

        // Read two integers from the input: X and t
        int X = scan.nextInt();
        int t = scan.nextInt();
        
        // Check if X is greater than or equal to t
        if (X >= t) {
            // If true, print the result of X minus t
            System.out.println(X - t);
        } 
        // Check if X is less than t
        else if (X < t) {
            // If true, print 0
            System.out.print(0);
        }
    }
}
