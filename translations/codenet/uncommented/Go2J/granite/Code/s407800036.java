
import java.util.Scanner;

public class s407800036{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Code for A - Between Two Integers
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();

        if (C >= A && C <= B) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
