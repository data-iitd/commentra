import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a new scanner to read input from standard input
        Scanner sc = new Scanner(System.in);

        // Read two integers from input and convert them from string to int
        int a = Integer.parseInt(sc.next());
        int b = Integer.parseInt(sc.next());

        // Initialize ret with the sum of a and b
        int ret = a + b;

        // Check if ret is less than the difference of a and b
        if (ret < (a - b)) {
            ret = a - b; // Update ret to the difference if it's smaller
        }
        // Check if ret is less than the product of a and b
        if (ret < (a * b)) {
            ret = a * b; // Update ret to the product if it's smaller
        }

        // Print the final result
        System.out.println(ret);
    }
}
