import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers 'n' and 'd' from the standard input
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        
        // Calculate the value of 'a' as 'd' multiplied by 2 and adding 1
        double a = d * 2 + 1;
        
        // Use the Math.ceil function to find the smallest integer greater than or equal to the result of dividing 'n' by 'a'
        // Print the result to the standard output
        System.out.println((int) Math.ceil((double) n / a));
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
