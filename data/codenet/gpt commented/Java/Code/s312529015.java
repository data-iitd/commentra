import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read two integers A and B from the user
        int A = sc.nextInt();
        int B = sc.nextInt();
        
        // Check if A or B is divisible by 3, or if the sum of A and B is divisible by 3
        if(A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0) {
            // If any of the above conditions are true, print "Possible"
            System.out.println("Possible");
        } else {
            // If none of the conditions are true, print "Impossible"
            System.out.println("Impossible");
        }
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}
