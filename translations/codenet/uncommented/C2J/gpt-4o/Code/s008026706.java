import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int x = 2 * a + 2 * b;
        int y = a * b;
        System.out.println(y + " " + x);
        scanner.close();
    }
}

// <END-OF-CODE>
