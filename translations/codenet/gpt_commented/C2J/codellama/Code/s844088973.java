
public class Main {
    public static void main(String[] args) {
        // Declare two integer variables K and X
        int K, X;

        // Read two integers from standard input: K and X
        Scanner sc = new Scanner(System.in);
        K = sc.nextInt();
        X = sc.nextInt();

        // Loop from (X - K + 1) to (X + K - 1)
        for (int i = X - K + 1; i <= X + K - 1; i++) {
            // Print the current value of i
            System.out.print(i);

            // If i is not the last number, print a space after it
            if (i < X + K - 1)
                System.out.print(" ");
        }

        // Print a newline character after the loop completes
        System.out.println();
    }
}

