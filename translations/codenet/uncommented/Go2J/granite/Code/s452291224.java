
import java.util.Scanner;

public class s452291224{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        if (C - A + B < 0) {
            System.out.println("0");
        } else {
            System.out.printf("%d\n", C - A + B);
        }
    }
}
