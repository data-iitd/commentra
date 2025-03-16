public class SimpleCalculator {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (true) {
            int a = scanner.nextInt();
            char op = scanner.next().charAt(0);
            int b = scanner.nextInt();
            if (op == '+') {
                System.out.println(a + b);
            } else if (op == '-') {
                System.out.println(a - b);
            } else if (op == '*') {
                System.out.println(a * b);
            } else if (op == '/') {
                System.out.println(a / b);
            } else {
                break;
            }
        }
    }
}
