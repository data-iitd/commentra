import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input as two integers n and m
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Check if both n and m are less than 1
        if (n < 1) {
            // If yes, check if m is also less than 1
            if (m < 1) {
                // Print n and m and quit the program
                System.out.println(n + " " + m);
                return;
            }
            // If not, print "Impossible" and quit the program
            System.out.println("Impossible");
            return;
        }

        // Check if m is greater than n
        if (m > n) {
            // If yes, calculate the minimum and maximum values
            int min = m;
            int max = n + m - 1;
            // Print the minimum and maximum values
            System.out.println(min + " " + max);
        } else {
            // If m is less than or equal to n
            int min = n;
            int max = n + m - 1;
            // If m is 0, adjust the maximum value accordingly
            if (m == 0) {
                max = n;
            }
            // Print the minimum and maximum values
            System.out.println(min + " " + max);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
