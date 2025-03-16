import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables to hold user input
        int x, y;

        // Read two integers from standard input
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();
        y = sc.nextInt();

        // Calculate the sum of x and half of y, then print the result
        System.out.println(x + y/2);
    }
}
