import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner object named sc.
        Scanner sc = new Scanner(System.in);

        // Read two integers A and B from the standard input.
        int A = sc.nextInt();
        int B = sc.nextInt();

        // Calculate the maximum value of A+B, A-B, and A*B using the max function.
        int mx = Math.max(A + B, A - B);
        mx = Math.max(mx, A * B);

        // Print the maximum value.
        System.out.println(mx);
        
        // Close the scanner
        sc.close();
    }
}

// <END-OF-CODE>
