
// Importing the java.util.Scanner class for reading input
import java.util.Scanner;

// Function definition: main function takes three arguments N, d, and x
public static void main(String[] args) {
    // Creating a new Scanner object for reading input
    Scanner sc = new Scanner(System.in);

    // Reading input as three integers: N, d, and x
    int N = sc.nextInt();
    int d = sc.nextInt();
    int x = sc.nextInt();

    // Initializing the result variable to 0
    int ret = 0;

    // Loop continues as long as N is greater than 0
    while (N > 0) {
        // Adding the current term to the result
        ret += d + (N - 0.5) * x;

        // Updating the value of d for the next iteration
        d += d / N + (5 * x) / (2 * N);

        // Updating the value of x for the next iteration
        x += 2 * x / N;

        // Decrementing the value of N for the next iteration
        N -= 1;
    }

    // Printing the final result
    System.out.println(ret);
}

// End of code
