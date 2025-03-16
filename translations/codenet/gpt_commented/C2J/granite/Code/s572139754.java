
import java.util.Scanner;

public class s572139754{
    public static void main(String[] args) {
        // Declare an integer variable to hold the input value
        int n;

        // Create a Scanner object to read an integer value from standard input
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        // Check if n is a multiple of 1000
        if(n % 1000 == 0) 
            // If true, print 0 since no additional amount is needed to reach the next multiple of 1000
            System.out.println(0);
        else 
            // If false, calculate and print the difference to the next multiple of 1000
            System.out.println((n / 1000 + 1) * 1000 - n);

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
