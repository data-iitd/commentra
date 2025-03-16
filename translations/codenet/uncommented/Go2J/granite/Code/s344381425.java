
import java.util.Scanner;

public class s344381425{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        if (a < b && b < c) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
