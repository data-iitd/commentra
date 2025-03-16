import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read two integers, sum them, and compare the result with a third integer
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        if (a + b >= c) {
            System.out.println("Yes"); // Print "Yes" if the sum is greater than or equal to the third integer
        } else {
            System.out.println("No"); // Print "No" otherwise
        }
    }
}
