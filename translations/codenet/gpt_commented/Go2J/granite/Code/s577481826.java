
import java.util.Scanner;

public class s577481826{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read two integers from input and store them in variables a and b
        int a = sc.nextInt();
        int b = sc.nextInt();

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
