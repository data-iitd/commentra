import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input values from the user
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Initialize output string
        String ans;

        // Determine the answer based on the input values
        if (a == 1 && b == 1) {
            // Both a and b are equal to 1, so the answer is a draw
            ans = "Draw";
        } else if (a == 1) {
            // a is equal to 1, so the answer is Alice
            ans = "Alice";
        } else {
            // Neither a nor b is equal to 1, so the answer is Bob
            ans = "Bob";
        }

        // Print the answer to the console
        System.out.println(ans);
    }
}

