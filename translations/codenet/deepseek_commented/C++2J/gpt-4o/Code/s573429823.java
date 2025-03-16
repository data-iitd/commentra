import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a Scanner to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the value of n from the standard input
        long n = scanner.nextLong();
        
        // Initialize a boolean variable to false
        boolean flg = false;
        
        // Check if n is less than 4. If so, print "No" and exit.
        if (n < 4) {
            System.out.println("No");
        } else {
            // Check all possible combinations of 4s and 7s that sum up to n
            for (int i = 0; i <= (n / 4); i++) {
                for (int j = 0; j <= (n / 7); j++) {
                    if ((i * 4 + j * 7) == n) {
                        flg = true;
                        break;
                    }
                }
                if (flg) break;
            }
            
            // Check the value of flg and print "Yes" or "No" accordingly
            if (flg) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
