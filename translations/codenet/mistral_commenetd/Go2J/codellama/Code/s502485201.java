
public class Main {
    public static void main(String[] args) {
        // Initialize variables r, d, and x with given values
        int r = 2, d = 3, x = 1;

        // Loop through 10 iterations
        for (int i = 0; i < 10; i++) {
            // Calculate new value of x using given formula
            x = r*x - d;

            // Print the current value of x
            System.out.println(x);
        }
    }
}

