
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an integer variable 'n' for input and an unsigned long long int'm' for storing the result
        int n;
        long m;

        // Read an integer value from the user and store it in 'n'
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Initialize'm' with the value of 'n'
        m = n;

        // Decrease 'n' by 1 to prepare for the factorial calculation
        n--;

        // Loop to calculate the factorial of 'n' (m = n!)
        for (; n > 1; n--) {
            // Multiply'm' by the current value of 'n'
            m *= n;
        }

        // Print the calculated factorial value stored in'm'
        System.out.println(m);
    }
}

