import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, b, c;
        char op;

        while (true) {
            a = scanner.nextInt();
            op = scanner.next().charAt(0);
            b = scanner.nextInt();

            if (op == '+') {
                c = a + b;
                System.out.println(c);
            } else if (op == '-') {
                c = a - b;
                System.out.println(c);
            } else if (op == '*') {
                c = a * b;
                System.out.println(c);
            } else if (op == '/') {
                c = a / b;
                System.out.println(c);
            } else {
                break;
            }
        }
        scanner.close();
    }
}

// <END-OF-CODE>
