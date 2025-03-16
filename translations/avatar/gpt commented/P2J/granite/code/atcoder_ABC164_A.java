
import java.util.Scanner;

public class atcoder_ABC164_A{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from input: S (the strength) and W (the weight)
        int S = scanner.nextInt();
        int W = scanner.nextInt();
        
        // Check if the strength S is less than or equal to the weight W
        // If it is, print "unsafe"; otherwise, print "safe"
        if (S <= W) {
            System.out.println("unsafe");
        } else {
            System.out.println("safe");
        }
        
        // Close the Scanner object to release system resources
        scanner.close();
    }
}

