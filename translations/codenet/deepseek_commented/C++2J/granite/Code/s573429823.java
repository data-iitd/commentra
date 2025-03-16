
import java.util.Scanner;

public class s573429823{
    public static void main(String[] args) {
        // Declare an unsigned long integer to store the input number
        long n;
        
        // Create a Scanner object to read the input from the standard input
        Scanner scanner = new Scanner(System.in);
        
        // Read the value of n from the standard input
        n = scanner.nextLong();
        
        // Initialize a boolean variable to false
        boolean flg = false;
        
        // Check if n is less than 4. If so, print "No" and exit.
        if(n < 4) {
            System.out.println("No");
        } else {
            // Check all possible combinations of 4s and 7s that sum up to n
            for(int i = 0; i <= (n / 4); i++) {
                for(int j = 0; j <= (n / 7); j++) {
                    if((i * 4 + j * 7) == n) {
                        flg = true;
                        break;
                    }
                }
                if(flg) break;
            }
            
            // Check the value of flg and print "Yes" or "No" accordingly
            if(flg) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
        
        // Close the Scanner object
        scanner.close();
    }
}
