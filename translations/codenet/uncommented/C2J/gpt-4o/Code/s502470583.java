import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = a * b;
        int d = 2 * a + 2 * b;
        System.out.println(c + " " + d);
        scanner.close();
    }
}

// <END-OF-CODE>
