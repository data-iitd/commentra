import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for h and a
        int h = scanner.nextInt();
        int a = scanner.nextInt();
        
        // Calculate the quotient of h by a
        int sho = h / a;
        
        // Calculate the remainder of the division of h by a
        int am = h % a;
        
        // Check if the remainder is not equal to zero
        if (am != 0) {
            // Increment the value of sho by one
            sho += 1;
        }
        
        // Print the value of sho
        System.out.println(sho);
        
        scanner.close();
    }
}
// <END-OF-CODE>
