import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for input
        int i, t, n;

        // Create a Scanner object
        Scanner sc = new Scanner(System.in);

        // Loop to process 4 test cases
        for(i = 0; i < 4; i++) {
            // Read the type (t) and quantity (n) from input
            t = sc.nextInt();
            n = sc.nextInt();

            // Calculate and output the result based on the type (t)
            if(t == 1) {
                // If type is 1, multiply n by 6000
                System.out.println(6000 * n);
            }
            else if(t == 2) {
                // If type is 2, multiply n by 4000
                System.out.println(4000 * n);
            }
            else if(t == 3) {
                // If type is 3, multiply n by 3000
                System.out.println(3000 * n);
            }
            else if(t == 4) {
                // If type is 4, multiply n by 2000
                System.out.println(2000 * n);
            }
        }
    }
}

