import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading three integers and checking if their sum is greater than or equal to the third integer
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        if (a + b >= c) {
            System.out.println("Yes"); // Printing "Yes" if the condition is true
        } else {
            System.out.println("No"); // Printing "No" if the condition is false
        }
    }
}
