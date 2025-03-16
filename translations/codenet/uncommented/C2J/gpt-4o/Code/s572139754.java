import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        if (n % 1000 == 0) {
            System.out.println(0);
        } else {
            System.out.println((n / 1000 + 1) * 1000 - n);
        }
        scanner.close();
    }
}
// <END-OF-CODE>
