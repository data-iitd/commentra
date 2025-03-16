import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer from the user
        int n = scanner.nextInt();
        
        // Check if n is divisible by 1000
        if (n % 1000 == 0) 
            // If n is divisible by 1000, print 0
            System.out.println(0);
        else 
            // If n is not divisible by 1000, calculate the difference
            // between the next multiple of 1000 and n, and print that difference
            System.out.println((n / 1000 + 1) * 1000 - n);
        
        scanner.close();
    }
}
// <END-OF-CODE>
